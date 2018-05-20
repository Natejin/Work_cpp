#include "My_Array.h" 
#include <stdio.h>




int My_Array()
{
	unsigned int Index;
Initiate_Program:
	printf("\n\n____________________________________________________________________________\n");
	printf("1: 평균 구하기(배열)\n");
	printf("2: 소수 구하기(배열)\n");
	printf("3: 학생당 과목별점수(이차 배열)\n");
	printf("\n____________________________________________________________________________\n");
	printf("\nInput value : ");
	scanf_s("%d", &Index);
	printf("\n____________________________________________________________________________\n");
	switch (Index)
	{
	case(1):
		Example_average();
		goto Initiate_Program;
		break;
	case(2):
		Example_Find_Prime();
		goto Initiate_Program;
		break;
	case(3):
		Second_Dimension_Array();
		goto Initiate_Program;
		break;
	default:
		printf("무슨 명령인지 못 알아 듣겠어. 왈왈 \n");
		main();
		break;
	}
	return 0;
}

int Example_average()
{

	int arr[10]; // 성적을 저장하는 배열
	unsigned int i = 0;
	int ave = 0;


	for (i = 0; i < 10; i++)
	{
		printf("%d 번째 학생의 성적은? ", i + 1);
		scanf_s("%d", &arr[i]);
		ave = ave + arr[i];
	}
	ave = ave / 10;
	printf("전체 학생의 평균은 : %d \n", ave);
	for (i = 0; i < 10; i++)
	{
		printf("학생 %d : ", i + 1);
		if (arr[i] >= ave)
			printf("합격 \n");
		else
			printf("불합격 \n");
	}
	return 0;

}
int Example_Find_Prime()
{
	/* 우리가 소수인지 판별하고 있는 수 */
	int guess = 5;
	/* 소수의 배열 */
	int prime[1000];
	/*
	현재까지 찾은 (소수의 개수 - 1)
	아래 두 개의 소수를 미리 찾았으므로
	초기값은 1 이 된다.
	*/
	int index = 1;
	/* for 문 변수 */
	int i;
	/* 소수인지 판별위해 쓰이는 변수*/
	int ok;

	/* 처음 두 소수는 특별한 경우로 친다 */
	prime[0] = 2;
	prime[1] = 3;
	for (;;)
	{
		ok = 0;
		for (i = 0; i <= index; i++)
		{
			if (guess % prime[i] != 0)
			{
				ok++;
			}
			else
			{
				break;
			}
		}
		if (ok == (index + 1))
		{
			index++;
			prime[index] = guess;
			printf("소수 : %d \n", prime[index]);
			if (index == 999)
				break;
		}
		guess += 2;
	}
	return 0;
}
int Second_Dimension_Array()
{
	int score[3][2];
	int i, j;

	for (i = 0; i < 3; i++) // 총 3 명의 학생의 데이터를 받는다
	{
		for (j = 0; j < 2; j++)
		{
			if (j == 0)
			{
				printf("%d 번째 학생의 국어 점수 : ", i + 1);
				scanf_s("%d", &score[i][j]);
			}
			else if (j == 1)
			{
				printf("%d 번째 학생의 수학 점수 : ", i + 1);
				scanf_s("%d", &score[i][j]);
			}
		}
	}

	for (i = 0; i < 3; i++)
	{
		printf("%d 번째 학생의 국어 점수 : %d, 수학 점수 : %d \n", i + 1, score[i][0], score[i][1]);
	}

	return 0;
}