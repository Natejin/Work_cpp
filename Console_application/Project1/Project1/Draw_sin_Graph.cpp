#include<stdio.h>
#include<math.h> // math ��� ����
#define PH 3.1415926535 //��ũ�� ���� ���̰�
void sin_degree(int i, int x, double si); // �Լ����� ����
int main(void) //main �Լ�
{
	int i = 0; // ������ ������ ����
	double si = 0; // ���ΰ��� ����� ����
	int x = 0; // �׷����� ��������� ����
	sin_degree(i, x, si); // �Լ�ȣ��
}
void sin_degree(int i, int x, double si) // sin_degree �Լ� ����
{
	for (i = 0; i <= 360; i += 20) { //20�� ������ ���
		si = sin((PH*i) / 180.0); //��ȯ��
		printf("sin(%3d)�� ���� %+f", i, si); //������ sin�� ���
		for (x = -15; x < si * 10; x++) { // �׷��� ���� ����
			printf(" ");
		}
		printf("*\n"); // * ����� ���� ����
	}
}