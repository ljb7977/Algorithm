#include <windows.h>


#define MAP_X 30
#define MAP_Y 20

int main()
{
    draw_map();
    return 0;
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

void gotoxy(int x, int y, char* s) { //x���� 2x�� ����, ��ǥ���� �ٷ� ���ڿ��� �Է��� �� �ֵ��� printf�Լ� ����
    COORD pos = {2 * x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    printf("%s", s);
}
