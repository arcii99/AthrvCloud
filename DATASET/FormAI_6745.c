//FormAI DATASET v1.0 Category: Game ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   srand(time(NULL)); // seed the random number generator
   int number = rand() % 1000; // generate a random number between 0 and 999
   int guess, tries = 0;
   
   printf("Welcome to the Guessing Game.\n");
   printf("I am thinking of a number between 0 and 999.\n");
   
   do {
      printf("Guess the number: ");
      scanf("%d", &guess);
      tries++;
      
      if (guess == number) {
         printf("Congratulations, you guessed the number in %d attempts!\n", tries);
         break;
      } else if (guess < number) {
         printf("Too low. Try again.\n");
      } else {
         printf("Too high. Try again.\n");
      }
      
   } while (guess != number);
   
   return 0;
}