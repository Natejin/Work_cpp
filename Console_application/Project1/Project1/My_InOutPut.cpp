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
	//printf("7: 더블 포인터 1차 배열 \n");
	//printf("8: 포인터 2차 배열 \n");
	//printf("9: 포인터 3차 배열 \n");
	//printf("10: 포인터 정리 \n");
	//printf("11: void 포인터 \n");
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
		printf("무슨 명령인지 못 알아 듣겠어. 왈왈 \n");
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
	//	printf("폴더 생성 성공");

	//}
	//else if (nResult == -1)
	//{
	//	perror("폴더 생성 실패 - 폴더가 이미 있거나 부정확함\n");
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
	printf("이 파일의 크기는 : %d bytes \n", size);

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
	printf("이 파일의 크기는 : %d bytes \n", size);
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
	printf("입력 받은 데이터 : %s \n", data);

	c = fgetc(fp);
	printf("그 다음에 입력 받은 문자 : %c \n", c);

	fseek(fp, -1, SEEK_CUR);

	c = fgetc(fp);
	printf("그렇다면 무슨 문자가? : %c \n", c);

	fclose(fp);
}

void IOPut_change_upper()
{
	FILE *fp;
	fopen_s(&fp, "a.txt", "r+");
	char c;

	if (fp == NULL)
	{
		printf("파일 열기를 실패하였습니다! \n");
	}

	while ((c = fgetc(fp)) != EOF)
	{
		/* c 가 대문자일 경우 */
		if (65 <= c && c <= 90)
		{
			/* 한 칸 뒤로 가서*/
			fseek(fp, -1, SEEK_CUR);
			/* 소문자로 바뀐 c 를 출력한다*/
			fputc(c + 32, fp);
			/*

			쓰기 - 읽기 모드 전환을 위해서는 무조건
			fseek 함수와 같은 파일 위치 지정자 설정 함수들을
			호출해야 한다.

			*/
			fseek(fp, 0, SEEK_CUR);
		}
		/* c 가 소문자일 경우*/
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
	printf("현재 파일에 있는 내용 : %s \n", data1);

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
		printf("파일 열기를 실패하였습니다! \n");

	}

	/* 아래 내용이 파일 뒤에 덧붙여진다.*/
	fputs("IS ADDED HAHAHAHA", fp);
	fclose(fp);
}

#define MAX_MEMBERS     10
#define MAX_NAME_LEN    20

//회원 구조체 정의
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
	//원본 회원 배열
	//Member members[MAX_MEMBERS] =
	//{
	//	{ "홍길동",20 },{ "강감찬",15 },{ "을지문덕",22 },{ "이순신",19 },{ "김구",30 },
	//{ "안중근",30 },{ "박찬호",35 },{ "김연아",17 },{ "아이유",20 },{ "주니엘",20 }
	//};
	Classed *arr_class;
	int size;
	printf("원하시는 맴버의 숫자 : ");
	scanf_s("%d", &size);


	arr_class = (Classed *)malloc(sizeof(Classed) * size);

	for (i = 0; i<size; i++)
	{
		printf("player[%d].classes : ", i + 1);
		scanf_s("%s", &arr_class[i].name,sizeof(arr_class[MAX_NAME_LEN+1].name));
		printf("player[%d].races : ", i + 1);
		scanf_s("%d", &arr_class[i].age);
	}

	//읽어올 회원 배열
	Class members[MAX_MEMBERS];

	//쓰기 모드로 파일 열기
	fopen_s(&fp, "data.txt", "w");
	if (fp == NULL)
	{
		perror("error fopen");
		return;
	}

	//전체 회원 정보를 파일에 쓰기
	for (i = 0; i<MAX_MEMBERS; i++)
	{
		fprintf(fp, "%-10s %-10d\n", arr_class[i].name, arr_class[i].age);
	}
	fclose(fp);//파일 스트림닫기

	//읽기 모드로 파일 열기
	fopen_s(&fp, "data.txt", "r");
	if (fp == NULL)
	{
		perror("error fopen");
		return;
	}

	//장식을 위한 출력
	printf("%-10s %-10s\n", "이름", "나이");
	//입력 파일 스트림에서 포멧에 맞게 회원 정보 읽어온 후에 출력 반복
	for (i = 0; i<MAX_MEMBERS; i++)
	{
		fscanf_s(fp, "%s %d\n", members[i].name, MAX_NAME_LEN, &members[i].age);
		printf("%-10s %-10d\n", members[i].name, members[i].age);
	}
	fclose(fp);//파일 스트림 닫기

}
