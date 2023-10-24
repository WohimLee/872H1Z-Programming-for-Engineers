#include<stdio.h>
#include<stdlib.h>

main() {
	// allocate memory for two integers (like an array)
	int *p1 = (int *)malloc(sizeof(int)*2);
	int *p2;
	// put 11 in the first element
	*p1 = 11;
	// increment the pointer var and store 22 in the secon element
	*(p1+1) = 22;
	// increase my memory allocation with a new pointer p2 and reserve 3*int
	p2 = (int *)realloc(p1,sizeof(int)*3);
	// move 2 locations from the beginning of p1/p2
	*(p2+2) = 33;
	int i;
	// loop through the array of integers
	for(i=0;i <3; i++)
		printf("%d ",*(p2+i)); // print the value at address p2+index
}
