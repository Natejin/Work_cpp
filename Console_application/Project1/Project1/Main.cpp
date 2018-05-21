#include <stdio.h>
//#include <stdlib.h>
//#include <conio.h>		   //_getch
#include <string.h>       // memset 
#include "My_Array.h" 
#include "My_String.h"
#include "My_Struct.h"
#include "My_DMA.h"
#include "My_Linked_lists.h"
#include "My_Pointer.h"

#pragma warning( disable : 4477)
#pragma warning( disable : 4473)		// scanf_s not enough arguments passed for format string
//#pragma warning( disable : 4996)		//scanf_s
#pragma warning( disable : 4313)



int Function();
int test();



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
		My_Pointer();
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
		printf("무슨 명령인지 못 알아 듣겠어. 왈왈 \n");
		goto Initiate_Program;
		break;
	}


}



int Function()
{
	unsigned int Index;
Initiate_Program:
	printf("\n\n____________________________________________________________________________\n");
	printf("1: 함수 기본 (원하는 값으로 변경) \n");
	printf("2: 함수 기본 (값 바꾸기) \n");
	printf("3: 입력한 값중 최고값 출력 \n");
	printf("4: 두 상수의 포인터 바꾸기 \n");
	printf("5: 배열에 입력수 만큼 증가 \n");
	printf("6: 포인터 함수 \n");
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
		printf("무슨 명령인지 못 알아 듣겠어. 왈왈 \n");
		main();
		break;
	}
	return 0;
}




//Function
#pragma region Change val
int Func_B_Cng_Val(int *pi, int *cng_v)
{
	printf("\n----- Function_Basic_Change_Val 함수 안에서 -----\n\n");
	printf("pi 의 값 : %d \n", pi);
	printf("pi 가 가리키는 것의 값 : %d \n\n", *pi);

	*pi = *cng_v;
	printf("pi 의 값을 %d으로 변경\n\n", *cng_v);

	printf("pi 의 값 : %d \n", pi);
	printf("pi 가 가리키는 것의 값 : %d \n", *pi);

	printf("\n----- Function_Basic_Change_Val 함수 끝~~ -----\n\n");
	return 0;
}
int Function_Basic_Change_Val()
{
	int i = 2;
	int cng_v;
	printf("i 변수의 주소값 : %d \n", &i);
	printf("호출 이전 i 의 값 : %d \n\n", i);
	printf("원하는 변경값 : ");
	scanf_s("%d", &cng_v);
	Func_B_Cng_Val(&i, &cng_v);
	printf("호출 이후 i 의 값 : %d \n", i);

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
	printf("교환을 원하는 변수 a : ");
	scanf_s("%d", &swap_a);
	printf("교환을 원하는 변수 b : ");
	scanf_s("%d", &swap_b);
	Func_B_Swap_Val(&swap_a, &swap_b);
	printf("교환 이후 a 의 값 : %d \n", swap_a);
	printf("교환 이후 b 의 값 : %d \n", swap_b);
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
	printf("입력한 배열 중 가장 큰 수 : %d \n", Func_Find_Max_Val(arr_max));
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
	printf("pa 가 가리키는 변수 a의 값 : %d \n", *pa);
	printf("pa 가 가리키는 변수 a의 주소값 : %x \n", pa);
	printf("pa 의 실제 주소값 : %x \n \n", &pa);
	printf("pa 가 가리키는 변수 b의 값 : %d \n", *pb);
	printf("pb 가 가리키는 변수 b의 주소값 : %x \n", pb);
	printf("pb 의 실제 주소값 : %x \n", &pb);

	printf(" ------------- 호출 -------------- \n");
	Func_Swap_P(&pa, &pb);
	printf(" ------------- 호출끝 -------------- \n");

	printf("a : %d \n", a);
	printf("b : %d \n", b);
	printf("pa 가 가리키는 변수 a의 값 : %d \n", *pa);
	printf("pa 가 가리키는 변수의 주소값 : %x \n", pa);
	printf("pa 의 실제 주소값 : %x \n \n", &pa);
	printf("pa 가 가리키는 변수 b의 값 : %d \n", *pb);
	printf("pb 가 가리키는 변수의 주소값 : %x \n", pb);
	printf("pb 의 실제 주소값 : %x \n", &pb);

	printf("\na,b,pa,pb 의 주소값은 변경불가\n pa,pb가 가르키는 변수의 주소값은 변경 가능\n\n");
	return 0;

}
int Func_Swap_P(int **ppa, int **ppb)
{
	int *temp = *ppa;

	printf("ppa 가 가리키는 변수의 주소값 : %x \n", ppa);
	printf("ppb 가 가리키는 변수의 주소값 : %x \n", ppb);

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
	printf("원하는 숫자의 값 : ");
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

	printf("두 상수 입력 : ");
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




