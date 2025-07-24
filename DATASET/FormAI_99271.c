//FormAI DATASET v1.0 Category: Funny ; Style: happy
#include <stdio.h>

int main() {
   int x = 10;
   int y = 20;
   int z = 0;

   printf("Welcome to the happy program! \n");

   z = x + y;
   printf("The sum of %d and %d is %d \n", x, y, z);

   if (z > 30) {
      printf("Wow, that's a big number! \n");
   } else {
      printf("That's a pretty small number. \n");
   }

   printf("Now let's play a game! \n");
   printf("Guess a number between 1 and 100: ");

   int guess;
   scanf("%d", &guess);

   int correct_number = 75;

   if (guess == correct_number) {
      printf("You got it! You're a winner! \n");
   } else if (guess < correct_number) {
      printf("Sorry, too low. Try again! \n");
   } else {
      printf("Sorry, too high. Try again! \n");
   }

   printf("Thanks for playing! Have a happy day! \n");

   return 0;
}