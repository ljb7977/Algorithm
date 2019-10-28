#include <stdio.h>
#include <stdlib.h>

typedef struct student
{
    char name[10];
    int age;
    int gender;
    int year;
    int class;
    float score;
    int valid;
} Student;

Student s[100];

void printStudent(int i)
{
    printf("----�л� ����----\n");
    printf("�⼮��ȣ %d��\n", i);
    printf("�̸�: %s\n", s[i].name);
    printf("����: %d\n", s[i].age);
    if(s[i].gender == 1)
    {
        printf("����: ����\n");
    }
    else
    {
        printf("����: ����\n");
    }
    printf("%d�г� %d��\n", s[i].year, s[i].class);
    printf("����: %.2f\n", s[i].score);
    printf("-----------------\n");
}

void modifyStudent()
{
    int num, mode;
    printf("������ �л� ��ȣ�� �Է��ϼ���\n");
    scanf("%d", &num);
    if(s[num].valid == 0)
    {
        printf("�������� �ʴ� �л��Դϴ�.\n");
        return;
    }
    printStudent(num);
    printf("������ �׸��� ������\n");
    printf("1:�̸�  2:����  3:����  4:�г�  5:��  6:����\n");
    scanf("%d", &mode);
    if(mode == 1) {
        printf("������ �̸��� �Է��ϼ���\n");
        scanf("%s", s[num].name);
    }
    else if (mode == 2) {
        printf("������ ���̸� �Է��ϼ���\n");
        scanf("%d", &s[num].age);
    }
    else if (mode == 3) {
        printf("������ ������ �Է��ϼ���. ���ڴ� 1, ���ڴ� 2\n");
        scanf("%d", &s[num].gender);
    }
    else if (mode == 4) {
        printf("������ �г��� �Է��ϼ���.\n");
        scanf("%d", &s[num].year);
    }
    else if (mode == 5) {
        printf("������ ���� �Է��ϼ���.\n");
        scanf("%d", &s[num].class);
    }
    else if (mode == 6) {
        printf("������ ������ �Է��ϼ���.\n");
        scanf("%f", &s[num].score);
    }
    else {
        printf("�߸��� ����Դϴ�.\n");
        return;
    }
    printf("������ �����Դϴ�.\n");
    printStudent(num);
}

int main()
{
    char command;
    int i;
    int num;
    int mode, temp;
    printf("�л� ���� �ý���\n");
    while(1){
        printf("Ŀ�ǵ带 �Է��ϼ���.\n");
        printf("q: ����  i: �߰�  d: ����  m: ����\n");
        printf("a: ��ü ���  p: �� �л� ���\n");
        scanf("%c", &command);
        switch(command) {
        case 'q':
            printf("���α׷��� �����մϴ�.\n");
            return 0;
        case 'i':
            printf("�Է��� �л� ��ȣ�� �Է��ϼ���\n");
            scanf("%d", &num);
            if(s[num].valid == 1){
                printf("�̹� ��ϵ� �л��Դϴ�.\n");
                break;
            }
            printf("%d�� �л�\n", num);
            printf("�̸��� �Է��ϼ���: ");
            scanf("%s", s[num].name);
            printf("���̸� �Է��ϼ���: ");
            scanf("%d", &s[num].age);
            printf("������ �Է��ϼ���. ���ڴ� 1, ���ڴ� 2: ");
            scanf("%d", &s[num].gender);
            printf("�г��� �Է��ϼ���: ");
            scanf("%d", &s[num].year);
            printf("���� �Է��ϼ���: ");
            scanf("%d", &s[num].class);
            printf("������ �Է��ϼ���: ");
            scanf("%f", &s[num].score);

            s[num].valid = 1;
            printf("�л��� ��ϵǾ����ϴ�.\n");
            printStudent(num);
            break;
        case 'd':
            printf("������ �л� ��ȣ�� �Է��ϼ���.\n");
            scanf("%d", &num);
            if(s[num].valid == 0){
                printf("�������� �ʴ� �л��Դϴ�.\n");
                break;
            }
            printStudent(num);
            s[num].valid = 0;
            printf("�л��� �����߽��ϴ�.\n");
            break;
        case 'm':
            modifyStudent();
            break;
        case 'a':
            printf("��ü �л� ������ ����մϴ�.\n");
            for(i = 0; i<100; i++)
                if(s[i].valid == 1)
                    printStudent(i);
            break;
        case 'p':
            printf("����� �л� ��ȣ�� �Է��ϼ���\n");
            scanf("%d", &num);
            if(s[num].valid == 0){
                printf("�������� �ʴ� �л��Դϴ�.\n");
                break;
            }
            printStudent(num);
            break;
        default:
            printf("�߸��� Ŀ�ǵ��Դϴ�.\n");
        }
        getchar();
    }
    return 0;
}
