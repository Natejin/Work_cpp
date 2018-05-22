//���� ���� ���α׷� - �л� ��ȣ ������ �迭�� ����
//���� ������ �л� ����ü �迭�� ����
//�ִ� �л� ���� ����
//�Է� ������ ���� ���� ó�� ����
#include "Grade_Control.h"



const char *stitles[MAX_SUBJECT] = { "����","����","����" };

Student stues[MAX_STUDENT];

void Control_Grade()
{

	Initialize();//�л� ������ �ʱ�ȭ
	Run();

}


void Initialize()
{
	int i = 0;
	int s = 0;

	for (i = 0; i<MAX_STUDENT; i++)
	{
		for (s = 0; s<MAX_SUBJECT; s++)
		{
			stues[i].scores[s] = -1; //������ -1�� ����
		}
	}
}


void Run()	//����
{
	int key = 0;
	while ((key = SelectMenu()) != 0)//������ �޴��� 0�� �ƴϸ� �ݺ�
	{
		switch (key)//������ Ű�� ���� ��� ����
		{
		case 1: AddStudent(); break;
		case 2: RemoveStudent(); break;
		case 3: FindStudent(); break;
		case 4: ListStudent(); break;
		default: printf("�߸� �����Ͽ����ϴ�.\n"); break;
		}
	}
	printf("���α׷� ����\n");
}

int SelectMenu() //�޴� ��� �� ����
{
	int key = 0;
	printf("���� ���� ���α׷� 0:����\n");
	printf("1: �л� ������ �Է� 2: �л� ������ ���� 3: �л� �˻� 4: ��� ���� \n");
	scanf_s("%d", &key);
	return key;
}


void AddStudent()	//�л� ������ �Է�
{
	int num = 0;
	Student *stu = 0;
	int s = 0;

	printf("�߰��� �л� ��ȣ(1~%d): ", MAX_STUDENT);
	scanf_s("%d", &num);

	if (IsAvailNum(num) == 0)//��ȿ�� ��ȣ�� �ƴ� ��
	{
		printf("������ ��� �л� ��ȣ�Դϴ�.\n");
		return;
	}

	if (stues[num - 1].num)//�̹� ��ȣ�� ������ ������ ��
	{
		printf("�̹� �߰��Ͽ����ϴ�\n");
		return;
	}

	//stues���� 1�� �л� �����͸� �����ϴ� �޸� �ּ�
	//���� stues+(num-1)�� num�� �л� �����͸� �����ϴ� �޸� �ּ�
	stu = stues + (num - 1);
	stu->num = num;
	printf("�̸�: ");
	scanf_s("%s", stu->name, sizeof(stu->name));

	for (s = 0; s<MAX_SUBJECT; s++)
	{
		printf("%s ����:", stitles[s]);
		scanf_s("%d", stu->scores + s);

		if (IsAvailScore(stu->scores[s]) == 0)//��ȿ�� ������ �ƴ� ��
		{
			stu->scores[s] = -1;
			printf("�Է��� ������ ��ȿ���� �ʾƼ� %s ������ �Է� ó������ �ʾҽ��ϴ�.\n", stitles[s]);
		}
	}
}
int IsAvailNum(int num)
{
	return (num >= 1) && (num <= MAX_STUDENT);
}
int IsAvailScore(int score)
{
	return (score >= 0) && (score <= 100);
}
void RemoveStudent() //�л� ������ ����
{
	int num = 0;
	Student *stu = 0;
	int s = 0;

	printf("������ �л� ��ȣ(1~%d): ", MAX_STUDENT);
	scanf_s("%d", &num);

	if (IsAvailNum(num) == 0)//��ȿ�� ��ȣ�� �ƴ� ��
	{
		printf("������ ��� �л� ��ȣ�Դϴ�.\n");
		return;
	}

	if (stues[num - 1].num == 0)//��ȣ�� ������ ���°� �ƴ� ��
	{
		printf("�����Ͱ� �����ϴ�.\n");
		return;
	}

	stu = stues + (num - 1);
	strcpy_s(stu->name, sizeof(stu->name), "");
	stu->num = 0;
	for (s = 0; s<MAX_SUBJECT; s++)
	{
		stu->scores[s] = -1;
	}

	printf("�����Ͽ����ϴ�.\n");
}
void ViewStuData(Student *stu);
void FindStudent()  //�л� �˻�
{
	int num = 0;
	Student *stu = 0;
	int s = 0;

	printf("�˻��� �л� ��ȣ(1~%d): ", MAX_STUDENT);
	scanf_s("%d", &num);

	if (IsAvailNum(num) == 0)//��ȿ�� ��ȣ�� �ƴ� ��
	{
		printf("������ ��� �л� ��ȣ�Դϴ�.\n");
		return;
	}

	if (stues[num - 1].num == 0)//��ȣ�� ������ ���°� �ƴ� ��
	{
		printf("�����Ͱ� �����ϴ�.\n");
		return;
	}

	stu = stues + (num - 1);
	ViewStuData(stu);
}

void ViewStuData(Student *stu) //�л������� ����
{
	int i = 0;
	int s = 0;

	printf("%4d %10s ", stu->num, stu->name);
	for (s = 0; s<MAX_SUBJECT; s++)
	{
		printf("%4d ", stu->scores[s]);
	}
	printf("\n");
}
void ListStudent() //��� ����
{
	int i = 0;
	int s = 0;

	printf("%4s %10s ", "��ȣ", "�̸�");
	for (s = 0; s<MAX_SUBJECT; s++)
	{
		printf("%4s ", stitles[s]);
	}
	printf("������ -1�� ���� ���Է�\n");

	for (i = 0; i<MAX_STUDENT; i++)
	{
		if (stues[i].num)
		{
			ViewStuData(stues + i);
		}
	}
}
