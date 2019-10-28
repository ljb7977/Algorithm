#include <stdio.h>
#include <stdlib.h>

int main()
{
    int score[100] = {0,};
    int used[100] = {0,};
    int mode, i;
    int student, temp;
    int num;
    double sum;

    while(1){
        printf("���� ���� ���α׷��Դϴ�. ��带 �������ּ���.\n");
        printf("1. �Է� �� ����  2. ��ü ���  3. ���  4. �ְ���  5. ������  6. ����\n");
        scanf("%d", &mode);
        switch(mode){
        case 1:
            printf("�Է��� �л� ��ȣ�� ������ �Է��ϼ���\n");
            scanf("%d %d", &student, &temp);
            score[student] = temp;
            used[student] = 1;
            break;
        case 2:
            printf("��ü �л� ������ ����մϴ�.\n");
            for(i = 0; i<100; i++){
                if(used[i]){
                    printf("%d : %d\n", i, score[i]);
                }
            }
            break;
        case 3:
            printf("��� ������ ����մϴ�.\n");
            sum = 0;
            num = 0;
            for(i = 0; i<100; i++){
                if(used[i]){
                    sum += score[i];
                    num++;
                }
            }
            printf("%.2f\n", sum/num);
            break;
        case 4:
            printf("�ְ� ������ ����մϴ�.\n");
            temp = 0;
            for(i = 1; i<100; i++){
                if(used[i]){
                    if(score[i] > score[temp]){
                        temp = i;
                    }
                }
            }
            printf("%d�� %d��\n", temp, score[temp]);
            break;
        case 5:
            printf("���� ������ ����մϴ�.\n");
            temp = 0;
            for(i = 1; i<100; i++){
                if(used[i]){
                    if(score[i] < score[temp]){
                        temp = i;
                    }
                }
            }
            printf("%d�� %d��\n", temp, score[temp]);
            break;
        case 6:
            printf("���α׷��� �����մϴ�.\n");
            return 0;
        }
    }

    return 0;
}
