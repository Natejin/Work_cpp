#include <stdio.h>
#include "ComFunc.h"


int GetSumInBoundary(int start, int end) {
	int Sum=0;
	for (int i = start ; i <= end; i++) {
		Sum += i;
	}
	return Sum;
}


int IsPrime(int val) {
	for (int i = 2; i <= (val / 2); i++) {
		if (val%i == 0) {
			return 0;
		}		
	}
	return 1;
}

int GetCountIsPrime(int start, int end) {
	return 0;
}
int GetSum(int *base, int n) {
	return 0;
}
void Swap(int *a, int *b) {

}
int *GetMaxPos(int *base, int n) {
	return 0;
}
void SelectionSort(int *base, int n) {

}

int FindBig(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	return b;
}

