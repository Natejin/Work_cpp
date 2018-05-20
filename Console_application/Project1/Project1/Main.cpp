#include <stdio.h>
//#include <stdlib.h>
//#include <conio.h>		   //_getch
#include <string.h>       // memset 
#include "My_Array.h" 
#include "My_String.h"
#include "My_Struct.h"
#include "My_DMA.h"
#include "My_Linked_lists.h"

#pragma warning( disable : 4477)
#pragma warning( disable : 4473)		// scanf_s not enough arguments passed for format string
//#pragma warning( disable : 4996)		//scanf_s
#pragma warning( disable : 4313)


int Point();
int Function();
int test();


#pragma region  Pointer
int Point_Basic();
int Point_Const();
int Point_Cal();
int Point_Array1();
int Point_Array2();
int Point_Double();
int Point_Double_One_D_Array();
int Point_Two_D_Array();
int Point_Three_D_Array();
int Point_Summary();
int Point_Void();
#pragma endregion
#pragma region Function
int Function_Basic_Change_Val();
int Function_Basic_Swap_Val();
int Function_Find_Max_Val();
int Function_Swap_Pointer();
int Function_Increase_Element_Two_Array();
int Function_Pointer();
#pragma endregion


int main()
{
	unsigned int Index;
Initiate_Program:
	printf("\n\n____________________________________________________________________________\n");
	printf("0: Zombie\n");
	printf("1: Array\n");
	printf("2: Pointer\n");
	printf("3: Function\n");
	printf("4: String\n");
	printf("5: Structure\n");
	printf("6: Dynamic Memory Alloication\n");
	printf("7: Linked Lists\n");
	printf("\n____________________________________________________________________________\n");
	printf("\nInput value : ");
	scanf_s("%d", &Index);
	printf("\n____________________________________________________________________________\n");
	switch (Index)
	{
	case(0):
		test();
		goto Initiate_Program;
		break;
	case(1):
		My_Array();
		goto Initiate_Program;
		break;
	case(2):
		Point();
		goto Initiate_Program;
		break;
	case(3):
		Function();
		goto Initiate_Program;
		break;
	case(4):
		My_String();
		goto Initiate_Program;
		break;
	case(5):
		My_Struct();
		goto Initiate_Program;
		break;
	case(6):
		My_DMA();
		goto Initiate_Program;
		break;
	case(7):
		My_Linked_lists();
		goto Initiate_Program;
		break;
		
	default:
		printf("���� ������� �� �˾� ��ھ�. �п� \n");
		goto Initiate_Program;
		break;
	}


}


int Point()
{
	unsigned int Index;
Initiate_Program:
	printf("\n\n____________________________________________________________________________\n");
	printf("1: ������ �⺻ \n");
	printf("2: ��� ������ \n");
	printf("3: ������ ��� \n");
	printf("4: ������ �迭 1\n");
	printf("5: ������ �迭 2\n");
	printf("6: ���� ������ \n");
	printf("7: ���� ������ 1�� �迭 \n");
	printf("8: ������ 2�� �迭 \n");
	printf("9: ������ 3�� �迭 \n");
	printf("10: ������ ���� \n");
	printf("11: void ������ \n");
	printf("\n____________________________________________________________________________\n");
	printf("\nInput value : ");
	scanf_s("%d", &Index);
	printf("\n____________________________________________________________________________\n\n");
	switch (Index)
	{
	case(1):
		Point_Basic();
		goto Initiate_Program;
		break;
	case(2):
		Point_Const();
		goto Initiate_Program;
		break;
	case(3):
		Point_Cal();
		goto Initiate_Program;
		break;
	case(4):
		Point_Array1();
		goto Initiate_Program;
		break;
	case(5):
		Point_Array2();
		goto Initiate_Program;
		break;
	case(6):
		Point_Double();
		goto Initiate_Program;
		break;
	case(7):
		Point_Double_One_D_Array();
		goto Initiate_Program;
		break;
	case(8):
		Point_Two_D_Array();
		goto Initiate_Program;
		break;
	case(9):
		Point_Three_D_Array();
		goto Initiate_Program;
		break;
	case(10):
		Point_Summary();
		goto Initiate_Program;
		break;
	case(11):
		Point_Void();
		goto Initiate_Program;
		break;

	default:
		printf("���� ������� �� �˾� ��ھ�. �п� \n");
		main();
		break;
	}
	return 0;
}
int Function()
{
	unsigned int Index;
Initiate_Program:
	printf("\n\n____________________________________________________________________________\n");
	printf("1: �Լ� �⺻ (���ϴ� ������ ����) \n");
	printf("2: �Լ� �⺻ (�� �ٲٱ�) \n");
	printf("3: �Է��� ���� �ְ� ��� \n");
	printf("4: �� ����� ������ �ٲٱ� \n");
	printf("5: �迭�� �Է¼� ��ŭ ���� \n");
	printf("6: ������ �Լ� \n");
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
		Function_Basic_Change_Val();
		goto Initiate_Program;
		break;
	case(2):
		Function_Basic_Swap_Val();
		goto Initiate_Program;
		break;
	case(3):
		Function_Find_Max_Val();
		goto Initiate_Program;
		break;
	case(4):
		Function_Swap_Pointer();
		goto Initiate_Program;
		break;
	case(5):
		Function_Increase_Element_Two_Array();
		goto Initiate_Program;
		break;
	case(6):
		Function_Pointer();
		goto Initiate_Program;
		break;

	default:
		printf("���� ������� �� �˾� ��ھ�. �п� \n");
		main();
		break;
	}
	return 0;
}


