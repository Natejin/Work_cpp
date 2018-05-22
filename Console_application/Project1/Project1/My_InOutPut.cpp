#include <stdio.h>
#include "My_InOutPut.h"
#include <direct.h> //mkdir
#include <errno.h> //errno
#include <stdlib.h>

#ifndef _MAX_PATH
#define _MAX_PATH 260
#endif


void My_InOutPut()
{
	unsigned int Index;
Initiate_Program:
	printf("\n\n____________________________________________________________________________\n");
	printf("1: IOP_Basic_read and right \n");
	printf("2: IOPut_read_by_seek \n");
	printf("3: IOP_change Upper \n");
	printf("4: IOPut_read_and_write_word\n");
	printf("5: IOPut_add_word\n");
	printf("6: IOPut_scans_f\n");
	//printf("7: ���� ������ 1�� �迭 \n");
	//printf("8: ������ 2�� �迭 \n");
	//printf("9: ������ 3�� �迭 \n");
	//printf("10: ������ ���� \n");
	//printf("11: void ������ \n");
	printf("\n____________________________________________________________________________\n");
	printf("\nInput value : ");
	scanf_s("%d", &Index);
	printf("\n____________________________________________________________________________\n\n");
	switch (Index)
	{
	case(1):
		IOPut_Basic1();
		goto Initiate_Program;
		break;
	case(2):
		IOPut_read_by_seek();
		goto Initiate_Program;
		break;
	case(3):
		IOPut_change_upper();
		goto Initiate_Program;
		break;
	case(4):
		IOPut_read_and_write_word();
		goto Initiate_Program;
		break;
	case(5):
		IOPut_add_word();
		goto Initiate_Program;
		break;
	case(6):
		IOPut_scans_f();
		goto Initiate_Program;
		break;
		//case(7):
		//	Pointer_Double_One_D_Array();
		//	goto Initiate_Program;
		//	break;
		//case(8):
		//	Pointer_Two_D_Array();
		//	goto Initiate_Program;
		//	break;
		//case(9):
		//	Pointer_Three_D_Array();
		//	goto Initiate_Program;
		//	break;
		//case(10):
		//	Pointer_Summary();
		//	goto Initiate_Program;
		//	break;
		//case(11):
		//	Pointer_Void();
		//	goto Initiate_Program;
		//	break;

	default:
		printf("���� ������� �� �˾� ��ھ�. �п� \n");
		main();
		break;
	}

}

//Pointer
void IOPut_Basic1()
{
	//char strBuffer[_MAX_PATH] = { 0, };
	//char *pstrBuffer = NULL;

	//pstrBuffer = getcwd( strBuffer, _MAX_PATH );

	//char strFolderPath[] = { "D:\\CreateFolder" };
	//int nResult = _mkdir("%s\\CreateFolder", pstrBuffer,sizeof(pstrBuffer));


	//if (nResult == 0)
	//{
	//	printf("���� ���� ����");

	//}
	//else if (nResult == -1)
	//{
	//	perror("���� ���� ���� - ������ �̹� �ְų� ����Ȯ��\n");
	//	printf("errorno : %d", errno);
	//}
//write
	FILE *fp;
	char c;
	fopen_s(&fp, "a.txt", "w");

	if (fp == NULL)
	{
		printf("Write Error!!\n");
	}

	fputs("Hello World!!! \n", fp);

	fclose(fp);
	//read

	fopen_s(&fp, "a.txt", "r");
	int size = 0;

	while ((c = fgetc(fp)) != EOF)
	{
		printf("%c", c);
		size++;
	}


	fclose(fp);
	printf("�� ������ ũ��� : %d bytes \n", size);

	fopen_s(&fp, "a.txt", "w");
	fseek(fp, 0, SEEK_SET);
	fputs("New World \n", fp);

	size = 0;
	fclose(fp);
	fopen_s(&fp, "a.txt", "r");
	while ((c = fgetc(fp)) != EOF)
	{
		printf("%c", c);
		size++;
	}
	printf("�� ������ ũ��� : %d bytes \n", size);
	fclose(fp);
}

void IOPut_read_by_seek()
{
	//char input[100];
	//char *pinput;
	//pinput = input;
	//scanf_s("%s", pinput, sizeof(pinput));
	//printf("%s\n", pinput);
	FILE *fp;
	fopen_s(&fp, "a.txt", "r");
	char data[10];
	char c;

	if (fp == NULL)
	{
		printf("file open error ! \n");
	}

	fgets(data, 5, fp);
	printf("�Է� ���� ������ : %s \n", data);

	c = fgetc(fp);
	printf("�� ������ �Է� ���� ���� : %c \n", c);

	fseek(fp, -1, SEEK_CUR);

	c = fgetc(fp);
	printf("�׷��ٸ� ���� ���ڰ�? : %c \n", c);

	fclose(fp);
}

