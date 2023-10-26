#ifndef EXERCISE_H
#define EXERCISE_H

#include <stdio.h>
#include <stdlib.h>


void exercise1()
/* Guess Number */
{
    const int target = 888;
    int input;
    int diff;
    
    while(
        printf("Please enter a number: "), 
        scanf("%d",&input), 
        input != target)
    {
        diff = abs(input - target);
        if(diff < 10)
            printf("Diff < 10. You almost there!\n");
        else if(diff < 50)
            printf("Diff < 50. It's quite close!\n");
        else if(diff < 100)
            printf("Diff < 100. You are getting close!\n");
        else if(diff < 500)
            printf("Diff < 500. Good job, keep trying!\n");
        else if(diff < 1000)
            printf("Diff < 1000. Way too far bro!\n");

    }
    printf("Congratulations! You hit the target: %d!\n", target);
}

void exercise2()
{
    int a, b;
    char op;
    float res;
    printf("Please enter two integers and a character(+,-,*,/): ");
    scanf("%d %c %d", &a, &op, &b);
    switch(op){
        case '+':
            res = a+b;
            break;
        case '-':
            res = a-b;
            break;
        case '*':
            res = a*b;
            break;
        case '/':
            res = a/b;
            break;
    }
    printf("%d %c %d = %.2f\n", a, op, b, res);
}


void exercise3()
/* 7-2 p54 */
{
    int arr[5];
    int i = 0;
    while(i<5)
    {
        printf("Enter the %d number(): ", i);
        scanf("%d", &arr[i]);
        i++;
    }

    int sum = 0;
    for(int i=0; i<5; i++)
        printf("Adding the %d nubmer: %d, result: %d\n", 
            i, arr[i], sum+=arr[i]);
}


#endif // EXERCISE_H