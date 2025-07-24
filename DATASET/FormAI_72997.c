//FormAI DATASET v1.0 Category: Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
     system("color 0E"); // Changes Console colors
     int guess, number, nguesses=1;
     srand(time(0)); // Random Number Generator
     number=rand()%100+1; // Generates random number between 1 and 100

     // Game Introduction
     printf("\n\n\t\t\tWelcome to the Guessing Game!\n\n");
     printf("Enter a number between 1 and 100 to guess the number: ");
     
     // Loop until correct number is guessed
     do
     {
          scanf("%d",&guess);
          if(guess<number)
          {
               printf("Too low, try again: ");
               nguesses++;
          }
          else if(guess>number)
          {
               printf("Too high, try again: ");
               nguesses++;
          }
          else
          {
               printf("\n\n\t\t\tCongratulations! You guessed the number in %d attempts.\n",nguesses);
          }
          
     }while(guess!=number);
     
     printf("\n\n\t\t\tThanks for playing! Play again soon!\n");

     return 0;
}