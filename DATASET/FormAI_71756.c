//FormAI DATASET v1.0 Category: Table Game ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
   int num, guess, nguesses = 1;
   srand(time(0));
   num = rand() % 100 + 1; //generate the random number between 1 and 100
   
   printf("Welcome to the Guessing Game!\n");
   printf("The random number has been generated between 1 and 100. Try to guess the number.\n\n");
   
   do
   {
       printf("Enter your guess: ");
       scanf("%d", &guess);
       
       if(guess>num)
       {
           printf("Lower number please!\n");
       }
       else if (guess<num)
       {
           printf("Higher number please!\n");
       }
       else
       {
           printf("You guessed the correct number in %d attempts! Congratulations!\n", nguesses);
       }
       nguesses++;
       
   } while(guess!=num);
   
   return 0;
}