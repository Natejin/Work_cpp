#include <stdio.h>
#include <string.h>
#include "My_Pointer.h"

int My_Pointer()
{
	unsigned int Index;
Initiate_Program:
	printf("\n\n____________________________________________________________________________\n");
	printf("1: 포인터 기본 \n");
	printf("2: 상수 포인터 \n");
	printf("3: 포인터 계산 \n");
	printf("4: 포인터 배열 1\n");
	printf("5: 포인터 배열 2\n");
	printf("6: 더블 포인터 \n");
	printf("7: 더블 포인터 1차 배열 \n");
	printf("8: 포인터 2차 배열 \n");
	printf("9: 포인터 3차 배열 \n");
	printf("10: 포인터 정리 \n");
	printf("11: void 포인터 \n");
	printf("\n____________________________________________________________________________\n");
	printf("\nInput value : ");
	scanf_s("%d", &Index);
	printf("\n____________________________________________________________________________\n\n");
	switch (Index)
	{
	case(1):
		Pointer_Basic();
		goto Initiate_Program;
		break;
	case(2):
		Pointer_Const();
		goto Initiate_Program;
		break;
	case(3):
		Pointer_Cal();
		goto Initiate_Program;
		break;
	case(4):
		Pointer_Array1();
		goto Initiate_Program;
		break;
	case(5):
		Pointer_Array2();
		goto Initiate_Program;
		break;
	case(6):
		Pointer_Double();
		goto Initiate_Program;
		break;
	case(7):
		Pointer_Double_One_D_Array();
		goto Initiate_Program;
		break;
	case(8):
		Pointer_Two_D_Array();
		goto Initiate_Program;
		break;
	case(9):
		Pointer_Three_D_Array();
		goto Initiate_Program;
		break;
	case(10):
		Pointer_Summary();
		goto Initiate_Program;
		break;
	case(11):
		Pointer_Void();
		goto Initiate_Program;
		break;

	default:
		printf("무슨 명령인지 못 알아 듣겠어. 왈왈 \n");
		main();
		break;
	}
	return 0;
}