//Point
int Point_Basic()
{
	unsigned int *p;
	unsigned int a;

	p = &a;

	printf("������ p �� ��� �ִ� �� : %p \n", p);
	printf("int ���� a �� ����� �ּ� : %p \n", &a);

	a = 2;

	printf("a �� �� : %d \n", a);
	printf("*p �� �� : %d \n", *p);

	*p = 3;
	printf("a �� �� : %d \n", a);
	printf("*p �� �� : %d \n", *p);

	return 0;
}
int Point_Const()
{

	const unsigned int a = 5;
	const unsigned int *p = &a;

	printf("const unsigned int *p=&a; p �ּ��� ���� ���� (*p=val ���Ұ�)\n");
	printf("unsigned int *const p=&a; p �ּҸ� ���� (p=address ���Ұ�)\n");

	printf("a �� �� : %d \n", a);
	printf("*p �� �� : %d \n", *p);
	printf("������ p �� ��� �ִ� �� : %p \n", p);
	printf("int ���� a �� ����� �ּ� : %p \n", &a);


	return 0;
}
int Point_Cal()
{
	int a;
	short int d;
	char b;
	double c;
	int* pa = &a;
	char* pb = &b;
	double* pc = &c;
	short int *pd = &d;


	//printf("pb (char) �� �� : %o, %d, %x \n", pb,pb,pb);
	//printf("(pb + 1) �� �� : %o, %d, %x \n\n", pb + 1, pb + 1, pb + 1);
	//printf("pa (short int) �� �� : %o, %d, %x \n", pd, pd, pd);
	//printf("(pd + 1) �� �� : %o, %d, %x \n\n", pd + 1, pd + 1, pd + 1);
	//printf("pa (int) �� �� : %o, %d, %x \n", pa, pa,pa);
	//printf("(pa + 1) �� �� : %o, %d, %x \n\n", pa + 1, pa + 1, pa + 1);
	//printf("pc (double) �� �� : %o, %d, %x \n", pc, pc, pc);
	//printf("(pc + 1) �� �� : %o, %d, %x \n\n", pc + 1, pc + 1, pc + 1);

	return 0;
}
int Point_Array1()
{

	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int* parr;
	int i;
	parr = &arr[0];

	for (i = 0; i < 10; i++)
	{
		printf("arr[%d] �� �ּҰ� : %x ", i, &arr[i]);
		printf("(parr + %d) �� �� : %x ", i, (parr + i));

		if (&arr[i] == (parr + i))
		{
			/* ���� (parr + i) �� ���������� arr[i] �� ����Ų�ٸ� */
			printf(" --> ��ġ \n");
		}
		else
		{
			printf("--> ����ġ\n");
		}
	}
	return 0;
}
int Point_Array2()
{
	int arr[10] = { 100,99,98,97,96,95,94,93,92,91 };

	int* parr = arr;
	int sum = 0;

	while (parr - arr <= 9)
	{

		sum += (*parr);
		parr++;

	}
	printf("�� ���� ���� : int arr[10] = { 100,99,98,97,96,95,94,93,92,91 };");
	printf("�� ���� ���� ��� : %d \n", sum / 10);
	return 0;
}
int Point_Double()
{
	int a;
	int *pa;
	int **ppa;
	int ***pppa;

	pa = &a;
	ppa = &pa;
	pppa = &ppa;

	a = 3;
	printf("a = 3 �϶�\n");
	printf("  a : %7d // *pa : %7d // **ppa : %7d \n", a, *pa, **ppa);
	printf(" &a : %d //  pa : %d //  *ppa : %d \n", &a, pa, *ppa);
	printf("&pa : %d // ppa : %d \n\n", &pa, ppa);

	a = 5;
	printf("a = 5 �϶�\n");
	printf("  a : %7d // *pa : %7d // **ppa : %7d \n", a, *pa, **ppa);
	printf(" &a : %d //  pa : %d //  *ppa : %d \n", &a, pa, *ppa);
	printf("&pa : %d // ppa : %d \n\n", &pa, ppa);

	a = 7;
	printf("a = 7 �϶� (3�� ������)\n");
	printf("    a : %7d //  *pa : %7d // **ppa : %7d // ***pppa : %7d \n", a, *pa, **ppa, ***pppa);
	printf("   &a : %d //   pa : %d //  *ppa : %d //  **pppa : %d \n", &a, pa, *ppa, **pppa);
	printf("  &pa : %d //  ppa : %d // *pppa : %d \n", &pa, ppa, *pppa);
	printf(" &ppa : %d // pppa : %d \n", &ppa, pppa);
	printf("&pppa : %d \n\n", &pppa);

	printf("&a, pa, *ppa : a�� ���� ���Ե� �ּҴ� ����\n");
	printf("&pa, ppa : a�� ���� ���Ե� �ּҰ��� ���Ե� �ּҴ� ����\n");
	return 0;
}
int Point_Double_One_D_Array()
{
	int arr[5] = { 10, 20, 30, 40, 50 };
	int *parr = arr;


	printf("arr[0~5]�� �� �����ǰ� { 10, 20, 30, 40, 50 }\n");
	printf("arr[0]      = %d      : arr[0] ������ ��\n", arr[0]);
	printf("arr         = %x  : arr�� ����Ű�� �ּ�\n", arr);
	printf("*(arr)      = %d      : arr�� ����Ű�� �ּ��� ��\n", *(arr));
	printf("parr        = %x  : parr�� ����Ű�� �ּ�\n", parr);
	printf("*parr       = %d      : parr�� ����Ű�� �ּ��� ��\n", *parr);
	printf("(arr + 1)   = %x  : arr + 1�� ����Ű�� �ּ�\n", (arr + 1));
	printf("*(arr + 1)  = %d      : arr + 1�� ����Ű�� �ּ��� ��\n", *(arr + 1));
	printf("parr + 1    = %x  : parr + 1�� ����Ű�� �ּ�\n", parr + 1);
	printf("*(parr + 1) = %d      : parr + 1�� ����Ű�� �ּ��� ��\n", *(parr + 1));
	printf("*parr + 1   = %d      : parr�� ����Ű�� �ּ��� �� + 1\n\n", *parr + 1);
	printf("*parr++     = %d -> %d: parr�� ����Ű�� �ּ��� ���� ����ϰ� parr�� �ּҿ� + 1\n", *parr++, *parr);
	printf("*parr++     = %d -> %d: parr�� ����Ű�� �ּ��� ���� ����ϰ� parr�� �ּҿ� + 1\n\n*parr = 10;\n", *parr++, *parr);
	*parr = 10;
	printf("++*parr     = %d -> %d: parr�� ����Ű�� �ּ��� ���� +1�� �� ������ ���\n", ++*parr, *parr);
	printf("++*parr     = %d -> %d: parr�� ����Ű�� �ּ��� ���� +1�� �� ������ ���\n\n*parr = 10;\n", ++*parr, *parr);
	*parr = 10;
	printf("(*parr)++   = %d -> %d: parr�� ����Ű�� �ּ��� ���� ����ϰ� parr�� ����Ű�� �ּ��� ���� + 1\n", (*parr)++, *parr);
	printf("(*parr)++   = %d -> %d: parr�� ����Ű�� �ּ��� ���� ����ϰ� parr�� ����Ű�� �ּ��� ���� + 1\n\n*parr = 10;\n", (*parr)++, *parr);
	*parr = 10;
	printf("++(*parr)   = %d -> %d: parr�� ����Ű�� �ּ��� ���� +1�� �� ������ ���\n", ++(*parr), *parr);
	printf("++(*parr)   = %d -> %d: parr�� ����Ű�� �ּ��� ���� +1�� �� ������ ���\n\n", ++(*parr), *parr);

	return 0;
}
int Point_Two_D_Array()
{
	int arr[2][3] = { { 1,2,3 },{ 4,5,6 } };


	printf("2�� �迭 : int arr[2][3] = { { 1,2,3 },{ 4,5,6 } };\n\n");
	printf("arr = (arr[0][0]) : %x\narr + 1 = (arr[1][0]) : %x \n\n", arr, arr + 1);
	printf("*arr = (arr[0][0]) : %x\n*(arr + 1) = (arr[1][0]) : %x �ּҾȿ� �� �б� �Ұ�\n\n", *arr, *(arr + 1));

	int(*parr)[3];  // ��ȣ�� �� ���̼���
	parr = arr; // parr �� arr �� ����Ű�� �Ѵ�. 

	printf("int(*parr)[3]\nparr = arr\n");
	printf("parr[1][2] : %d \narr[1][2] : %d  �ּҾȿ� �� �б� ����\n\n", parr[1][2], arr[1][2]);
	printf("2�� �迭�� int **parr; �� ���Ұ� int(*parr)[3]; �� ��ü b���� ���ƾ���\n\n");


	return 0;

}
int Point_Three_D_Array()
{
	printf("\n\n===========================\n\n");
	int arr[3][3] = { { 1,3,5 },{ 7,9,11 },{ 13,15,17 } };
	printf("�迭 : int array[2][3] = { { 1,3,5 },{ 7,9,11 } };\n");
	printf("������ �޸�ũ�� = %2d\n", sizeof(arr[0][0]));
	printf("���� �޸�ũ��   = %2d\n", sizeof(arr[0]));
	printf("�迭�� �޸�ũ�� = %2d\n", sizeof(arr));
	printf("\n===========================\n\n");
	printf("arr[0][0]     : %2d\n", arr[0][0]);
	printf("*arr[0]       : %2d\n", *arr[0]);
	printf("**arr         : %2d\n", **arr);
	printf("arr[0][1]     : %2d\n", arr[0][1]);
	printf("*(arr[0] + 1) : %2d\n", *(arr[0] + 1));
	printf("*(*arr + 1)   : %2d\n", *(*arr + 1));
	printf("\n===========================\n\n");
	printf("*(*(arr+2)+1) = arr[2][1] : %2d\n", *(*(arr + 2) + 1));
	printf("\n===========================\n\n");
	int arr2[2][3][4] = {
		{ { 1,3,5,7 },
	{ 9,11,13,15 },
	{ 17,19,21,23 }
		},
	{ { 25,27,29,31 },
	{ 33,35,37,39 },
	{ 41,43,45,48 }
	}
	};
	printf("3�� �迭 : 	int arr2[2][3][4]  = \n{{{ 1,3,5,7 },\n{ 9,11,13,15 },\n{ 17,19,21,23}},\n{{25,27,29,31},\n{33,35,37,39},\n{41,43,45,48} } };\n\n");
	printf("***arr2                    = %d\n", ***arr2);
	printf("*(*(*(arr2 + 1) + 1) + 1)  = %d\n", *(*(*(arr2 + 1) + 1) + 1));
	printf("arr[1][1][1]               = %2d\n", arr2[1][1][1]);

	printf("*(*(*(arr2 + 1) + 2) + 3)  = %d\n", *(*(*(arr2 + 1) + 2) + 3));
	printf("arr[1][2][3]               = %d\n", arr2[1][2][3]);
	printf("\n===========================\n\n");


	arr2[1][2][3] = 10;
	printf("arr2[1][2][3] = 10;\n\n");
	printf("*(*(*(arr2 + 1) + 2) + 3)  = %d\n", *(*(*(arr2 + 1) + 2) + 3));
	//int (*parr2)[3][4];
	//parr2 = arr2;
	//int(*(*pparr2))[4];
	//parr2 = arr2;
	//*pparr2 = arr2;

	int(*parr2)[3][4] = arr2;

	//int a;
	//int *pa;
	//int **ppa;
	//int ***pppa;
	//pa = &a;
	//ppa = &pa;
	//pppa = &ppa;
	//
	//a = 5;



	//printf("arr2[1][2][3] = 10;\n\n");
	//printf("*(*(*(arr2 + 1) + 2) + 3)  = %x\n", &arr2);
	//printf("*(*(*(arr2 + 1) + 2) + 3)  = %x\n", &arr2[1][2][3]);
	//printf("*(*(*(arr2 + 1) + 2) + 3)  = %x\n", arr2 + 1);
	//printf("*(*(*(arr2 + 1) + 2) + 3)  = %x\n", arr2 + 2);
	//printf("*(*(*(arr2 + 1) + 2) + 3)  = %x\n", arr2 + 1);
	printf("*(parr2 + 1);                = %x\n", *(parr2 + 1));
	printf("*(*(parr2 + 1) + 2);         = %x\n", *(*(parr2 + 1) + 2));
	printf("*(*(*(parr2 + 1) + 2) + 3);  = %d\n", *(*(*(parr2 + 1) + 2) + 3));

	printf("*(arr2 + 1);                 = %x\n", *(arr2 + 1));
	printf("*(*(arr2 + 1) + 2);          = %x\n", *(*(arr2 + 1) + 2));
	printf("*(*(*(arr2 + 1) + 2) + 3);   = %d\n", *(*(*(arr2 + 1) + 2) + 3));

	printf("\n3�� �迭�� int ***parr; �� ���Ұ� int(*parr)[3][4]; �� ��ü b���� c���� ���ƾ���\n\n");

	return 0;
}
int Point_Summary()
{

	int *parr[3];
	int a = 1, b = 2, c = 3;
	parr[0] = &a;
	parr[1] = &b;
	parr[2] = &c;
	printf("	int *parr[3];\n");
	printf("	int a = 1, b = 2, c = 3;\n");
	printf("	parr[0] = &a;\n");
	printf("	parr[1] = &b;\n");
	printf("	parr[2] = &c;\n");
	printf("\n");

	printf("a : %d, *parr[0] : %d \n", a, *parr[0]);
	printf("b : %d, *parr[1] : %d \n", b, *parr[1]);
	printf("c : %d, *parr[2] : %d \n", c, *parr[2]);
	printf("a,b,c �� ���� *parr[n] �ּ��� ���� ����\n\n");

	printf("&a      : %x      &b : %x      &c : %x\n", &a, &b, &c);
	printf("parr[0] : %x parr[1] : %x parr[2] : %x\n", parr[0], parr[1], parr[2]);
	printf("a,b,c�� �ּҰ� parr[n] �ּҿ� ����\n\n");
	return 0;
}
int Point_Void()
{
	int arr[5] = { 10, 20, 30, 40, 50 };
	int *parr = arr;
	int *parr1;
	int i;
	char ch[5];
	void *vparr = arr;
	printf("\n\n===========================\n\n");
	printf("int arr[5] = { 10, 20, 30, 40, 50 };\n\
int *parr = arr;\n\
int *parr1;\n\
int i;\n\
char ch[5];\n\
void *vparr = arr;");
	printf("\n\n===========================\n\n");
	printf("1) ��� �������� �ּҸ� ����ų �� �ֽ��ϴ�\n\
2) *�����ڸ� �� �� �����ϴ�.\n\
3) ���� �����ڸ� ����� �� �����ϴ�.");
	printf("\n\n===========================\n\n");


	printf("parr�� ���� �ּ� : %d\n", parr);
	printf("vparr�� ���� �ּ� : %d\n", vparr);
	printf("parr�� ����Ű�� �� : %d\n", *parr);
	//    printf("vparr�� ����Ű�� �� : %d\n", *vparr);                // error : vparr�� *(point)�� ����� �� ����. 



	printf("parr + 1 �� ����Ű�� �� %d\n", *(parr + 1));
	//    printf("vparr + 1 �� ����Ű�� �� %d\n", *(vparr + 1));    // error : vparr�� *(point)�� ����� �� ����. 



	parr1 = (int *)vparr;
	printf("parr1�� ����Ű�� �� : %d\n", *parr1);



	memset(ch, '*', sizeof(ch));
	printf("ch�� �� : %s\n", ch);
	memset(arr, '*', sizeof(arr));
	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
		printf("%d\t", arr[i]);



	return 0;
}

