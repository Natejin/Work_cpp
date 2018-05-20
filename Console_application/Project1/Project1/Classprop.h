#pragma once

#define MAX_NAME_LEN    20
typedef struct _Class Class;
struct _Class
{
	char name[MAX_NAME_LEN + 1];//이름
	int num; //번호
	int hp; //체력
	int iq; //지력
	int stress; //스트레스
	int scnt; //연속으로 공부한 횟수
};
enum _ClassConst
{
	MIN_HP = 0, MAX_HP = 100, DEF_HP = 100,
	MIN_IQ = 0, MAX_IQ = 200, DEF_IQ = 100,
	MIN_STRESS = 0, MAX_STRESS = 100, DEF_STRESS = 0,
	MIN_SCNT = 0, MAX_SCNT = 5, DEF_SCNT = 0
};

void Class_Class(Class *CLASS, const char *name); //생성자
void Class_Study(Class *CLASS);//공부하다.
void Class_ListenLecture(Class *CLASS);//강의받다.
void Class_Relax(Class *CLASS);//휴식하다.
void Class_Sleep(Class *CLASS);//잠자다.
void Class_Drink(Class *CLASS);//음료를 마시다.
void Class_Sing(Class *CLASS);//노래하다.
void Class_View(Class *CLASS);//자신의 정보를 출력하다.