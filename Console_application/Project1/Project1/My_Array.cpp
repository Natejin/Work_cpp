#include "My_Array.h" 
#include <stdio.h>




int My_Array()
{
	unsigned int Index;
Initiate_Program:
	printf("\n\n____________________________________________________________________________\n");
	printf("1: ��� ���ϱ�(�迭)\n");
	printf("2: �Ҽ� ���ϱ�(�迭)\n");
	printf("3: �л��� ��������(���� �迭)\n");
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
		printf("���� ������� �� �˾� ��ھ�. �п� \n");
		main();
		break;
	}
	return 0;
}

int Example_average()
{

	int arr[10]; // ������ �����ϴ� �迭
	unsigned int i = 0;
	int ave = 0;


	for (i = 0; i < 10; i++)
	{
		printf("%d ��° �л��� ������? ", i + 1);
		scanf_s("%d", &arr[i]);
		ave = ave + arr[i];
	}
	ave = ave / 10;
	printf("��ü �л��� ����� : %d \n", ave);
	for (i = 0; i < 10; i++)
	{
		printf("�л� %d : ", i + 1);
		if (arr[i] >= ave)
			printf("�հ� \n");
		else
			printf("���հ� \n");
	}
	return 0;

}
int Example_Find_Prime()
{
	/* �츮�� �Ҽ����� �Ǻ��ϰ� �ִ� �� */
	int guess = 5;
	/* �Ҽ��� �迭 */
	int prime[1000];
	/*
	������� ã�� (�Ҽ��� ���� - 1)
	�Ʒ� �� ���� �Ҽ��� �̸� ã�����Ƿ�
	�ʱⰪ�� 1 �� �ȴ�.
	*/
	int index = 1;
	/* for �� ���� */
	int i;
	/* �Ҽ����� �Ǻ����� ���̴� ����*/
	int ok;

	/* ó�� �� �Ҽ��� Ư���� ���� ģ�� */
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
			printf("�Ҽ� : %d \n", prime[index]);
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

	for (i = 0; i < 3; i++) // �� 3 ���� �л��� �����͸� �޴´�
	{
		for (j = 0; j < 2; j++)
		{
			if (j == 0)
			{
				printf("%d ��° �л��� ���� ���� : ", i + 1);
				scanf_s("%d", &score[i][j]);
			}
			else if (j == 1)
			{
				printf("%d ��° �л��� ���� ���� : ", i + 1);
				scanf_s("%d", &score[i][j]);
			}
		}
	}

	for (i = 0; i < 3; i++)
	{
		printf("%d ��° �л��� ���� ���� : %d, ���� ���� : %d \n", i + 1, score[i][0], score[i][1]);
	}

	return 0;
}