//Function
#pragma region Change val
int Func_B_Cng_Val(int *pi, int *cng_v)
{
	printf("\n----- Function_Basic_Change_Val �Լ� �ȿ��� -----\n\n");
	printf("pi �� �� : %d \n", pi);
	printf("pi �� ����Ű�� ���� �� : %d \n\n", *pi);

	*pi = *cng_v;
	printf("pi �� ���� %d���� ����\n\n", *cng_v);

	printf("pi �� �� : %d \n", pi);
	printf("pi �� ����Ű�� ���� �� : %d \n", *pi);

	printf("\n----- Function_Basic_Change_Val �Լ� ��~~ -----\n\n");
	return 0;
}
int Function_Basic_Change_Val()
{
	int i = 2;
	int cng_v;
	printf("i ������ �ּҰ� : %d \n", &i);
	printf("ȣ�� ���� i �� �� : %d \n\n", i);
	printf("���ϴ� ���氪 : ");
	scanf_s("%d", &cng_v);
	Func_B_Cng_Val(&i, &cng_v);
	printf("ȣ�� ���� i �� �� : %d \n", i);

	return 0;
}
#pragma endregion
#pragma region Swap val
int Func_B_Swap_Val(int *swap_a, int *swap_b)
{
	int Cash_data = *swap_a;
	*swap_a = *swap_b;
	*swap_b = Cash_data;
	return 0;
}
int Function_Basic_Swap_Val()
{
	int swap_a;
	int swap_b;
	printf("��ȯ�� ���ϴ� ���� a : ");
	scanf_s("%d", &swap_a);
	printf("��ȯ�� ���ϴ� ���� b : ");
	scanf_s("%d", &swap_b);
	Func_B_Swap_Val(&swap_a, &swap_b);
	printf("��ȯ ���� a �� �� : %d \n", swap_a);
	printf("��ȯ ���� b �� �� : %d \n", swap_b);
	return 0;
}
#pragma endregion
#pragma region Find Max Val
int Func_Find_Max_Val(int *parr);
int Function_Find_Max_Val()
{
	int arr_max[10];
	unsigned int i;
	for (i = 0; i < 10; i++)
	{
		scanf_s("%d", &arr_max[i]);
	}
	printf("�Է��� �迭 �� ���� ū �� : %d \n", Func_Find_Max_Val(arr_max));
	return 0;

}
int Func_Find_Max_Val(int *parr_max)
{
	int i;
	int max = parr_max[0];

	for (i = 1; i < 10; i++)
	{
		if (parr_max[i] > max)
		{
			max = parr_max[i];
		}
	}
	return max;
}

