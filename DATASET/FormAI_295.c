//FormAI DATASET v1.0 Category: Game ; Style: enthusiastic
#include <stdio.h>

int main() {
   int guess, num, count = 1;
   num = rand() % 100 + 1; //generating random number between 1 and 100
   printf("Guess the number between 1 and 100: ");
   scanf("%d", &guess);
 
   while (guess != num) {
      if (guess > num) {
         printf("Too high! Try again: ");
         scanf("%d", &guess);
      }
      else {
         printf("Too low! Try again: ");
         scanf("%d", &guess);
      }
      count++; //incrementing the guess count
   }
 
   printf("Congratulations! You guessed the number in %d tries.", count);
   return 0;
}