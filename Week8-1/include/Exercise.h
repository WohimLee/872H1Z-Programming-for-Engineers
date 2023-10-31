#ifndef EXERCISE_H
#define EXERCISE_H

#include <stdio.h>
#include <math.h>

void exercise1()
{
    const int NUM = 100;
    int array[NUM];
    int i=0;
    while(i < NUM)
    {
        array[i] = i;
        printf("assign %d to array[%d]\n", i, i);
        i++;
    }

    float sum = 0;
    for(i=0; i<NUM; i++)
    {
        if(i%2==0)
        {
            sum += array[i];
            printf("i: %d, Add %d, sum=%f\n", i, array[i], sum);
            if(sum > 1000)
            {
                printf("sum = %f, array[%d]=%d\n", sum, i, array[i]);
                break;
            }
        }
    }
}


#define NUM 50
void exercise2()
{
    long unsigned int fibonacci[NUM] = {1, 1, 0};

    for(int i = 2; i < NUM; i++)
    {
        fibonacci[i] = fibonacci[i-1]+fibonacci[i-2];
        printf("fn=%ld, fn-1=%ld, fn-2=%ld\n", 
               fibonacci[i], fibonacci[i-1], fibonacci[i-2]);
    }

    for(int i=0; i < NUM; i++)
    {
        if(i%5==0 && i > 0)
            printf("\n");
        printf("%12ld ", fibonacci[i]);       
    }
    printf("\n");
}


int factorial(int x)
{
    int res=1;
    if(x == 0)
        return 0;
    else if (x > 0)
    {
        for(int i=1; i<=x; i++)
            res *= i;
    }
    else{
        printf("Negatives don't have a factorial\n");
        return -1;
    }
    
    return res;
}

float root(float x)
{
    return sqrt(x);
}

float exercise3()
{
    int operand, choice;

    printf("Please enter the integer operand x: ");
    scanf("%d", &operand);

    printf("Choose one of the following operation(Enter 1 or 2):\n"
           "    1. Computing the factorial of x;\n"
           "    2. Computing the square root of x.\n");
    scanf("%d", &choice);
    
    int res=1;
    switch(choice){
        case 1:
            printf("The factorial of %d is res = %d\n", operand, factorial(operand));
            break;
        case 2: 
            printf("The square root of %d is res = %f\n", operand, root(operand));
            break;
        default:
            printf("You should only enter 1 or 2\n");
            break;
    }
}

#endif // EXERCISE_H