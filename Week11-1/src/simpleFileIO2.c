// Program that does simple file I/O
// and takes one argument (file name)
#include <stdio.h>

main(int argc, char* argv[]) {
	
	if(argc < 2) {
		printf("No filename specified!");
		return;
	}
	
	// create a string variable
	char text[100];
	char text2[100];

	// Filestream pointer (file handle)
	FILE *writeFile;
	writeFile = fopen(argv[1],"a");
	// Elicit user input
	printf("Please enter a message: ");
	scanf("%s",&text);
	// Write the data to the file
	fprintf(writeFile, "%s", &text);
	// close the file handle
	fclose(writeFile);

	FILE *readFile;
	readFile = fopen(argv[1], "r");
	while(!feof(readFile)) {
		fscanf(readFile, "%s", &text2);
		printf("%s", text2);
	}
	fclose(readFile);
}

