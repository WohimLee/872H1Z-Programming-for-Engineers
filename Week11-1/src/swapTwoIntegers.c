// A program to swap two integer values

#include <stdio.h>
// function prototypes
void swapByValue(int, int);
void swapByReference(int*,int*);

int main() {
	int x = 5; // first int
	int y = 8; // second int
	int *p1;	// first pointer
	int *p2;	// second pointer
	p1 = &x;
	p2 = &y;
	
	printf("x is %d and y is %d", x, y);
	swapByValue(x,y);
	printf("\n\nSwapping by value, x is %d and y is %d", x, y);
	swapByReference(p1,p2);
	printf("\n\nSwapping by reference, x is %d and y is %d", x, y);
	return 0;
}
// THIS DOES NOT WORK!!!!
void swapByValue(int x, int y) {
	int temp = x; 	// save the value of x in temp
	x = y;			// assign y to x
	y = temp;		// assign the saved value of x to y
}
void swapByReference(int* x, int* y) {
	int temp = *x;	// save the value stored at the address of x in temp
	*x = *y;		// save the value at the adress of y at the address of x
	*y = temp;		// save the value stored in the integer variable temp at the address of y
}
