#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <time.h>

char player_name_1[50];
char player_name_2[50];

int energy[3];
int mode[3];
int power[3];
int hp[3]={0, 100, 100};

int battle()
{
    system("cls");
    printf("��Ʋ ����!\n");
    Sleep(1000);
    if(mode[1] == 1){//player 1 ������ ������
        if(mode[2] == 1){
            printf("�� �÷��̾� ��� �������� �����߽��ϴ�.\n");
            Sleep(1000);
        } else if (mode[2] == 2){
            printf("%s�� %s�� ���ݷ� %d���� �����߽��ϴ�!\n", player_name_2, player_name_1, power[2]);
            Sleep(500);
            hp[1] -= power[2];
            printf("%s�� �������� �����ϴ��� ������� ���߽��ϴ�...\n", player_name_1);
            Sleep(500);
            printf("%s�� �������� %d �޾ҽ��ϴ�.\n", player_name_1, power[2]);
            Sleep(1000);
        } else if (mode[2] == 3){
            printf("%s�� �������� �����߽��ϴ�.\n", player_name_1);
            Sleep(500);
            printf("%s�� ����߽��ϴ�.\n", player_name_2);
            Sleep(500);
            printf("�ƹ��� �������� ���� �ʾҽ��ϴ�.\n");
            Sleep(1000);
        }
    } else if(mode[1] == 2){//player 1 ����
        if(mode[2] == 1){
            printf("%s�� %s�� ���ݷ� %d���� �����߽��ϴ�!\n", player_name_1, player_name_2, power[1]);
            Sleep(500);
            hp[2] -= power[1];
            printf("%s�� �������� �����ϴ��� ������� ���߽��ϴ�...\n", player_name_2);
            Sleep(500);
            printf("%s�� �������� %d �޾ҽ��ϴ�.\n", player_name_2, power[1]);
            Sleep(1000);
        } else if (mode[2] == 2){
            printf("%s�� %s�� ���ݷ� %d���� �����߽��ϴ�!\n", player_name_1, player_name_2, power[1]);
            Sleep(500);
            hp[2] -= power[1];

            printf("%s�� %s�� ���ݷ� %d���� �����߽��ϴ�!\n", player_name_2, player_name_1, power[2]);
            Sleep(500);
            hp[1] -= power[2];

            printf("%s�� �������� %d �޾ҽ��ϴ�.\n", player_name_1, power[2]);
            Sleep(500);

            printf("%s�� �������� %d �޾ҽ��ϴ�.\n", player_name_2, power[1]);
            Sleep(1000);
        } else if (mode[2] == 3){
            printf("%s�� %s�� ���ݷ� %d���� �����߽��ϴ�!\n", player_name_1, player_name_2, power[1]);
            Sleep(500);
            printf("%s�� ���� %d���� ����߽��ϴ�!\n", player_name_2, power[2]);
            Sleep(500);
            if(power[2] >= power[1]){
                printf("%s�� �������� ���� �ʾҽ��ϴ�.\n", player_name_2);
            } else {
                printf("%s�� �������� %d �Ծ����ϴ�.\n", player_name_2, power[1]-power[2]);
                hp[2] -= (power[1]-power[2]);
            }
            Sleep(1000);
        }
    } else if(mode[1] == 3){//player 1 ���
        if(mode[2] == 1){
            printf("%s�� �������� �����߽��ϴ�.\n", player_name_2);
            Sleep(500);
            printf("%s�� ����߽��ϴ�.\n", player_name_1);
            Sleep(500);
            printf("�ƹ��� �������� ���� �ʾҽ��ϴ�.\n");
            Sleep(1000);
        } else if (mode[2] == 2){
            printf("%s�� %s�� ���ݷ� %d���� �����߽��ϴ�!\n", player_name_2, player_name_1, power[2]);
            Sleep(500);
            printf("%s�� ���� %d���� ����߽��ϴ�!\n", player_name_1, power[1]);
            Sleep(500);
            if(power[1] >= power[2]){
                printf("%s�� �������� ���� �ʾҽ��ϴ�.\n", player_name_1);
            } else {
                printf("%s�� �������� %d �Ծ����ϴ�.\n", player_name_1, power[2]-power[1]);
                hp[1] -= (power[2]-power[1]);
            }
            Sleep(1000);
        } else if (mode[2] == 3){
            printf("%s�� ����߽��ϴ�.\n", player_name_1);
            Sleep(500);
            printf("%s�� ����߽��ϴ�.\n", player_name_2);
            Sleep(500);
            printf("�ƹ��� �������� ���� �ʾҽ��ϴ�.\n");
            Sleep(1000);
        }
    }

    if(hp[1] <= 0 && hp[2] > 0){
        printf("%s(��)�� �¸��߽��ϴ�!\n", player_name_2);
        Sleep(4000);
        return 1;
    } else if (hp[2] <= 0 && hp[1] > 0){
        printf("%s(��)�� �¸��߽��ϴ�!\n", player_name_1);
        Sleep(4000);
        return 1;
    } else if (hp[2] <= 0 && hp[1] <= 0) {
        printf("���º��Դϴ�.\n");
        Sleep(4000);
        return 1;
    }

    printf("%s�� ���� ü�� : %d\n", player_name_1, hp[1]);
    printf("%s�� ���� ü�� : %d\n", player_name_2, hp[2]);
    Sleep(1000);
    return 0;
}

