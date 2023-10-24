#include <stdio.h>

int main(){
	long i,n=0;
	double res = 0;
	int fib[40]={1,1,0};
	double div[40]={0};
	
	for(i=0;i<40;i++){
    	fib[i+2] = fib[i+1]+fib[i];
		div[i] = (double)fib[i]/fib[i+1];  		
	}
	printf("The Fibonnacci numbers [0-49] are:\n");
	for(i=0;i<40;i++){
		if(i%5==0&&(i!=0))
		  printf("\n%-13d ",fib[i]);		  
		else
		  printf("%-13d ",fib[i]);  
	}
	printf("\n\n");
	printf("The Fibonnacci fib[n]/fin[n+1] numbers are(golden section):\n");
	for(i=0;i<40;i++){
		if(i%5==0&&(i!=0))
		  printf("\n%-13.3lf ",div[i]);		  
		else
		  printf("%-13.3lf ",div[i]);  
	}
	
	
	getchar();
	return 0;
	
}
