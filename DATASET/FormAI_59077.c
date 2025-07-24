//FormAI DATASET v1.0 Category: Table Game ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int num, guess, attempts = 0;
   srand(time(0));
   num = rand() % 100 + 1; // Generate random number from 1 to 100
   
   printf("Welcome to the Number Guessing Game!\n");
   printf("I'm thinking of a number from 1 to 100. Can you guess it in 10 tries?\n");
   
   while(attempts < 10) {
      printf("Guess #%d: ", attempts+1);
      scanf("%d", &guess);
      
      if(guess < 1 || guess > 100) {
         printf("Invalid guess. Please enter a number from 1 to 100.\n");
         continue; // Restart the while-loop
      }
      
      if(guess < num) {
         printf("Too low!\n");
      } else if(guess > num) {
         printf("Too high!\n");
      } else {
         printf("Congratulations, you guessed the number in %d tries!\n", attempts+1);
         return 0; // Terminate the program
      }
      
      attempts++;
   }
   
   // If the user didn't guess the number in 10 tries, print the correct number
   printf("Sorry, you didn't guess the number in time. The correct number was %d.\n", num);
   
   return 0;
}