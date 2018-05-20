#include "Classprop.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <memory.h>


void Class_SetHP(Class *CLASS, int hp);
void Class_SetIQ(Class *CLASS, int iq);
void Class_SetStress(Class *CLASS, int stress);
void Class_IncreSCnt(Class *CLASS);
void Class_Class(Class *CLASS, const char *name)
{
	/*�л��� ������ �� ���������� ��ȣ�� �ο��ϼ���.
		�̸� ���� ���� ������ ���� �ֱٿ� �ο��� �л� ��ȣ�� ����ϴ� ������ �����ϼ���.*/
	static int last_num;
	/*�Է� ���ڷ� ���޹��� �л��� �޸𸮸� �ʱ�ȭ�� �ʿ�����.*/
	memset(CLASS, 0, sizeof(Class));

	/*�׸��� �Է� ���ڷ� ���޹��� �̸��� �����ϼ���.*/
	strncpy_s(CLASS->name, sizeof(CLASS->name), name, MAX_NAME_LEN);
	/*������ ����鵵 �ʱⰪ���� �����ϼ���.*/
	CLASS->hp = DEF_HP;
	CLASS->iq = DEF_IQ;
	CLASS->stress = DEF_STRESS;
	CLASS->scnt = DEF_SCNT;
	/*���� �ֱٿ� �ο��� �л� ��ȣ�� 1 ������ �Ŀ� �л� ��ȣ�� �����ϼ���.*/
	last_num++;
	CLASS->num = last_num;
}

