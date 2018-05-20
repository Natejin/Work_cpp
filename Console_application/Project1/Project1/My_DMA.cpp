#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "My_DMA.h"

void My_DMA()
{
	unsigned int Index;
Initiate_Program:
	printf("\n\n____________________________________________________________________________\n");
	printf("1: Dynamic Memory alloication (Basic) \n");
	printf("2: Dynamic Memory alloication (1st Array) \n");
	printf("3: Dynamic Memory alloication (2st Array) \n");
	printf("4: Dynamic Memory alloication (Struct) \n");
	//printf("5: Linker List \n");
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
		DMA_Basic();
		goto Initiate_Program;
		break;
	case(2):
		DMA_1arr_exam();
		goto Initiate_Program;
		break;
	case(3):
		DMA_2arr_exam();
		goto Initiate_Program;
		break;
	case(4):
		DMA_struct();
		goto Initiate_Program;
		break;
	case(5):
		Memory_function();
		goto Initiate_Program;
		break;
	//case(6):
	//	Linker_List();
	//	goto Initiate_Program;
	//	break;
	default:
		printf("���� ������� �� �˾� ��ھ�. �п� \n");
		main();
		break;
	}
}


#pragma region Dynamic_Memory_Alloication

void DMA_Basic()
{
	int SizeOfArray;
	int *arr;

	printf("����� ���� �迭�� ������ �� : ");
	scanf_s("%d", &SizeOfArray);

	arr = (int *)malloc(sizeof(int) * SizeOfArray);
	// int arr[SizeOfArray] �� ������ �۾��� �� ũ���� �迭 ���� 

	free(arr);



}

#pragma endregion

#pragma region Dynamic_Memory_Alloicatio_1st_array_example
void DMA_1arr_exam()
{
	int student1,student2; // �Է� �ް��� �ϴ� �л� �� 
	int input_m,input_n;
	int Max_student;
	int *class1; // �л� ���� �������� ���� 
	int *class2;
	int sum1 = 0;
	int	sum2 = 0; // ���� 

	printf("1�� �л��� ����? : ");
	scanf_s("%d", &student1);
	printf("2�� �л��� ����? : ");
	scanf_s("%d", &student2);

	class1 = (int *)malloc(student1 * sizeof(int));
	class2 = (int *)malloc(sizeof(int)*student2);

	if (student1 <= student2) Max_student = student2;
	else Max_student = student1;

	for (int i = 0; i<=Max_student; i++)
	{
		if (i+1 <= student1)
		{
			printf("\n1���� �л� %d �� ���� : ", i + 1);
			scanf_s("%d", &input_m);
			class1[i] = input_m;
			sum1 += class1[i];
		}
		if (i+1 <= student2)
		{
			printf("\n2���� �л� %d �� ���� : ", i + 1);
			scanf_s("%d", &input_n);
			class2[i] = input_n;
			sum2 += class2[i];
		}
	}
	printf("1���� �л� ��� ���� : %d \n", sum1 / student1);
	printf("2���� �л� ��� ���� : %d \n", sum2 / student2);
	free(class1);
}
#pragma endregion

#pragma region Dynamic_Memory_Alloicatio_2st_array_example
void get_average(int **arr, int numStudent, int numSubject);
void DMA_2arr_exam()
{
	int i, j, input, sum = 0;
	int subject, students;
	int **arr;
	// �츮�� arr[subject][students] �迭�� ���� ���̴�. 

	printf("���� �� : ");
	scanf_s("%d", &subject);

	printf("�л��� �� : ");
	scanf_s("%d", &students);

	arr = (int **)malloc(sizeof(int *) * subject);

	for (i = 0; i<subject; i++)
	{
		arr[i] = (int *)malloc(sizeof(int) * students);
	}

	for (i = 0; i<subject; i++)
	{
		printf("���� %d ���� --------- \n", i);

		for (j = 0; j<students; j++)
		{
			printf("�л� %d ���� �Է� : ", j);
			scanf_s("%d", &input);

			arr[i][j] = input;
		}
	}

	get_average(arr, students, subject);

	for (i = 0; i<subject; i++)
	{
		free(arr[i]);
	}
	free(arr);
}
void get_average(int **arr, int numStudent, int numSubject)
{
	int i, j, sum;

	for (i = 0; i<numSubject; i++)
	{
		sum = 0;
		for (j = 0; j<numStudent; j++)
		{
			sum += arr[i][j];
		}
		printf("���� %d ��� ���� : %d \n", i, sum / numStudent);
	}
}

#pragma endregion

#pragma region Dynamic_Memory_Alloication_struct
struct Character
{
   int classes, races;
};
void DMA_struct()
{
	struct Character *arr_char;
	int size, i;

	printf("���Ͻô� ����ü �迭�� ũ�� : ");
	scanf_s("%d", &size);

	arr_char = (struct Character *)malloc(sizeof(struct Character) * size);

	for (i = 0; i<size; i++)
	{
		printf("player[%d].classes : ", i+1);
		scanf_s("%d", &arr_char[i].classes);
		printf("player[%d].races : ", i+1);
		scanf_s("%d", &arr_char[i].races);
	}

	for (i = 0; i<size; i++)
	{
		printf("player[%d].a : %d , player[%d].b : %d \n", i+1, arr_char[i].classes, i+1, arr_char[i].races);
	}

	free(arr_char);

}

#pragma endregion

#pragma region Memory function 

void Memory_function()
{
	char str[50] = "I love Chewing C hahaha";
	char str2[50];
	char str3[50];

	memcpy(str2, str, strlen(str) + 1);
	memcpy(str3, "hello", 6);

	printf("%s \n", str);
	printf("%s \n", str2);
	printf("%s \n", str3);


	char str4[50] = "I love Chewing C hahaha";

	printf("%s \n", str4);
	printf("memmove ���� \n");
	memmove(str4 + 23, str4 + 17, 6);
	printf("%s", str4);


	int arr[10] = { 1,2,3,4,5 };
	int arr2[10] = { 1,2,3,4,5 };

	if (memcmp(arr, arr2, 5) == 0)
		printf("arr �� arr2 �� ��ġ! \n");
	else
		printf("arr �� arr2 �� ��ġ ���� \n");

}

#pragma endregion

