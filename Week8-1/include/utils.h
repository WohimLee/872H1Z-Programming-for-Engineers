#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <math.h>


#define NUM 50


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



#endif // UTILS_H