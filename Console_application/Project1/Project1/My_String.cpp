#include <stdio.h>
#include "My_String.h"

int My_String()
{
	unsigned int Index;
Initiate_Program:
	printf("\n\n____________________________________________________________________________\n");
	printf("1: ���ڿ� �⺻ \n");
	printf("2: ���ڿ� �ٲٱ� \n");
	printf("3: ���ڿ� ��ġ�� \n");
	//printf("4: �� ����� ������ �ٲٱ� \n");
	//printf("5: �迭�� �Է¼� ��ŭ ���� \n");
	//printf("6: ������ �Լ� \n");
	//printf("1: �Լ� �⺻ (���ϴ� ������ ����) \n");
	//printf("1: �Լ� �⺻ (���ϴ� ������ ����) \n");
	//printf("1: �Լ� �⺻ (���ϴ� ������ ����) \n");
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
		printf("���� ������� �� �˾� ��ھ�. �п� \n");
		main();
		break;
	}
	return 0;
}

//String
int String_Basic()
{
	char null_1 = '\0'; // �� 3 ���� ��� �����ϴ�
	char null_2 = 0;
	char null_3 = NULL; // ��� �빮�ڷ� ��� �Ѵ�

	char not_null = '0';

	printf("%d, %d, %d\n", null_1, null_2, null_3);
	printf("'0' �� ����(�ƽ�Ű)�� : %d \n", not_null);

	char sentence_1[4] = { 'P', 's', 'i', '\0' };
	char sentence_2[4] = { 'P', 's', 'i', 0 };
	char sentence_3[4] = { 'P', 's', 'i', NULL };
	char sentence_4[4] = { "Psi" };

	printf("sentence_1[4] = %s \n", sentence_1); // %s �� ���ؼ� ���ڿ��� ����Ѵ�.
	printf("sentence_2[4] = %s \n", sentence_2);
	printf("sentence_3[4] = %s \n", sentence_3);
	printf("sentence_4[4] = %s \n", sentence_4);



	printf("\n\n===========================\n\n");
	printf("�����͸� �迭��� ����ؼ� ���\n");
	printf("\n\n===========================\n\n");
	char word[30] = { "long sentence" };
	char *str = word;

	printf("%s \n", str);

	return 0;


	printf("\n\n===========================\n\n");
	printf("���ڿ� �ٲٱ�\n");
	printf("\n\n===========================\n\n");
	char word1[] = { "long sentence" };


	printf("���� ���� : %s \n", word1);

	word[0] = 'a';
	word[1] = 'b';
	word[2] = 'c';
	word[3] = 'd';

	printf("���� ���� : %s \n", word1);


}
int String_Change()
{

	char Word_Base[30] = { "Hello World" };
	char Word_Input[30];

	printf("30 �� �̳��� ���ڿ��� �Է����ּ���! : ");
	scanf_s("%s", Word_Input, sizeof(Word_Input));


	printf("�⺻ ���ڿ� : %s \n", Word_Base);
	printf("�ٲ� ���ڿ� : %s \n", Word_Input);

	for (int i = 0; i < 30; i++)
	{
		Word_Base[i] = Word_Input[i];
	}

	int num;
	char c;

	printf("�ٲ� ���� : %s \n", Word_Base);

	printf("���ڸ� �Է��ϼ��� : ");
	scanf_s("%d", &num);

	printf("���ڸ� �Է��ϼ��� : ");
	scanf_s("%c", &c);

	return 0;

}
#pragma region String_Merge
int String_Merge_Func(char *pstr1,char *pstr2);
int String_Merge()
{


	char str1[100] = "hello my name is ";
	char str2[10];

	printf("�̸��� �Է����ּ���! : ");
	scanf_s("%s", str2, sizeof(str2));

	String_Merge_Func(str1, str2);
	printf("%s",str1);
	return 0;
}
int String_Merge_Func(char *pstr_base,char *pstr_plus)
{


	/* dest �� �� �κ��� ã�´�.*/
	while (*pstr_base)
	{
		pstr_base++;
	}

	/*
	while ���� ������ ���� dest �� dest ���ڿ��� NULL ���ڸ� ����Ű�� �ְ� �ȴ�.
	���� src �� ���ڿ����� dest �� NULL ���� �ִ� �� ���� �����سִ´�.
	*/
	while (*pstr_plus)
	{
		*pstr_base = *pstr_plus;
		pstr_plus++;
		pstr_base++;
	}

	/* ���������� dest �� NULL �߰� (�ֳ��ϸ� src ���� NULL �� �߰� ���� �ʾ����Ƿ�) */
	*pstr_base = '\0';

	return 1;

}
#pragma endregion


// str1 �� "hello my name is Psi" �� �ȴ�.