int main()
{
    srand(time(0));

    int player = 1;
    printf("Battle!\n");

    printf("�÷��̾� 1�� �̸��� �Է��ϼ��� : ");
    gets(player_name_1);

    while(1){
        printf("�÷��̾� 2�� �̸��� �Է��ϼ��� : ");
        gets(player_name_2);
        if(strcmp(player_name_1, player_name_2) == 0){
            printf("�� �÷��̾��� �̸��� �����ϴ�.\n");
        } else {
            break;
        }
    }
    Sleep(1000);

    while(1){
        system("cls");
        if(player == 1){
            printf("%s, ������ ���� �����ϼ���. ���� �������� %d�Դϴ�.\n", player_name_1, energy[player]);
        } else if (player == 2){
            printf("%s, ������ ���� �����ϼ���. ���� �������� %d�Դϴ�.\n", player_name_2, energy[player]);
        }
        printf("1. ������ ������   2. �����ϱ�   3. ����ϱ�\n");
        scanf("%d", &mode[player]);
        if(mode[player] == 1){//������ ������
            system("cls");
            printf("============������ ������============\n");
            Sleep(1000);

            int r = rand()%100;
            if(r>=0 && r<=2){
                energy[player] += 10;
            } else if (r >= 3 && r<=6){
                energy[player] += 1;
            } else {
                energy[player] += 3;
            }

            energy[player] += rand()%20;

            printf("�������� �����Ǿ����ϴ�. ���� �������� %d�Դϴ�.\n", energy[player]);
            Sleep(1000);
        } else if (mode[player] == 2){
            if(energy[player] == 0){
                printf("�������� 0�̾ ������ �� �����ϴ�.\n");
                Sleep(1000);
                continue;
            }
            while(1){
                system("cls");
                printf("===========���� ���===========\n");
                printf("���ݷ��� �����ϼ���. ���� ������ : %d\n", energy[player]);
                scanf("%d", &power[player]);
                if(power[player] > energy[player]){
                    printf("�������� �����մϴ�!\n");
                    Sleep(1000);
                    continue;
                } else {
                    break;
                }
            }
            energy[player] -= power[player];
            printf("���ݷ��� %d�� �����߽��ϴ�. ���� ������: %d\n", power[player], energy[player]);
            Sleep(1000);
        } else if (mode[player] == 3){
            if(energy[player] == 0){
                printf("�������� 0�̾ ����� �� �����ϴ�.\n");
                Sleep(1000);
                continue;
            }
            while(1){
                system("cls");
                printf("===========��� ���===========\n");
                printf("������ �����ϼ���. ���� ������ : %d\n", energy[player]);
                scanf("%d", &power[player]);
                if(power[player] > energy[player]){
                    printf("�������� �����մϴ�!\n");
                    Sleep(1000);
                    continue;
                } else {
                    break;
                }
            }
            energy[player] -= power[player];
            printf("������ %d�� �����߽��ϴ�. ���� ������: %d\n", power[player], energy[player]);
            Sleep(1000);
        }
        if(player == 1){
            player = 2;
        } else if (player == 2){
            player = 1;
            if (battle() == 1){
                printf("������ �������ϴ�.\n");
                return 0;
            }
        }
    }
    return 0;
}
