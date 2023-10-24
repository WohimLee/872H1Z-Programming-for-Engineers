#include <stdio.h>
 
int a; 
 
int main () {
  
  test();
  printf ("The value of global a is %d\n", a);
  getchar();
  return 0;
}

int test() {
    int a = 20; 
    printf ("The value of local a is %d\n", a);    
}

