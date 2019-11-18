#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define PAUSE 112
#define ESC 27

#define MAP_X 30
#define MAP_Y 20

void show_title(void); //���� ����ȭ��
void draw_map(void); // ������ �׵θ��� �׸�
int move(int dir); //��Ӹ��� �̵�
void pause(void); //�Ͻ� ����
void game_over(void); //���� ������ Ȯ��
void make_food(void); // ���� ����
void game(void);
void show_score(void);

int x[100], y[100]; //���� ��ǥ��, �ִ� 100��
int food_x, food_y; //food�� ��ǥ��
int length; //�� ����
int speed; //���� �ӵ�
int score; //����  --reset�Լ��� ���� �ʱ�ȭ��
int best_score = 0; //�ְ� ���� --reset�Լ��� ���� �ʱ�ȭ ���� ����
int dir; //���� �̵� ����
int key; //�Է¹��� Ű

void gotoxy(int x, int y, char* s) { //x���� 2x�� ����, ��ǥ���� �ٷ� ���ڿ��� �Է��� �� �ֵ��� printf�Լ� ����
    COORD pos = {2 * x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    printf("%s", s);
}

int main() {
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.bVisible = 0;
    cursorInfo.dwSize = 1;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo); //delete cursor
    srand(time(NULL));

    while(1){
        show_title();
        game();
        game_over();
    }
}

void game()
{
    int is_game_over = 0;
    while (1) {
        if (kbhit()){
            key = getch();
            if(key == 224)
                key = getch();
        }
        Sleep(speed);

        switch (key) { //�Է¹��� Ű�� ���� ������ �з�
        case LEFT:
        case RIGHT:
        case UP:
        case DOWN:
            if ((dir == LEFT && key != RIGHT) || (dir == RIGHT && key != LEFT) ||
                (dir == UP && key != DOWN) ||(dir == DOWN && key != UP)) //180�� ȸ���� ����
                dir = key;
            key = 0; //Ű �� reset
            break;
        case ESC:
            exit(0);
        }
        is_game_over = move(dir);
        show_score();
        if(is_game_over == 1)
            break;
    }
}

void show_title(void) {
    while (kbhit())
        getch(); //���ۿ� �ִ� Ű���� ����

    system("cls");
    draw_map();    //�� �׵θ��� �׸�

    gotoxy(MAP_X / 2 - 7, 5, "+--------------------------+");
    gotoxy(MAP_X / 2 - 7, 6, "|   S N A K E    G A M E   |");
    gotoxy(MAP_X / 2 - 7, 7, "+--------------------------+");

    gotoxy(MAP_X / 2 - 7, 13, "   �� ��,��,��,�� : Move    ");
    gotoxy(MAP_X / 2 - 7, 14, "   �� P : Pause             ");
    gotoxy(MAP_X / 2 - 7, 15, "   �� ESC : Quit              ");

    while (1) {
        if (kbhit()) {
            key = getch();
            if (key == ESC)
                exit(0); // ESCŰ�� ����
            else
                break; //���� ȭ������ �Ѿ��
        }
        gotoxy(MAP_X / 2 - 7, 10, " < PRESS ANY KEY TO START > ");
        Sleep(400);
        gotoxy(MAP_X / 2 - 7, 10, "                            ");
        Sleep(400);
    }

    system("cls"); //ȭ���� ����
    draw_map(); //�� �׵θ��� �׸�
    while (kbhit())
        getch(); //flush buffer

    dir = LEFT; // ���� �ʱ�ȭ
    speed = 100; // �ӵ� �ʱ�ȭ
    length = 5; //�� ���� �ʱ�ȭ
    score = 0; //���� �ʱ�ȭ
    int i;
    for (i = 0; i < length; i++) { //�� ���밪 �Է�
        x[i] = MAP_X / 2 + i;
        y[i] = MAP_Y / 2;
        gotoxy(x[i], y[i], "��");
    }
    gotoxy(x[0], y[0], "��"); //�� �Ӹ� ���
    make_food(); // food ����
}

