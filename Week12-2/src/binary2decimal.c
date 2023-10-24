// A program that converts binary into decimal
#include <stdio.h>

main() {
	// variables
	int b;  		// a binary number, stored as an integer
	int ls; 		// id of the least significant bit
	int dec;  		// decimal value of the current bit
	
	while(b != -1) {
		int exponent = 0; // the exponent to start with, e.g. 2^0 is our first computation
		int result = 0;		// the end result
		// elicit input
		printf("Please enter a binary number (or -1 to quit): ");
		scanf("%d", &b);
		// process number as long as there are any 1's left
		while(b > 0) {
			// get the least significant bit of b
			// a binary number, when considered as a decimal number, can be divided by 10 
			// to leave the value of the least-significant (right-most) bit as a remainder
			// b%10 will yield the remainder of the integer division by 10, which is 
			// identical to the value of the least-significant bit
			// e.g., 101101 / 10 will yield a remainder of 1
			// e.g., 101000 / 10 will yield a remainder of 0
			ls = b % 10;
			// compute the power of two with the current exponent
			dec = pow(2,exponent);
			// we only add to result if the bit was "switched on", i.e. 1
			if(ls)
				result += dec; // result = result + dec
			// trim the current least significant bit (integer division by 10)
			b = b/10;
			// increment exponent by 1
			exponent++;

		}
	// output result
	if(b != -1)
		printf("In decimal, that is: %d.\n", result);
	}	
	return;
} 
