#ifndef EXERCISE_H
#define EXERCISE_H

#include <stdio.h>

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

#endif // EXERCISE_H