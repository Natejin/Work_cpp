#include "Classprop.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <memory.h>


void Class_SetHP(Class *CLASS, int hp);
void Class_SetIQ(Class *CLASS, int iq);
void Class_SetStress(Class *CLASS, int stress);
void Class_IncreSCnt(Class *CLASS);
void Class_Class(Class *CLASS, const char *name)
{
	/*학생은 생성할 때 순차적으로 번호를 부여하세요.
		이를 위해 정적 변수로 가장 최근에 부여한 학생 번호를 기억하는 변수를 선언하세요.*/
	static int last_num;
	/*입력 인자로 전달받은 학생의 메모리를 초기화가 필요하죠.*/
	memset(CLASS, 0, sizeof(Class));

	/*그리고 입력 인자로 전달받은 이름을 설정하세요.*/
	strncpy_s(CLASS->name, sizeof(CLASS->name), name, MAX_NAME_LEN);
	/*나머지 멤버들도 초기값으로 설정하세요.*/
	CLASS->hp = DEF_HP;
	CLASS->iq = DEF_IQ;
	CLASS->stress = DEF_STRESS;
	CLASS->scnt = DEF_SCNT;
	/*가장 최근에 부여한 학생 번호를 1 증가한 후에 학생 번호를 설정하세요.*/
	last_num++;
	CLASS->num = last_num;
}

//학생이 공부하면 체력이 5 소모하며 지력은 연속으로 공부한 횟수만큼 증가하고 스트레스는 2 감소한다.
void Class_Study(Class *CLASS)
{
	/*먼저 누가 공부하는지 콘솔 화면에 출력하세요*/
	printf("<%d>:%s 공부하다.\n", CLASS->num, CLASS->name);
	/*그리고 시나리오에 나온 것처럼 학생의 능력치를 변경하세요.*/
		//학생이 공부하면 체력이 5 소모하며 지력은 연속으로 공부한 횟수만큼 증가하고 스트레스는 2 감소한다.
		/*주의할 점은 능력치가 최대값과 최소값의 범위를 벗어나지 않게 제어하세요.
		이러한 부분은 다른 기능에서도 공통적으로 수행해야 하므로 각 능력치를 설정하는 함수를 별도로 제공하여 구현하면 좋아요.*/
	Class_SetHP(CLASS, CLASS->hp - 5);
	Class_SetIQ(CLASS, CLASS->iq + CLASS->scnt);
	Class_SetStress(CLASS, CLASS->stress - 2);
	Class_IncreSCnt(CLASS);
}
//학생이 강의를 받으면 체력은 3 소모하며 지력은 연속으로 공부한 횟수만큼 증가하고 스트레스는 2 증가한다.
void Class_ListenLecture(Class *CLASS)
{
	printf("<%d>:%s 강의받다. \n", CLASS->num, CLASS->name);
	//학생이 강의를 받으면 체력은 3 소모하며 지력은 연속으로 공부한 횟수만큼 증가하고 스트레스는 2 증가한다.
	Class_SetHP(CLASS, CLASS->hp - 3);
	Class_SetIQ(CLASS, CLASS->iq + CLASS->scnt);
	Class_SetStress(CLASS, CLASS->stress + 2);
	CLASS->scnt = 0;
}
//학생이 휴식하면 체력은 3회복하고 스트레스는 10 감소한다.
void Class_Relax(Class *CLASS)
{
	printf("<%d>:%s 휴식하다. \n", CLASS->num, CLASS->name);
	//학생이 휴식하면 체력은 3회복하고 스트레스는 10 감소한다.
	Class_SetHP(CLASS, CLASS->hp + 3);
	Class_SetStress(CLASS, CLASS->stress - 10);
	CLASS->scnt = 0;
}
//학생이 잠을 자면 체력은 10 회복하고 스트레스는 5 감소한다.
void Class_Sleep(Class *CLASS)
{
	printf("<%d>:%s 잠을자다. \n", CLASS->num, CLASS->name);
	//학생이 잠을 자면 체력은 10 회복하고 스트레스는 5 감소한다.
	Class_SetHP(CLASS, CLASS->hp + 10);
	Class_SetStress(CLASS, CLASS->stress - 5);
	CLASS->scnt = 0;
}
//학생이 음료를 마시면 체력이 10 소모하며 지력은 5 감소하고 스트레스는 2 감소한다.
void Class_Drink(Class *CLASS)
{
	printf("<%d>:%s 음료를 마시다. \n", CLASS->num, CLASS->name);
	//학생이 음료를 마시면 체력이 10 소모하며 지력은 5 감소하고 스트레스는 2 감소한다.
	Class_SetHP(CLASS, CLASS->hp - 10);
	Class_SetIQ(CLASS, CLASS->iq - 5);
	Class_SetStress(CLASS, CLASS->stress - 2);
	CLASS->scnt = 0;
}
//학생이 노래하면 체력이 10 소모하며 지력은 1 증가하고 스트레스는 5 감소한다.
void Class_Sing(Class *CLASS)
{
	printf("<%d>:%s 노래하다. \n", CLASS->num, CLASS->name);
	// 학생이 노래하면 체력이 10 소모하며 지력은 1 증가하고 스트레스는 5 감소한다.
	Class_SetHP(CLASS, CLASS->hp - 10);
	Class_SetIQ(CLASS, CLASS->iq + 1);
	Class_SetStress(CLASS, CLASS->stress - 5);
	CLASS->scnt = 0;
}
//추가로 학생 정보를 출력하는 기능을 제공한다.
void Class_View(Class *CLASS)
{
	//학생 번호와 이름은 중요한 데이터이므로 먼저 출력하는 것이 좋겠죠.
	printf("<%d>:%s\n", CLASS ->num, CLASS -> name);
	//그리고 나머지 능력치를 출력하세요.
	//굳이 연속으로 공부한 횟수는 출력할 필요가 없겠죠.
	//모든 데이터를 최종 사용자에게 알려줄 필요는 없어요.
	printf("\t 체력:%d 아이큐:%d 스트레스:%d\n", CLASS ->hp, CLASS -> iq, CLASS -> stress);
}

void Class_SetHP(Class *CLASS, int hp)
{
	/*입력 인자로 전달받은 값이 최대값을 벗어나면 최대값으로 수정하세요*/
	if (hp > MAX_HP)
	{
		hp = MAX_HP;
	}
	/*마찬가지로 최소값을 벗어나면 최소값으로 수정해야겠죠.*/
	if (hp < MIN_HP)
	{
		hp = MIN_HP;
	}
	/*이제 수정한 값으로 학생의 hp를 설정하세요.*/
	CLASS->hp = hp;
}
void Class_SetIQ(Class *CLASS, int iq)
{
	if (iq > MAX_IQ)
	{
		iq = MAX_IQ;
	}
	if (iq < MIN_IQ)
	{
		iq = MIN_IQ;
	}
	CLASS->iq = iq;
}
void Class_SetStress(Class *CLASS, int stress)
{
	if (stress > MAX_STRESS)
	{
		stress = MAX_STRESS;
	}
	if (stress < MIN_STRESS)
	{
		stress = MIN_STRESS;
	}
	CLASS->stress = stress;
}
void Class_IncreSCnt(Class *CLASS)
{
	/*학생의 scnt 값이 최대값보다 작을 때만 1 증가하게 하세요.*/
	if (CLASS->scnt < MAX_SCNT)
	{
		CLASS->scnt++;
	}
}