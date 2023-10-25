#include <stdio.h>
#include <stdlib.h>
void numbers_game(){
       const TARGET = 23;  // the target number to be guessed
       int guess;          // the variable for storing the user input
       
       while(guess != TARGET) {   // keep executing the following block until correct number guessed

           printf("\nGuess a number: ");
           scanf("%d", &guess); 
                    
           if(abs(TARGET - guess) > 1000)
              printf("\n\nYou guessed far ");
           else if(abs(TARGET - guess) > 100)
             printf("\n\nYou guessed "); 
           else if(abs(TARGET - guess) > 10)
             printf("\n\nThat's a bit "); 
           else
             printf("\n\nQuite close, but ");
             
           if(TARGET > guess)
             printf("too low"); 
           else
             printf("too high"); 
       }
       // we leave the while block once there was a correct guess
       printf("Congratulations - You guessed correctly!");
       getchar();

}
