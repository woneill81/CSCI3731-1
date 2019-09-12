#include <cstdio>
#include "swap.h"

int main(int argc, char** argv) {
	
	int num1 = 0;
	int num2 = 0;
	
	printf("Enter number 1:\n");
	scanf("%d", &num1);
	
	printf("Enter number 2\n");
	scanf("%d", &num2);
	
	swap(&num1, &num2);
	
	printf("Number 1: %d\n", num1);
	printf("Number 2: %d\n", num2);
}