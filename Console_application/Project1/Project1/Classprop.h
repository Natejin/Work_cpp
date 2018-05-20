#pragma once

#define MAX_NAME_LEN    20
typedef struct _Class Class;
struct _Class
{
	char name[MAX_NAME_LEN + 1];//�̸�
	int num; //��ȣ
	int hp; //ü��
	int iq; //����
	int stress; //��Ʈ����
	int scnt; //�������� ������ Ƚ��
};
enum _ClassConst
{
	MIN_HP = 0, MAX_HP = 100, DEF_HP = 100,
	MIN_IQ = 0, MAX_IQ = 200, DEF_IQ = 100,
	MIN_STRESS = 0, MAX_STRESS = 100, DEF_STRESS = 0,
	MIN_SCNT = 0, MAX_SCNT = 5, DEF_SCNT = 0
};

void Class_Class(Class *CLASS, const char *name); //������
void Class_Study(Class *CLASS);//�����ϴ�.
void Class_ListenLecture(Class *CLASS);//���ǹ޴�.
void Class_Relax(Class *CLASS);//�޽��ϴ�.
void Class_Sleep(Class *CLASS);//���ڴ�.
void Class_Drink(Class *CLASS);//���Ḧ ���ô�.
void Class_Sing(Class *CLASS);//�뷡�ϴ�.
void Class_View(Class *CLASS);//�ڽ��� ������ ����ϴ�.