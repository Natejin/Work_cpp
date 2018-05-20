#include<stdio.h>
#include<math.h> // math 헤더 파일
#define PH 3.1415926535 //매크로 정의 파이값
void sin_degree(int i, int x, double si); // 함수원형 정의
int main(void) //main 함수
{
	int i = 0; // 각도를 저장할 변수
	double si = 0; // 사인값이 저장될 변수
	int x = 0; // 그래프를 만들기위한 변수
	sin_degree(i, x, si); // 함수호출
}
void sin_degree(int i, int x, double si) // sin_degree 함수 정의
{
	for (i = 0; i <= 360; i += 20) { //20도 단위로 출력
		si = sin((PH*i) / 180.0); //변환식
		printf("sin(%3d)의 값은 %+f", i, si); //각도와 sin값 출력
		for (x = -15; x < si * 10; x++) { // 그래프 공백 생성
			printf(" ");
		}
		printf("*\n"); // * 출력후 라인 변경
	}
}