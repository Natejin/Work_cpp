

#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <string.h> 

#define MAX_STUDENT 10//�ִ� �л� ��
#define MAX_NLEN    20 //�ִ� �̸� ����
#define MAX_SUBJECT 3 //���� ��

typedef struct {//�л� ����ü ����
	char name[MAX_NLEN + 1];//�̸�
	int num; //��ȣ
	int scores[MAX_SUBJECT];//��,��,�� ����
}Student;

void Initialize();		//�л� ������ �ʱ�ȭ
void Run();				//����	
//void Control_Grade();	//����
//
int SelectMenu();//�޴� ��� �� ����
void AddStudent();//�л� ������ �Է�
void RemoveStudent();//�л� ������ ����
void FindStudent();//�л� �˻�
void ListStudent();//��� ����
//
int IsAvailNum(int num);	//��ȿ�� ��ȣ���� �Ǻ�
int IsAvailScore(int score);	//��ȿ�� �������� �Ǻ�
void Control_Grade();