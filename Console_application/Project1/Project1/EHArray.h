#pragma once
typedef struct _EHArray EHArray;
typedef void * Element;
typedef Element * Iterator;

struct _EHArray
{
	Element *base; //저장소의 위치 정보
	int capacity;     //현재 저장소의 크기
	int size;           //현재 보관한 요소 개수
};

EHArray *EHArray_New(int init_capa, Element init_value); //동적으로 배열 생성
void EHArray_Delete(EHArray *eharr); //배열 소멸
int EHArray_GetCapacity(EHArray *eharr); //저장소의 크기 가져오기
int EHArray_GetSize(EHArray *eharr);       //보관한 요소 개수 가져오기
void EHArray_PushBack(EHArray *eharr, Element data); //순차적으로 자료 보관
Element EHArray_GetAt(EHArray *eharr, int index); //보관한 요소 가져오기
void EHArray_SetAt(EHArray *eharr, int index, Element data); //보관한 요소 설정하기
Iterator EHArray_Begin(EHArray *eharr); //저장소의 시작 위치
Iterator EHArray_End(EHArray *eharr); //저장소의 마지막 위치(보관할 위치)
void EHArray_Erase(EHArray *eharr, Iterator it);//보관한 요소 제거하기