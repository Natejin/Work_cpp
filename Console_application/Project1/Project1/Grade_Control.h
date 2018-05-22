

#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <string.h> 

#define MAX_STUDENT 10//최대 학생 수
#define MAX_NLEN    20 //최대 이름 길이
#define MAX_SUBJECT 3 //과목 수

typedef struct {//학생 구조체 정의
	char name[MAX_NLEN + 1];//이름
	int num; //번호
	int scores[MAX_SUBJECT];//국,영,수 성적
}Student;

void Initialize();		//학생 데이터 초기화
void Run();				//실행	
//void Control_Grade();	//메인
//
int SelectMenu();//메뉴 출력 및 선택
void AddStudent();//학생 데이터 입력
void RemoveStudent();//학생 데이터 삭제
void FindStudent();//학생 검색
void ListStudent();//목록 보기
//
int IsAvailNum(int num);	//유효한 번호인지 판별
int IsAvailScore(int score);	//유효한 성적인지 판별
void Control_Grade();