


#include <stdio.h>


struct msgTemp1
{
    char a;
    char b;
    int index;
};

typedef struct msgTemp2
{
    char a;
    char b;
    int index;
}msgTemp;




int main(int argc, char** argv)
{
    struct msgTemp1 msg1[5];
    struct msgTemp2 msg2[5];
    msgTemp msg[5];
    for(int i=0; i<5; i++)
    {
        msg[i].index = i;
        msg[i].a = 10+i;
        msg[i].b = 20+i; 
    }


    return 0;
}