#pragma endregion
#pragma region Swap_Pointer
int Func_Swap_P(int **pa, int **pb);
int Function_Swap_Pointer()
{
	int a = 5;
	int b = 10;
	int *pa, *pb;

	pa = &a;
	pb = &b;

	printf("a : %d \n", a);
	printf("b : %d \n", b);
	printf("pa �� ����Ű�� ���� a�� �� : %d \n", *pa);
	printf("pa �� ����Ű�� ���� a�� �ּҰ� : %x \n", pa);
	printf("pa �� ���� �ּҰ� : %x \n \n", &pa);
	printf("pa �� ����Ű�� ���� b�� �� : %d \n", *pb);
	printf("pb �� ����Ű�� ���� b�� �ּҰ� : %x \n", pb);
	printf("pb �� ���� �ּҰ� : %x \n", &pb);

	printf(" ------------- ȣ�� -------------- \n");
	Func_Swap_P(&pa, &pb);
	printf(" ------------- ȣ�ⳡ -------------- \n");

	printf("a : %d \n", a);
	printf("b : %d \n", b);
	printf("pa �� ����Ű�� ���� a�� �� : %d \n", *pa);
	printf("pa �� ����Ű�� ������ �ּҰ� : %x \n", pa);
	printf("pa �� ���� �ּҰ� : %x \n \n", &pa);
	printf("pa �� ����Ű�� ���� b�� �� : %d \n", *pb);
	printf("pb �� ����Ű�� ������ �ּҰ� : %x \n", pb);
	printf("pb �� ���� �ּҰ� : %x \n", &pb);

	printf("\na,b,pa,pb �� �ּҰ��� ����Ұ�\n pa,pb�� ����Ű�� ������ �ּҰ��� ���� ����\n\n");
	return 0;

}
int Func_Swap_P(int **ppa, int **ppb)
{
	int *temp = *ppa;

	printf("ppa �� ����Ű�� ������ �ּҰ� : %x \n", ppa);
	printf("ppb �� ����Ű�� ������ �ּҰ� : %x \n", ppb);

	*ppa = *ppb;
	*ppb = temp;

	return 0;
}



