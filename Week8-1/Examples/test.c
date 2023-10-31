#include <stdio.h>
#include <math.h>

int main(){
int i,j;
char name[7][10]={"Ja","Sarah","Joe","Jammes","Sandy","Sonya","Philip"};
char answers[7][10] = {
	{'A', 'B', 'A', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
	{'D', 'B', 'A', 'B', 'C', 'A', 'E', 'E', 'A', 'D'},
	{'E', 'D', 'D', 'A', 'D', 'B', 'A', 'E', 'A', 'D'},
	{'A', 'C', 'B', 'A', 'C', 'B', 'E', 'D', 'A', 'D'},
	{'A', 'B', 'A', 'A', 'D', 'B', 'A', 'E', 'B', 'D'},
	{'D', 'C', 'A', 'A', 'D', 'A', 'E', 'E', 'A', 'C'},
	{'E', 'E', 'A', 'A', 'E', 'E', 'A', 'A', 'A', 'D'}}; 
	// Key to the questions
	char keys[10] = {'A', 'B', 'A', 'A', 'C', 'B', 'E', 'E', 'A', 'D'}; 
	//add your code here
	int score[9]={0};
	char grade[7];
	for(i=0;i<7;i++)
	{
		for(j=0;j<10;j++)
		{
			if(answers[i][j]==keys[j])
			{
				score[i]++;
			}
			else
				continue;	
				
		}
		
	}
	
	for(i=0;i<7;i++)
	{
		if(score[i]>8)
		{
		 grade[i]='A';	
		 printf("%s's grade is %c\n",name[i],grade[i]);
		}
		else if(score[i]>6)
		{
		 grade[i]='B';
		 printf("%s's grade is %c\n",name[i],grade[i]);
		}
		else if(score[i]>4)
		{
		 grade[i]='C';
		 printf("%s's grade is %c\n",name[i],grade[i]);	
		}
		else if(score[i]==4)
		{
		
		 grade[i]='D';
		 printf("%s's grade is %c\n",name[i],grade[i]);
		}
		else
		 grade[i]='F';
		 printf("%s's grade is %c\n",name[i],grade[i]);
	}
	
	
		
	return 0;
}
	

