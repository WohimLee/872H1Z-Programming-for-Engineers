#include <stdio.h>
#include <string.h>

main() {
	// VARIABLES
	char string1[10] = "C is fun!";
	char string2[10] = "";
	int length, pointer1, pointer2;
	
	printf("String 1: %s\n", string1);
	printf("String 2: %s\n", string2);
	
	// PROCESSING
	// copy the contents of string1 to string2
	strcpy(string2, string1);
	//determine the length of string1
	length = strlen(string1);
	// find the first occurrence of a character in a string
	pointer1 = strchr(string1,'f');
	// find the first occurence of a string within a string
	pointer2 = strstr(string1,"fun");
	
	// OUTPUT
	printf("String 1: %s\n", string1);
	printf("String 2: %s\n", string2);
	printf("String1 is %d characters long.\n",length);
	printf("%s starts with an f\n",pointer1);
	printf("The sentence \"%s\" contains the substring \"%s\"\n",string1,pointer2);
		
}
