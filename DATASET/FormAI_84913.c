//FormAI DATASET v1.0 Category: Funny ; Style: creative
#include <stdio.h>
#include <stdlib.h>

int main() {
   int apple = 10;
   int orange = 15;

   printf("There are %d apples and %d oranges.\n", apple, orange);

   if (apple == orange) {
        printf("The number of apples equals to the number of oranges!\n");
   } else if (apple > orange) {
        printf("The number of apples is greater than the number of oranges!\n");
   } else {
        printf("The number of oranges is greater than the number of apples!\n");
   }

   printf("If I eat one apple and one orange, I will have:\n");

   apple--;
   orange--;

   printf("%d apples and %d oranges left.\n", apple, orange);

   printf("Let's play a game! Guess how many apples I have left:\n");

   int guess;

   scanf("%d", &guess);

   while (guess != apple) {
        printf("Wrong guess! Try again:\n");
        scanf("%d", &guess);
   }

   printf("Congratulations! You guessed it right! I have %d apples left!\n", apple);

   return 0;
}