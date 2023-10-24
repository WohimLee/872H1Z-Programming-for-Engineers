// Program that does simple file I/O
#include <stdio.h>

main() {
	// create a string variable
	char text[100];
	char text2[100];

	// Filestream pointer (file handle)
	FILE *writeFile;
	writeFile = fopen("hello.txt","w");
	// Elicit user input
	printf("Please enter a message: ");
	scanf("%s",&text);
	// Write the data to the file
	fprintf(writeFile, "%s", &text);
	// close the file handle
	fclose(writeFile);

	FILE *readFile;
	readFile = fopen("hello.txt", "r");
	while(!feof(readFile)) {
		fscanf(readFile, "%s", &text2);
		printf("%s", text2);
	}
	fclose(readFile);
}

