#include <stdio.h>
#include <stdlib.h>

char player_name_1[50];
char player_name_2[50];

int hp[3] = {0, 50, 50};
int energy[3];
int mode[3];
int power[3];

int main()
{
	int player = 1;

	printf("Battle!\n");

	printf("�÷��̾� 1�� �̸��� �Է��ϼ��� : ");
    gets(player_name_1);

	while(1){
        printf("�÷��̾� 2�� �̸��� �Է��ϼ��� : ");
        gets(player_name_2);
        if(strcmp(player_name_1, player_name_2) == 0){
            printf("�� �÷��̾��� �̸��� �����ϴ�.\n");
            Sleep(1000);
        } else {
            break;
        }
    }

		Sleep(1000);

	while(1){
		system("cls");
		printf("%s, ������ ���� �����ϼ���. ���� �������� %d�Դϴ�.\n", player_name_1, energy[player]);
		Sleep(1000);
		while(1){
			printf("1. ������ ������   2. �����ϱ�   3. ����ϱ�\n");
			scanf("%d", &mode[player]);
			if(mode[player] < 1 || mode[player] > 3){
				printf("�ùٸ� ��带 �Է��ϼ���!\n");
			} else {
				break;
			}
		}
		if(mode[player] == 1){
			system("cls");
			printf("===========������ ������==========\n");
			Sleep(1000);

			energy[1]++;
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
            printf("���ݷ��� %d�� �����߽��ϴ�. ���� ������: %d\n",
				power[player], energy[player]);
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
            printf("������ %d�� �����߽��ϴ�. ���� ������: %d\n",
				power[player], energy[player]);
            Sleep(1000);
        }

        if(player == 1){
			player = 2;
        } else if (player == 2){
			player = 1;
			battle();
        }
	}
	return 0;
}