//Pointer
int Pointer_Basic()
{
	unsigned int *p;
	unsigned int a;

	p = &a;

	printf("포인터 p 에 들어 있는 값 : %p \n", p);
	printf("int 변수 a 가 저장된 주소 : %p \n", &a);

	a = 2;

	printf("a 의 값 : %d \n", a);
	printf("*p 의 값 : %d \n", *p);

	*p = 3;
	printf("a 의 값 : %d \n", a);
	printf("*p 의 값 : %d \n", *p);

	return 0;
}
int Pointer_Const()
{

	const unsigned int a = 5;
	const unsigned int *p = &a;

	printf("const unsigned int *p=&a; p 주소의 값을 고정 (*p=val 사용불가)\n");
	printf("unsigned int *const p=&a; p 주소를 고정 (p=address 사용불가)\n");

	printf("a 의 값 : %d \n", a);
	printf("*p 의 값 : %d \n", *p);
	printf("포인터 p 에 들어 있는 값 : %p \n", p);
	printf("int 변수 a 가 저장된 주소 : %p \n", &a);


	return 0;
}
int Pointer_Cal()
{
	int a;
	short int d;
	char b;
	double c;
	int* pa = &a;
	char* pb = &b;
	double* pc = &c;
	short int *pd = &d;


	//printf("pb (char) 의 값 : %o, %d, %x \n", pb,pb,pb);
	//printf("(pb + 1) 의 값 : %o, %d, %x \n\n", pb + 1, pb + 1, pb + 1);
	//printf("pa (short int) 의 값 : %o, %d, %x \n", pd, pd, pd);
	//printf("(pd + 1) 의 값 : %o, %d, %x \n\n", pd + 1, pd + 1, pd + 1);
	//printf("pa (int) 의 값 : %o, %d, %x \n", pa, pa,pa);
	//printf("(pa + 1) 의 값 : %o, %d, %x \n\n", pa + 1, pa + 1, pa + 1);
	//printf("pc (double) 의 값 : %o, %d, %x \n", pc, pc, pc);
	//printf("(pc + 1) 의 값 : %o, %d, %x \n\n", pc + 1, pc + 1, pc + 1);

	return 0;
}
int Pointer_Array1()
{

	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int* parr;
	int i;
	parr = &arr[0];

	for (i = 0; i < 10; i++)
	{
		printf("arr[%d] 의 주소값 : %x ", i, &arr[i]);
		printf("(parr + %d) 의 값 : %x ", i, (parr + i));

		if (&arr[i] == (parr + i))
		{
			/* 만일 (parr + i) 가 성공적으로 arr[i] 를 가리킨다면 */
			printf(" --> 일치 \n");
		}
		else
		{
			printf("--> 불일치\n");
		}
	}
	return 0;
}
int Pointer_Array2()
{
	int arr[10] = { 100,99,98,97,96,95,94,93,92,91 };

	int* parr = arr;
	int sum = 0;

	while (parr - arr <= 9)
	{

		sum += (*parr);
		parr++;

	}
	printf("내 시험 점수 : int arr[10] = { 100,99,98,97,96,95,94,93,92,91 };");
	printf("내 시험 점수 평균 : %d \n", sum / 10);
	return 0;
}
int Pointer_Double()
{
	int a;
	int *pa;
	int **ppa;
	int ***pppa;

	pa = &a;
	ppa = &pa;
	pppa = &ppa;

	a = 3;
	printf("a = 3 일때\n");
	printf("  a : %7d // *pa : %7d // **ppa : %7d \n", a, *pa, **ppa);
	printf(" &a : %d //  pa : %d //  *ppa : %d \n", &a, pa, *ppa);
	printf("&pa : %d // ppa : %d \n\n", &pa, ppa);

	a = 5;
	printf("a = 5 일때\n");
	printf("  a : %7d // *pa : %7d // **ppa : %7d \n", a, *pa, **ppa);
	printf(" &a : %d //  pa : %d //  *ppa : %d \n", &a, pa, *ppa);
	printf("&pa : %d // ppa : %d \n\n", &pa, ppa);

	a = 7;
	printf("a = 7 일때 (3중 포인터)\n");
	printf("    a : %7d //  *pa : %7d // **ppa : %7d // ***pppa : %7d \n", a, *pa, **ppa, ***pppa);
	printf("   &a : %d //   pa : %d //  *ppa : %d //  **pppa : %d \n", &a, pa, *ppa, **pppa);
	printf("  &pa : %d //  ppa : %d // *pppa : %d \n", &pa, ppa, *pppa);
	printf(" &ppa : %d // pppa : %d \n", &ppa, pppa);
	printf("&pppa : %d \n\n", &pppa);

	printf("&a, pa, *ppa : a의 값이 포함된 주소는 고정\n");
	printf("&pa, ppa : a의 값이 포함된 주소값이 포함된 주소는 고정\n");
	return 0;
}
int Pointer_Double_One_D_Array()
{
	int arr[5] = { 10, 20, 30, 40, 50 };
	int *parr = arr;


	printf("arr[0~5]의 각 원소의값 { 10, 20, 30, 40, 50 }\n");
	printf("arr[0]      = %d      : arr[0] 원소의 값\n", arr[0]);
	printf("arr         = %x  : arr이 가리키는 주소\n", arr);
	printf("*(arr)      = %d      : arr이 가리키는 주소의 값\n", *(arr));
	printf("parr        = %x  : parr이 가리키는 주소\n", parr);
	printf("*parr       = %d      : parr가 가리키는 주소의 값\n", *parr);
	printf("(arr + 1)   = %x  : arr + 1이 가리키는 주소\n", (arr + 1));
	printf("*(arr + 1)  = %d      : arr + 1이 가리키는 주소의 값\n", *(arr + 1));
	printf("parr + 1    = %x  : parr + 1이 가리키는 주소\n", parr + 1);
	printf("*(parr + 1) = %d      : parr + 1이 가리키는 주소의 값\n", *(parr + 1));
	printf("*parr + 1   = %d      : parr가 가리키는 주소의 값 + 1\n\n", *parr + 1);
	printf("*parr++     = %d -> %d: parr가 가리키는 주소의 값을 출력하고 parr의 주소에 + 1\n", *parr++, *parr);
	printf("*parr++     = %d -> %d: parr가 가리키는 주소의 값을 출력하고 parr의 주소에 + 1\n\n*parr = 10;\n", *parr++, *parr);
	*parr = 10;
	printf("++*parr     = %d -> %d: parr가 가리키는 주소의 값에 +1을 한 다음에 출력\n", ++*parr, *parr);
	printf("++*parr     = %d -> %d: parr가 가리키는 주소의 값에 +1을 한 다음에 출력\n\n*parr = 10;\n", ++*parr, *parr);
	*parr = 10;
	printf("(*parr)++   = %d -> %d: parr가 가리키는 주소의 값을 출력하고 parr가 가리키는 주소의 값에 + 1\n", (*parr)++, *parr);
	printf("(*parr)++   = %d -> %d: parr가 가리키는 주소의 값을 출력하고 parr가 가리키는 주소의 값에 + 1\n\n*parr = 10;\n", (*parr)++, *parr);
	*parr = 10;
	printf("++(*parr)   = %d -> %d: parr가 가리키는 주소의 값에 +1을 한 다음에 출력\n", ++(*parr), *parr);
	printf("++(*parr)   = %d -> %d: parr가 가리키는 주소의 값에 +1을 한 다음에 출력\n\n", ++(*parr), *parr);

	return 0;
}
int Pointer_Two_D_Array()
{
	int arr[2][3] = { { 1,2,3 },{ 4,5,6 } };


	printf("2차 배열 : int arr[2][3] = { { 1,2,3 },{ 4,5,6 } };\n\n");
	printf("arr = (arr[0][0]) : %x\narr + 1 = (arr[1][0]) : %x \n\n", arr, arr + 1);
	printf("*arr = (arr[0][0]) : %x\n*(arr + 1) = (arr[1][0]) : %x 주소안에 값 읽기 불가\n\n", *arr, *(arr + 1));

	int(*parr)[3];  // 괄호를 꼭 붙이세요
	parr = arr; // parr 이 arr 을 가리키게 한다. 

	printf("int(*parr)[3]\nparr = arr\n");
	printf("parr[1][2] : %d \narr[1][2] : %d  주소안에 값 읽기 가능\n\n", parr[1][2], arr[1][2]);
	printf("2차 배열시 int **parr; 은 사용불가 int(*parr)[3]; 로 대체 b값은 같아야함\n\n");


	return 0;

}
int Pointer_Three_D_Array()
{
	printf("\n\n===========================\n\n");
	int arr[3][3] = { { 1,3,5 },{ 7,9,11 },{ 13,15,17 } };
	printf("배열 : int array[2][3] = { { 1,3,5 },{ 7,9,11 } };\n");
	printf("원소의 메모리크기 = %2d\n", sizeof(arr[0][0]));
	printf("행의 메모리크기   = %2d\n", sizeof(arr[0]));
	printf("배열의 메모리크기 = %2d\n", sizeof(arr));
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
	printf("3차 배열 : 	int arr2[2][3][4]  = \n{{{ 1,3,5,7 },\n{ 9,11,13,15 },\n{ 17,19,21,23}},\n{{25,27,29,31},\n{33,35,37,39},\n{41,43,45,48} } };\n\n");
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

	printf("\n3차 배열시 int ***parr; 은 사용불가 int(*parr)[3][4]; 로 대체 b값과 c값은 같아야함\n\n");

	return 0;
}
int Pointer_Summary()
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
	printf("a,b,c 의 값이 *parr[n] 주소의 값과 동일\n\n");

	printf("&a      : %x      &b : %x      &c : %x\n", &a, &b, &c);
	printf("parr[0] : %x parr[1] : %x parr[2] : %x\n", parr[0], parr[1], parr[2]);
	printf("a,b,c의 주소가 parr[n] 주소와 동일\n\n");
	return 0;
}
int Pointer_Void()
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
	printf("1) 모든 데이터의 주소를 가리킬 수 있습니다\n\
2) *연산자를 쓸 수 없습니다.\n\
3) 증감 연산자를 사용할 수 없습니다.");
	printf("\n\n===========================\n\n");


	printf("parr가 가진 주소 : %d\n", parr);
	printf("vparr가 가진 주소 : %d\n", vparr);
	printf("parr가 가리키는 값 : %d\n", *parr);
	//    printf("vparr가 가리키는 값 : %d\n", *vparr);                // error : vparr는 *(point)를 사용할 수 없다. 



	printf("parr + 1 이 가리키는 값 %d\n", *(parr + 1));
	//    printf("vparr + 1 이 가리키는 값 %d\n", *(vparr + 1));    // error : vparr는 *(point)를 사용할 수 없다. 



	parr1 = (int *)vparr;
	printf("parr1가 가리키는 값 : %d\n", *parr1);



	memset(ch, '*', sizeof(ch));
	printf("ch의 값 : %s\n", ch);
	memset(arr, '*', sizeof(arr));
	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
		printf("%d\t", arr[i]);



	return 0;
}


//# Prerequisites
//*.d
//
//# Compiled Object files
//*.slo
//*.lo
//*.o
//*.obj
//
//# Precompiled Headers
//*.gch
//*.pch
//
//# Compiled Dynamic libraries
//*.so
//*.dylib
//*.dll
//
//# Fortran module files
//*.mod
//*.smod
//
//# Compiled Static libraries
//*.lai
//*.la
//*.a
//*.lib
//
//# Executables
//*.exe
//*.out
//*.app