void game_over(void) { //�������� �Լ�
    gotoxy(MAP_X / 2 - 6, 5, "+----------------------+");
    gotoxy(MAP_X / 2 - 6, 6, "|      GAME OVER..     |");
    gotoxy(MAP_X / 2 - 6, 7, "+----------------------+");
    gotoxy(MAP_X / 2 - 6, 9, "     YOUR SCORE : ");
    printf("%d", score);

    gotoxy(MAP_X / 2 - 7, 12, " Press any key to restart.. ");

    if (score > best_score) {
        best_score = score;
        gotoxy(MAP_X / 2 - 4, 10, "�� BEST SCORE ��");
    }
    Sleep(500);
    getch();
}

void draw_map(void) { //�� �׵θ� �׸��� �Լ�
    int i;
    for (i = 0; i < MAP_X; i++) {
        gotoxy(i, 0, "��");
    }
    for (i = 1; i < MAP_Y - 1; i++) {
        gotoxy(0, i, "��");
        gotoxy(MAP_X - 1, i, "��");
    }
    for (i = 0; i < MAP_X; i++) {
        gotoxy(i, MAP_Y - 1, "��");
    }
}


/*
int move(int dir)
���� ������ �����̰�, ������ ������ ���� ���̸� �ø���, �ڱ� �ڽ�, Ȥ�� ���� �浹�� ���
1�� return�ϰ�, �׷��� ���� ��� 0�� return�Ѵ�.
*/
int move(int dir) {
    int i;

    if (x[0] == 0 || x[0] == MAP_X - 1 || y[0] == 0 || y[0] == MAP_Y - 1) { //���� �浹���� ���
        return 1;
    }
    for (i = 1; i < length; i++) { //�ڱ� ���� �浹�ߴ°�?
        if (x[0] == x[i] && y[0] == y[i]) {
            return 1;
        }
    }

    if (x[0] == food_x && y[0] == food_y) { //food�� �浹���� ���
        score += 10; //���� ����
        make_food(); //���ο� food �߰�
        length++; //��������
        x[length - 1] = x[length - 2]; //���θ��� ���뿡 �� �Է�
        y[length - 1] = y[length - 2];
    } else {
        gotoxy(x[length - 1], y[length - 1], "  "); //���� �������� ����
    }

    for (i = length - 1; i > 0; i--) { //������ǥ�� ��ĭ�� �ű�
        x[i] = x[i - 1];
        y[i] = y[i - 1];
    }
    gotoxy(x[0], y[0], "��"); //�Ӹ��� �ִ����� �������� ��ħ
    if (dir == LEFT) --x[0]; //���⿡ ���� ���ο� �Ӹ���ǥ(x[0],y[0])���� ����
    if (dir == RIGHT) ++x[0];
    if (dir == UP) --y[0];
    if (dir == DOWN) ++y[0];
    gotoxy(x[i], y[i], "��"); //���ο� �Ӹ���ǥ���� �Ӹ��� �׸�


    return 0;
}

void pause(void) { //�Ͻ� ����
    while (1) {
        if (key == PAUSE) {
            gotoxy(MAP_X / 2 - 9, 0, "< PAUSE : PRESS ANY KEY TO RESUME > ");
            Sleep(400);
            gotoxy(MAP_X / 2 - 9, 0, "                                    ");
            Sleep(400);
        }
        else {
            draw_map();
            return;
        }
        if (kbhit()) {
            key = getch();
            if(key == 224){
                key = getch();
            }
        }
    }
}

void make_food(void) {
    int i;
    while (1) {
        food_x = (rand() % (MAP_X - 2)) + 1;
        food_y = (rand() % (MAP_Y - 2)) + 1;

        for (i = 0; i < length; i++) //food�� �� ����� ��ġ���� Ȯ��
            if (food_x == x[i] && food_y == y[i])
                break;

        if (i != length)
            continue; //������ ��� while���� �ٽ� ����

        gotoxy(food_x, food_y, "��"); //�Ȱ����� ��� ��ǥ���� food�� ���
        speed -= 3; //�ӵ� ����
        break;
    }
}

void show_score()
{
    gotoxy(5, MAP_Y, " YOUR SCORE: "); //����ǥ��
    printf("%3d, BEST SCORE: %3d", score, best_score);
}
