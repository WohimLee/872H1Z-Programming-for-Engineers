#include <stdio.h>
// function prototype
void print();
// global vars
int numbers[5];

main() {
	//create a pointer to the first element of the array
	int *p; // pointer
	p = &numbers[0]; 
	// add five elements to the array
	int i; // control var for the loop
	int n; // var to store the value to go into the array
	for (i=0; i<5 ;i++) {
		// elicit input
		printf("Enter a number: ");
		scanf("%d",&n);
		// add to array
		*p = n; // overwrite the value at the address stored in p
		p++; // pointer arithmetic - point to the next position in the array
	}
	print();
}
void print() { // print contents of the array
	int i;
	for (i=0; i<5; i++) {
		printf("numbers[%d] -> value: %d\n", i, numbers[i]); // print out values
	}
}
