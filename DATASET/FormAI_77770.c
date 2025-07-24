//FormAI DATASET v1.0 Category: Game ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
  srand(time(NULL)); // seed random number generator with time
  int num1, num2, sum, guess;
  char name[20];

  printf("Welcome to the Surrealist Math Game!\n");
  printf("What is your name, player?\n");
  scanf("%s", name);

  printf("Hello, %s! Let's play.\n\n", name);

  while (1) {
    num1 = rand() % 10; // generate random numbers
    num2 = rand() % 10;
    sum = num1 + num2;

    printf("Here's your math problem:\n");
    printf("What is %d + %d?\n", num1, num2);

    printf("Enter your answer: ");
    scanf("%d", &guess);

    if (guess == sum) {
      printf("Congratulations, %s! That's correct!\n", name);
    } else {
      printf("Sorry, %s. The correct answer is %d.\n", name, sum);
    }

    printf("Would you like to play again? (Y/N)\n");
    char response = getchar(); // clear stdin
    response = getchar();
    if (response == 'N' || response == 'n') {
      break;
    }
    printf("\n");
  }
  printf("Thanks for playing, %s! Goodbye.\n", name);
}