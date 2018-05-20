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
		printf("무슨 명령인지 못 알아 듣겠어. 왈왈 \n");
		main();
		break;
	}
}


#pragma region Dynamic_Memory_Alloication

void DMA_Basic()
{
	int SizeOfArray;
	int *arr;

	printf("만들고 싶은 배열의 원소의 수 : ");
	scanf_s("%d", &SizeOfArray);

	arr = (int *)malloc(sizeof(int) * SizeOfArray);
	// int arr[SizeOfArray] 와 동일한 작업을 한 크기의 배열 생성 

	free(arr);



}

#pragma endregion

#pragma region Dynamic_Memory_Alloicatio_1st_array_example
void DMA_1arr_exam()
{
	int student1,student2; // 입력 받고자 하는 학생 수 
	int input_m,input_n;
	int Max_student;
	int *class1; // 학생 들의 수학점수 변수 
	int *class2;
	int sum1 = 0;
	int	sum2 = 0; // 총점 

	printf("1반 학생의 수는? : ");
	scanf_s("%d", &student1);
	printf("2반 학생의 수는? : ");
	scanf_s("%d", &student2);

	class1 = (int *)malloc(student1 * sizeof(int));
	class2 = (int *)malloc(sizeof(int)*student2);

	if (student1 <= student2) Max_student = student2;
	else Max_student = student1;

	for (int i = 0; i<=Max_student; i++)
	{
		if (i+1 <= student1)
		{
			printf("\n1반의 학생 %d 의 점수 : ", i + 1);
			scanf_s("%d", &input_m);
			class1[i] = input_m;
			sum1 += class1[i];
		}
		if (i+1 <= student2)
		{
			printf("\n2반의 학생 %d 의 점수 : ", i + 1);
			scanf_s("%d", &input_n);
			class2[i] = input_n;
			sum2 += class2[i];
		}
	}
	printf("1반의 학생 평균 점수 : %d \n", sum1 / student1);
	printf("2반의 학생 평균 점수 : %d \n", sum2 / student2);
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
	// 우리는 arr[subject][students] 배열을 만들 것이다. 

	printf("과목 수 : ");
	scanf_s("%d", &subject);

	printf("학생의 수 : ");
	scanf_s("%d", &students);

	arr = (int **)malloc(sizeof(int *) * subject);

	for (i = 0; i<subject; i++)
	{
		arr[i] = (int *)malloc(sizeof(int) * students);
	}

	for (i = 0; i<subject; i++)
	{
		printf("과목 %d 점수 --------- \n", i);

		for (j = 0; j<students; j++)
		{
			printf("학생 %d 점수 입력 : ", j);
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
		printf("과목 %d 평균 점수 : %d \n", i, sum / numStudent);
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

	printf("원하시는 구조체 배열의 크기 : ");
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
	printf("memmove 이후 \n");
	memmove(str4 + 23, str4 + 17, 6);
	printf("%s", str4);


	int arr[10] = { 1,2,3,4,5 };
	int arr2[10] = { 1,2,3,4,5 };

	if (memcmp(arr, arr2, 5) == 0)
		printf("arr 과 arr2 는 일치! \n");
	else
		printf("arr 과 arr2 는 일치 안함 \n");

}

#pragma endregion

