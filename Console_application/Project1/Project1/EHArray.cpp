#include "EHArray.h"
#include <stdlib.h>

void EHArray_EHArray(EHArray *eharr, int init_capa, Element init_value);
void EHArray_Reserve(EHArray *eharr, int capacity);
void EHArray_PushBacks(EHArray *eharr, int n, Element value);
void EHArray_TEHArray(EHArray *eharr);

EHArray *EHArray_New(int init_capa, Element init_value)
{
	EHArray *eharr = (EHArray *)malloc(sizeof(EHArray));
	EHArray_EHArray(eharr, init_capa, init_value);
	return eharr;
}

void EHArray_EHArray(EHArray *eharr, int init_capa, Element init_value)	//생성
{
	eharr->base = 0;
	eharr->capacity = 0;
	eharr->size = 0;
	if (init_capa>0)
	{
		EHArray_Reserve(eharr, init_capa);
		EHArray_PushBacks(eharr, init_capa, init_value);
	}
}
void EHArray_Reserve(EHArray *eharr, int capacity)					//재배정
{
	eharr->base = (Element *)realloc(eharr->base, sizeof(Element)*capacity);
	eharr->capacity = capacity;
}
void EHArray_PushBacks(EHArray *eharr, int init_capa, Element value)		//
{
	int i = 0;
	for (i = 0; i<init_capa; i++)
	{
		EHArray_PushBack(eharr, value);
	}
}
void EHArray_Delete(EHArray *eharr)	//메모리 해제후 소멸
{
	EHArray_TEHArray(eharr);
	free(eharr);
}

void EHArray_TEHArray(EHArray *eharr)
{
	if (eharr->base)
	{
		free(eharr->base);
	}
}
int EHArray_GetCapacity(EHArray *eharr)
{
	return eharr->capacity;
}
int EHArray_GetSize(EHArray *eharr)
{
	return eharr->size;
}


void EHArray_PushBack(EHArray *eharr, Element data)
{
	if (eharr->capacity == eharr->size)
	{
		if (eharr->capacity)
		{
			EHArray_Reserve(eharr, eharr->capacity * 2);
		}
		else
		{
			EHArray_Reserve(eharr, 1);
		}
	}
	eharr->base[eharr->size] = data;
	eharr->size++;
}
Element EHArray_GetAt(EHArray *eharr, int index)
{
	if ((index >= 0) && (index<eharr->size))
	{
		return eharr->base[index];
	}
	return 0;
}
void EHArray_SetAt(EHArray *eharr, int index, Element data)
{
	if ((index >= 0) && (index<eharr->size))
	{
		eharr->base[index] = data;
	}
}
Iterator EHArray_Begin(EHArray *eharr)
{
	return eharr->base;
}
Iterator EHArray_End(EHArray *eharr)
{
	return eharr->base + eharr->size;
}
void EHArray_Erase(EHArray *eharr, Iterator it)
{
	Iterator end;
	eharr->size--;
	end = eharr->base + eharr->size;
	for (; it != end; it++)
	{
		(*it) = *(it + 1);
	}
}