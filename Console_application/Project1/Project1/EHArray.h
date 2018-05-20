#pragma once
typedef struct _EHArray EHArray;
typedef void * Element;
typedef Element * Iterator;

struct _EHArray
{
	Element *base; //������� ��ġ ����
	int capacity;     //���� ������� ũ��
	int size;           //���� ������ ��� ����
};

EHArray *EHArray_New(int init_capa, Element init_value); //�������� �迭 ����
void EHArray_Delete(EHArray *eharr); //�迭 �Ҹ�
int EHArray_GetCapacity(EHArray *eharr); //������� ũ�� ��������
int EHArray_GetSize(EHArray *eharr);       //������ ��� ���� ��������
void EHArray_PushBack(EHArray *eharr, Element data); //���������� �ڷ� ����
Element EHArray_GetAt(EHArray *eharr, int index); //������ ��� ��������
void EHArray_SetAt(EHArray *eharr, int index, Element data); //������ ��� �����ϱ�
Iterator EHArray_Begin(EHArray *eharr); //������� ���� ��ġ
Iterator EHArray_End(EHArray *eharr); //������� ������ ��ġ(������ ��ġ)
void EHArray_Erase(EHArray *eharr, Iterator it);//������ ��� �����ϱ