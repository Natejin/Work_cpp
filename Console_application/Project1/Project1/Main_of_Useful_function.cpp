#include "Main_of_Useful_function.h"
#include "Grade_Control.h"
#include <stdio.h>


void Main_Useful_function()
{
	unsigned int Index;
Initiate_Program:
	printf("\n\n____________________________________________________________________________\n");
	printf("1: �л� ���� ���� ���α׷� \n");
	//printf("2: ��� ������ \n");
	//printf("3: ������ ��� \n");
	//printf("4: ������ �迭 1\n");
	//printf("5: ������ �迭 2\n");
	//printf("6: ���� ������ \n");
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
		Control_Grade();
		goto Initiate_Program;
		break;
	//case(2):
	//	Pointer_Const();
	//	goto Initiate_Program;
	//	break;
	//case(3):
	//	Pointer_Cal();
	//	goto Initiate_Program;
	//	break;
	//case(4):
	//	Pointer_Array1();
	//	goto Initiate_Program;
	//	break;
	//case(5):
	//	Pointer_Array2();
	//	goto Initiate_Program;
	//	break;
	//case(6):
	//	Pointer_Double();
	//	goto Initiate_Program;
	//	break;
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