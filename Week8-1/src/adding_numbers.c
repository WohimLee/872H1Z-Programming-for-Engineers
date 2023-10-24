#include <stdio.h>

main() {

int i;
int numbers[5] = { 0 };
printf("Please enter five integers\n\n"); 

for(i = 0; i <=4; i++)  // for-loop, allows i to be between 0 and 4
{
    if(i == 2)
         continue;
    printf("Number %d: ", i+1); // add 1 for sensible output
    scanf("%d", &numbers[i]);
}

int k = 0, result = 0;
int length = sizeof(numbers) / sizeof(int); // compute array length

while( k < length) // k must be strictly less than length (maxIndex+1==length)
{
    printf("\nI'm adding %d to %d", numbers[k], result); 
    result += numbers[k];  // same as result=result+numbers[k]
    printf(" which gives %d.", result); 
    k++;
    break;
}
printf("\n\nThe sum of all numbers is: %d", result); 


getchar();
getchar();
return 0;
}