void IOPut_change_upper()
{
	FILE *fp;
	fopen_s(&fp, "a.txt", "r+");
	char c;

	if (fp == NULL)
	{
		printf("���� ���⸦ �����Ͽ����ϴ�! \n");
	}

	while ((c = fgetc(fp)) != EOF)
	{
		/* c �� �빮���� ��� */
		if (65 <= c && c <= 90)
		{
			/* �� ĭ �ڷ� ����*/
			fseek(fp, -1, SEEK_CUR);
			/* �ҹ��ڷ� �ٲ� c �� ����Ѵ�*/
			fputc(c + 32, fp);
			/*

			���� - �б� ��� ��ȯ�� ���ؼ��� ������
			fseek �Լ��� ���� ���� ��ġ ������ ���� �Լ�����
			ȣ���ؾ� �Ѵ�.

			*/
			fseek(fp, 0, SEEK_CUR);
		}
		/* c �� �ҹ����� ���*/
		else if (97 <= c && c <= 122)
		{
			fseek(fp, -1, SEEK_CUR);
			fputc(c - 32, fp);
			fseek(fp, 0, SEEK_CUR);
		}
	}

	fclose(fp);
}

void IOPut_read_and_write_word()
{



	FILE *fp1;
	fopen_s(&fp1, "a.txt", "r+");
	char data1[100];

	fgets(data1, 100, fp1);
	printf("���� ���Ͽ� �ִ� ���� : %s \n", data1);

	fseek(fp1, 5, SEEK_SET);

	fputs("is nothing on this file", fp1);

	fclose(fp1);
}

void IOPut_add_word()
{
	FILE *fp;
	fopen_s(&fp,"a.txt", "a");


	if (fp == NULL)
	{
		printf("���� ���⸦ �����Ͽ����ϴ�! \n");

	}

	/* �Ʒ� ������ ���� �ڿ� ���ٿ�����.*/
	fputs("IS ADDED HAHAHAHA", fp);
	fclose(fp);
}

#define MAX_MEMBERS     10
#define MAX_NAME_LEN    20

//ȸ�� ����ü ����
struct Class
{
	char name[MAX_NAME_LEN + 1];
	int age;
};
typedef Class Classed;
void IOPut_scans_f()
{
	FILE * fp;
	int i;
	//���� ȸ�� �迭
	//Member members[MAX_MEMBERS] =
	//{
	//	{ "ȫ�浿",20 },{ "������",15 },{ "��������",22 },{ "�̼���",19 },{ "�豸",30 },
	//{ "���߱�",30 },{ "����ȣ",35 },{ "�迬��",17 },{ "������",20 },{ "�ִϿ�",20 }
	//};
	Classed *arr_class;
	int size;
	printf("���Ͻô� �ɹ��� ���� : ");
	scanf_s("%d", &size);


	arr_class = (Classed *)malloc(sizeof(Classed) * size);

	for (i = 0; i<size; i++)
	{
		printf("player[%d].classes : ", i + 1);
		scanf_s("%s", &arr_class[i].name,sizeof(arr_class[MAX_NAME_LEN+1].name));
		printf("player[%d].races : ", i + 1);
		scanf_s("%d", &arr_class[i].age);
	}

	//�о�� ȸ�� �迭
	Class members[MAX_MEMBERS];

	//���� ���� ���� ����
	fopen_s(&fp, "data.txt", "w");
	if (fp == NULL)
	{
		perror("error fopen");
		return;
	}

	//��ü ȸ�� ������ ���Ͽ� ����
	for (i = 0; i<MAX_MEMBERS; i++)
	{
		fprintf(fp, "%-10s %-10d\n", arr_class[i].name, arr_class[i].age);
	}
	fclose(fp);//���� ��Ʈ���ݱ�

	//�б� ���� ���� ����
	fopen_s(&fp, "data.txt", "r");
	if (fp == NULL)
	{
		perror("error fopen");
		return;
	}

	//����� ���� ���
	printf("%-10s %-10s\n", "�̸�", "����");
	//�Է� ���� ��Ʈ������ ���信 �°� ȸ�� ���� �о�� �Ŀ� ��� �ݺ�
	for (i = 0; i<MAX_MEMBERS; i++)
	{
		fscanf_s(fp, "%s %d\n", members[i].name, MAX_NAME_LEN, &members[i].age);
		printf("%-10s %-10d\n", members[i].name, members[i].age);
	}
	fclose(fp);//���� ��Ʈ�� �ݱ�

}
