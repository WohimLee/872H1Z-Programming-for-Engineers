// BITWISE OPERATIONS
#include <stdio.h>

void main() {
	int x;
	printf("Please enter a number: ");
	scanf("%d", &x);
	print(x);
	
	// multiply by 8
	printf("\nMultiplying by 8...");
	x = x << 3;
	print(x);
	
	// divide by 2
	printf("\nDividing by 2...");
	x = x >> 1;
	print(x);
}

void print(int x) {
	// print out the current value of x
	printf("x is now %d\n", x);
}
