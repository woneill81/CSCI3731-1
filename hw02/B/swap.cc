#include "swap.h"

void swap(int* a, int* b){

	int num1 = 0;
	int num2 = 0;
	
	//dereference for contents
	num1 = *a;
	num2 = *b;
	
	//swap the numbers
	*a = num2;
	*b = num1;
}