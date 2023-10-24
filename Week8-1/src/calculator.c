#include <stdio.h>
#include <math.h>

// function prototypes - to make sure the compiler "knows" these when they are used
// in our source code
long int factorial(int);
double squareroot(int);

// the main function will be run automatically when the program starts
void main() {
	// user input and menu choice
	int x,j;
	printf("Please enter a number: ");
	scanf("%d", &x);
	printf("\n\nPlease choose an operation:\n");
	printf("Press 1 to compute the factorial of %d\n", x);
	printf("Press 2 to compute the square root of %d\n", x);
	printf("Press 0 to quit\n");
	scanf("%d", &j);
	// function calls 
	if(j == 1) {
		printf("The factorial of %d is %d\n",x,factorial(x));		
	}
	else if (j == 2)
		printf("The square root of %d is %.2f",x,squareroot(x));
	else {
		printf("Goodbye");
	}
	getchar();
	return;		
}

// first mathematical operation
long int factorial(int a) {
	int i;
	long int r = a;
	for(i=a; i>1;i--) {
		//r = r * (i-1); --> the same as r *= i-1
		r*=i-1;
	}
	return r;
}
// second mathematical operation
double squareroot(int a) {
	// we need to "cast" a as a floating point number of double precision
	// because sqrt() requires a double as input parameter
	// casting: (type) identifier
	double r = sqrt((double)a);
}
