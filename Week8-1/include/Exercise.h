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


void exercise2()
{
    // Fibonacci
    const int NUM = 50;
    long unsigned int f0 = 0; // fn-2
    long unsigned int f1 = 1; // fn-1
    long unsigned int fn;
    long unsigned int fibonacci[NUM];
    fibonacci[0] = f0;
    fibonacci[1] = f1;

    for(int i = 2; i < NUM; i++)
    {
        fn = f0 + f1;
        fibonacci[i] = fn;
        printf("fn-1=%ld, fn-2=%ld, fn=%ld\n", f1, f0, fn);
        f0 = f1; f1 = fn;
    }

    for(int i=0; i < NUM; i++)
    {
        if(i%5==0 && i > 0)
            printf("\n");
        printf("%10ld ", fibonacci[i]);       
    }
    printf("\n");
}

#endif // EXERCISE_H