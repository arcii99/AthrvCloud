//FormAI DATASET v1.0 Category: Random ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_NUM 1
#define MAX_NUM 100

int main() {
   srand(time(0));
   int randNum = (rand() % (MAX_NUM - MIN_NUM + 1)) + MIN_NUM; // Generate a random number between 1 and 100
   int guess;

   printf("Welcome to the guessing game!\n");
   printf("I am thinking of a number between %d and %d.\n", MIN_NUM, MAX_NUM);

   do {
      printf("Guess what number I am thinking of: ");
      scanf("%d", &guess);

      if (guess < randNum) {
         printf("Your guess is too low. Try again!\n");
      } else if (guess > randNum) {
         printf("Your guess is too high. Try again!\n");
      }
   } while (guess != randNum);

   printf("Congratulations! You guessed the number %d!\n", randNum);

   return 0;
}