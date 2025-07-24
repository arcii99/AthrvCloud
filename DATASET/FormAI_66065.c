//FormAI DATASET v1.0 Category: Memory Game ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

# define MAX 100

int main() {
   int num, guess, tries = 0;
   int array[MAX];
   time_t t;
   
   srand((unsigned) time(&t));
   
   for(int i = 0; i < MAX; i++) {
      array[i] = rand() % 101;
   }
   
   num = rand() % 101;
 
   printf("\nWelcome to the Memory Game!\n");
   printf("The computer will generate a number between 0 and 100, and you have to guess it.\n");
 
   do {
      printf("\nEnter your guess: ");
      scanf("%d", &guess);
      tries++;
 
      if (guess > num) {
         printf("\nToo high! Try again.\n");
      }
      else if (guess < num) {
         printf("\nToo low! Try again.\n");
      }
      else {
         printf("\nCongratulations! You guessed the number in %d tries!\n", tries);
      }
   } while (guess != num);
   
   printf("\nHere are the first ten values of the generated array:\n");
   for(int i = 0; i < 10; i++) {
      printf("%d ", array[i]);
   }
   printf("\n");
   
   return 0;
}