#pragma endregion
#pragma region Increase_Element_Two_Array
int Func_Inc_Ele_Two_Arr(int(*arr)[2], int row, int val);
int Function_Increase_Element_Two_Array()
{
	int arr[3][2];
	int i, j, n;
	printf("���ϴ� ������ �� : ");
	scanf_s("%d", &n);
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 2; j++)
		{
			scanf_s("%d", &arr[i][j]);
		}
	}

	Func_Inc_Ele_Two_Arr(arr, 3, n);

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 2; j++)
		{
			printf("arr[%d][%d] : %d \n", i + 1, j + 1, arr[i][j]);
		}
	}
	return 0;

}
int Func_Inc_Ele_Two_Arr(int(*arr)[2], int row, int val)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < 2; j++)
		{
			(arr[i][j] += val);
		}
	}

	return 0;
}

#pragma endregion
#pragma region Pointer_Function
int Func_Point_Max(int a, int b);
int Func_point_Non(int c, int k);
int Function_Pointer()
{
	int a, b;
	int(*pfunc)(int, int);
	pfunc = Func_Point_Max;

	printf("�� ��� �Է� : ");
	scanf_s("%d %d", &a, &b);
	printf("\nFunc_Point_Max(a,b) : %d \n", Func_Point_Max(a, b));
	printf("pfunc(a,b)          : %d \n\n", pfunc(a, b));

	pfunc = Func_point_Non;

	printf("Func_point_Non(1,1) : %d \n", Func_point_Non(1, 1));
	printf("pfunc(1,1)          : %d \n", pfunc(1, 1));
	return 0;
}
int Func_Point_Max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;

	return 0;
}
int Func_point_Non(int c, int k)
{
	return 1;
}

