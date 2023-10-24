#include <stdio.h>

main() {
    
    int numbers[5] = { 0 }; // create an array
    int length = sizeof(numbers) / sizeof(int); // compute array length
    
    printf("This array of integers occupies %d bytes of memory", sizeof(numbers)); 
    printf("\n\nA single integer occupies %d bytes of memory", sizeof(int)); 
    printf("\n\nTherefore size of the current array is: %d", length); 
    
    getchar();
    return 0;
}
