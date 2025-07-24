//FormAI DATASET v1.0 Category: Table Game ; Style: innovative
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

int main() 
{ 
   int choice, number, guess, guessCount = 0, retry; 
   do 
   { 
      srand(time(0)); 
      number = rand() % 100 + 1; // Generate random number between 1 and 100 
      printf("\nWelcome to the C Table Game!\nGuess a number between 1 and 100: "); 
      do 
      { 
         printf("\n->"); 
         scanf("%d", &guess); 
         guessCount++; // Increment the guess count 
         if (guess > number) 
         { 
            printf("Too high! Try again!\n"); 
         } 
         else if (guess < number) 
         { 
            printf("Too low! Try again!\n"); 
         } 
         else 
         { 
            printf("\nCongratulations! You guessed the number %d with %d tries!\n", number, guessCount); 
            break; 
         } 
      } while (1); // Run until the number is guessed correctly 
      printf("\nDo you want to play again? (1 for yes, 0 for no)\n"); 
      scanf("%d", &retry); 
   } while (retry == 1); // Run until the player decides to quit 
   printf("\nThanks for playing the C Table Game!\n"); 
   return 0; 
}