//FormAI DATASET v1.0 Category: Random ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int num, guess, count = 0;
   time_t t;
   
   srand((unsigned) time(&t));
   
   num = rand() % 100 + 1;
   
   printf("Guess a number between 1 to 100\n");
   
   do {
      scanf("%d", &guess);
      count++;
      
      if (guess > num) {
         printf("Lower number please!\n");
      }
      if (guess < num) {
         printf("Higher number please!\n");
      }
   } while (guess != num);
   
   printf("Congratulations, you guessed it in %d tries!", count);
   
   return 0;
}