#pragma endregion





#pragma region Zombie

#pragma endregion
#pragma region Zombie

#pragma endregion
#pragma region Zombie

#pragma endregion
#pragma region Zombie
#include <iostream>  
using namespace std;
int test()
{


	//int a, b;
	//int *pa, *pb;
	//int **ppa, **ppb;

	//pa = &a;
	//pb = &b;

	//ppa = &pa;
	//ppb = &pb;

	//a = 35;
	//b = 55;

	//printf("%06x %06x %06x %d\n", ppa, pa, a, a);
	//printf("%06x %06x %06x %d\n", ppb, pb, b, b);
	//int temp;
	//temp = *pb;
	//*pb = *pa;
	//*pa = temp;
	//printf("%06x %06x %06x %d\n", ppa, pa, a, a);
	//printf("%06x %06x %06x %d\n", ppb, pb, b, b);

	//int *temp2;
	//temp2 = *ppb;
	//*ppb = *ppa;
	//*ppa = temp2;
	//printf("%06x %06x %06x %d\n", ppa, pa, a, a);
	//printf("%06x %06x %06x %d\n", ppb, pb, b, b);

	int arr[10];
	int i;

	for (i = 0; i < 10; i++)
	{
		scanf_s("%d", &arr[i]);
	}
	for (i = 0; i <= 10; i++)
	{
		printf("%d \n", arr[i]);
	}
	return 0;

}

#pragma endregion