//�л��� �����ϸ� ü���� 5 �Ҹ��ϸ� ������ �������� ������ Ƚ����ŭ �����ϰ� ��Ʈ������ 2 �����Ѵ�.
void Class_Study(Class *CLASS)
{
	/*���� ���� �����ϴ��� �ܼ� ȭ�鿡 ����ϼ���*/
	printf("<%d>:%s �����ϴ�.\n", CLASS->num, CLASS->name);
	/*�׸��� �ó������� ���� ��ó�� �л��� �ɷ�ġ�� �����ϼ���.*/
		//�л��� �����ϸ� ü���� 5 �Ҹ��ϸ� ������ �������� ������ Ƚ����ŭ �����ϰ� ��Ʈ������ 2 �����Ѵ�.
		/*������ ���� �ɷ�ġ�� �ִ밪�� �ּҰ��� ������ ����� �ʰ� �����ϼ���.
		�̷��� �κ��� �ٸ� ��ɿ����� ���������� �����ؾ� �ϹǷ� �� �ɷ�ġ�� �����ϴ� �Լ��� ������ �����Ͽ� �����ϸ� ���ƿ�.*/
	Class_SetHP(CLASS, CLASS->hp - 5);
	Class_SetIQ(CLASS, CLASS->iq + CLASS->scnt);
	Class_SetStress(CLASS, CLASS->stress - 2);
	Class_IncreSCnt(CLASS);
}
//�л��� ���Ǹ� ������ ü���� 3 �Ҹ��ϸ� ������ �������� ������ Ƚ����ŭ �����ϰ� ��Ʈ������ 2 �����Ѵ�.
void Class_ListenLecture(Class *CLASS)
{
	printf("<%d>:%s ���ǹ޴�. \n", CLASS->num, CLASS->name);
	//�л��� ���Ǹ� ������ ü���� 3 �Ҹ��ϸ� ������ �������� ������ Ƚ����ŭ �����ϰ� ��Ʈ������ 2 �����Ѵ�.
	Class_SetHP(CLASS, CLASS->hp - 3);
	Class_SetIQ(CLASS, CLASS->iq + CLASS->scnt);
	Class_SetStress(CLASS, CLASS->stress + 2);
	CLASS->scnt = 0;
}
//�л��� �޽��ϸ� ü���� 3ȸ���ϰ� ��Ʈ������ 10 �����Ѵ�.
void Class_Relax(Class *CLASS)
{
	printf("<%d>:%s �޽��ϴ�. \n", CLASS->num, CLASS->name);
	//�л��� �޽��ϸ� ü���� 3ȸ���ϰ� ��Ʈ������ 10 �����Ѵ�.
	Class_SetHP(CLASS, CLASS->hp + 3);
	Class_SetStress(CLASS, CLASS->stress - 10);
	CLASS->scnt = 0;
}
//�л��� ���� �ڸ� ü���� 10 ȸ���ϰ� ��Ʈ������ 5 �����Ѵ�.
void Class_Sleep(Class *CLASS)
{
	printf("<%d>:%s �����ڴ�. \n", CLASS->num, CLASS->name);
	//�л��� ���� �ڸ� ü���� 10 ȸ���ϰ� ��Ʈ������ 5 �����Ѵ�.
	Class_SetHP(CLASS, CLASS->hp + 10);
	Class_SetStress(CLASS, CLASS->stress - 5);
	CLASS->scnt = 0;
}
//�л��� ���Ḧ ���ø� ü���� 10 �Ҹ��ϸ� ������ 5 �����ϰ� ��Ʈ������ 2 �����Ѵ�.
void Class_Drink(Class *CLASS)
{
	printf("<%d>:%s ���Ḧ ���ô�. \n", CLASS->num, CLASS->name);
	//�л��� ���Ḧ ���ø� ü���� 10 �Ҹ��ϸ� ������ 5 �����ϰ� ��Ʈ������ 2 �����Ѵ�.
	Class_SetHP(CLASS, CLASS->hp - 10);
	Class_SetIQ(CLASS, CLASS->iq - 5);
	Class_SetStress(CLASS, CLASS->stress - 2);
	CLASS->scnt = 0;
}
//�л��� �뷡�ϸ� ü���� 10 �Ҹ��ϸ� ������ 1 �����ϰ� ��Ʈ������ 5 �����Ѵ�.
void Class_Sing(Class *CLASS)
{
	printf("<%d>:%s �뷡�ϴ�. \n", CLASS->num, CLASS->name);
	// �л��� �뷡�ϸ� ü���� 10 �Ҹ��ϸ� ������ 1 �����ϰ� ��Ʈ������ 5 �����Ѵ�.
	Class_SetHP(CLASS, CLASS->hp - 10);
	Class_SetIQ(CLASS, CLASS->iq + 1);
	Class_SetStress(CLASS, CLASS->stress - 5);
	CLASS->scnt = 0;
}
//�߰��� �л� ������ ����ϴ� ����� �����Ѵ�.
void Class_View(Class *CLASS)
{
	//�л� ��ȣ�� �̸��� �߿��� �������̹Ƿ� ���� ����ϴ� ���� ������.
	printf("<%d>:%s\n", CLASS ->num, CLASS -> name);
	//�׸��� ������ �ɷ�ġ�� ����ϼ���.
	//���� �������� ������ Ƚ���� ����� �ʿ䰡 ������.
	//��� �����͸� ���� ����ڿ��� �˷��� �ʿ�� �����.
	printf("\t ü��:%d ����ť:%d ��Ʈ����:%d\n", CLASS ->hp, CLASS -> iq, CLASS -> stress);
}

void Class_SetHP(Class *CLASS, int hp)
{
	/*�Է� ���ڷ� ���޹��� ���� �ִ밪�� ����� �ִ밪���� �����ϼ���*/
	if (hp > MAX_HP)
	{
		hp = MAX_HP;
	}
	/*���������� �ּҰ��� ����� �ּҰ����� �����ؾ߰���.*/
	if (hp < MIN_HP)
	{
		hp = MIN_HP;
	}
	/*���� ������ ������ �л��� hp�� �����ϼ���.*/
	CLASS->hp = hp;
}
void Class_SetIQ(Class *CLASS, int iq)
{
	if (iq > MAX_IQ)
	{
		iq = MAX_IQ;
	}
	if (iq < MIN_IQ)
	{
		iq = MIN_IQ;
	}
	CLASS->iq = iq;
}
void Class_SetStress(Class *CLASS, int stress)
{
	if (stress > MAX_STRESS)
	{
		stress = MAX_STRESS;
	}
	if (stress < MIN_STRESS)
	{
		stress = MIN_STRESS;
	}
	CLASS->stress = stress;
}
void Class_IncreSCnt(Class *CLASS)
{
	/*�л��� scnt ���� �ִ밪���� ���� ���� 1 �����ϰ� �ϼ���.*/
	if (CLASS->scnt < MAX_SCNT)
	{
		CLASS->scnt++;
	}
}