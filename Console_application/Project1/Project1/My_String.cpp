#include <stdio.h>
#include "My_String.h"

int My_String()
{
	unsigned int Index;
Initiate_Program:
	printf("\n\n____________________________________________________________________________\n");
	printf("1: 문자열 기본 \n");
	printf("2: 문자열 바꾸기 \n");
	printf("3: 문자열 합치기 \n");
	//printf("4: 두 상수의 포인터 바꾸기 \n");
	//printf("5: 배열에 입력수 만큼 증가 \n");
	//printf("6: 포인터 함수 \n");
	//printf("1: 함수 기본 (원하는 값으로 변경) \n");
	//printf("1: 함수 기본 (원하는 값으로 변경) \n");
	//printf("1: 함수 기본 (원하는 값으로 변경) \n");
	printf("\n____________________________________________________________________________\n");
	printf("\nInput value : ");
	scanf_s("%d", &Index);
	printf("\n____________________________________________________________________________\n\n");
	switch (Index)
	{
	case(1):
		String_Basic();
		goto Initiate_Program;
		break;
	case(2):
		String_Change();
		goto Initiate_Program;
		break;
	case(3):
		String_Merge();
		goto Initiate_Program;
		break;

	default:
		printf("무슨 명령인지 못 알아 듣겠어. 왈왈 \n");
		main();
		break;
	}
	return 0;
}

//String
int String_Basic()
{
	char null_1 = '\0'; // 이 3 개는 모두 동일하다
	char null_2 = 0;
	char null_3 = NULL; // 모두 대문자로 써야 한다

	char not_null = '0';

	printf("%d, %d, %d\n", null_1, null_2, null_3);
	printf("'0' 의 정수(아스키)값 : %d \n", not_null);

	char sentence_1[4] = { 'P', 's', 'i', '\0' };
	char sentence_2[4] = { 'P', 's', 'i', 0 };
	char sentence_3[4] = { 'P', 's', 'i', NULL };
	char sentence_4[4] = { "Psi" };

	printf("sentence_1[4] = %s \n", sentence_1); // %s 를 통해서 문자열을 출력한다.
	printf("sentence_2[4] = %s \n", sentence_2);
	printf("sentence_3[4] = %s \n", sentence_3);
	printf("sentence_4[4] = %s \n", sentence_4);



	printf("\n\n===========================\n\n");
	printf("포인터를 배열대신 사용해서 출력\n");
	printf("\n\n===========================\n\n");
	char word[30] = { "long sentence" };
	char *str = word;

	printf("%s \n", str);

	return 0;


	printf("\n\n===========================\n\n");
	printf("문자열 바꾸기\n");
	printf("\n\n===========================\n\n");
	char word1[] = { "long sentence" };


	printf("조작 이전 : %s \n", word1);

	word[0] = 'a';
	word[1] = 'b';
	word[2] = 'c';
	word[3] = 'd';

	printf("조작 이후 : %s \n", word1);


}
int String_Change()
{

	char Word_Base[30] = { "Hello World" };
	char Word_Input[30];

	printf("30 자 이내의 문자열을 입력해주세요! : ");
	scanf_s("%s", Word_Input, sizeof(Word_Input));


	printf("기본 문자열 : %s \n", Word_Base);
	printf("바꿀 문자열 : %s \n", Word_Input);

	for (int i = 0; i < 30; i++)
	{
		Word_Base[i] = Word_Input[i];
	}

	int num;
	char c;

	printf("바꾼 이후 : %s \n", Word_Base);

	printf("숫자를 입력하세요 : ");
	scanf_s("%d", &num);

	printf("문자를 입력하세요 : ");
	scanf_s("%c", &c);

	return 0;

}
#pragma region String_Merge
int String_Merge_Func(char *pstr1,char *pstr2);
int String_Merge()
{


	char str1[100] = "hello my name is ";
	char str2[10];

	printf("이름을 입력해주세요! : ");
	scanf_s("%s", str2, sizeof(str2));

	String_Merge_Func(str1, str2);
	printf("%s",str1);
	return 0;
}
int String_Merge_Func(char *pstr_base,char *pstr_plus)
{


	/* dest 의 끝 부분을 찾는다.*/
	while (*pstr_base)
	{
		pstr_base++;
	}

	/*
	while 문을 지나고 나면 dest 는 dest 문자열의 NULL 문자를 가리키고 있게 된다.
	이제 src 의 문자열들을 dest 의 NULL 문자 있는 곳 부터 복사해넣는다.
	*/
	while (*pstr_plus)
	{
		*pstr_base = *pstr_plus;
		pstr_plus++;
		pstr_base++;
	}

	/* 마지막으로 dest 에 NULL 추가 (왜냐하면 src 에서 NULL 이 추가 되지 않았으므로) */
	*pstr_base = '\0';

	return 1;

}
#pragma endregion


// str1 은 "hello my name is Psi" 가 된다.
