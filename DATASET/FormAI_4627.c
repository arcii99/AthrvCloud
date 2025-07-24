//FormAI DATASET v1.0 Category: Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
   srand(time(NULL)); // initialize random seed
   
   int lower = 1, upper = 100, count = 1; // initialize variables for guessing game
   int num = (rand() % (upper - lower + 1)) + lower; // generate random number
   
   int guess; // initialize variable for user's guess
   printf("Guess a number between %d and %d\n", lower, upper);
   
   do {
      printf("Enter guess %d: ", count);
      scanf("%d", &guess);
      
      if (guess == num) { // Check if guess is correct
         printf("Congratulations! You guessed the number in %d attempt(s).\n", count);
         break;
      }
      
      else if (guess < num) { // Check if guess is too low
         printf("Too low. Try again.\n");
         count++;
      }
      
      else { // Guess is too high
         printf("Too high. Try again.\n");
         count++;
      }
   } while (guess != num);
}