//FormAI DATASET v1.0 Category: Funny ; Style: inquisitive
#include <stdio.h>

int main() {
   char question[30];
   printf("Hi there, how are you today?\n");
   scanf("%s", question);
   printf("Hmm, that's interesting. Now, I have a question for you!\n");

   int answer;
   printf("What is the sum of 2 and 2?\n");
   scanf("%d", &answer);

   if (answer == 4) {
      printf("Correct! Good job!\n");
   } else {
      printf("Wrong! That's okay, let's try again!\n");
   }

   printf("Now, let's play a little game. I'm going to think of a number between 1 and 10. You have to guess what it is!\n");

   int number = rand() % 10 + 1;
   int guess;
   int attempts = 0;

   do {
      attempts++;
      printf("Guess #%d: ", attempts);
      scanf("%d", &guess);

      if (guess < number) {
         printf("Nope, too low! Try again.\n");
      } else if (guess > number) {
         printf("Nope, too high! Try again.\n");
      }
   } while (guess != number);

   printf("Congratulations! You guessed the number %d in %d attempts!\n", number, attempts);

   printf("Thanks for playing along. Do you have any more questions for me?\n");
   return 0;
}