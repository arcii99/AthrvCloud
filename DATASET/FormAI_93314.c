//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  char name[20];
  printf("Welcome to the Automated Fortune Teller!\n");
  printf("What is your name? ");
  scanf("%s", name);
  printf("Hello, %s!\n\n", name);

  char questions[3][50] = {
    "What is your favorite color?",
    "What is your zodiac sign?",
    "What is your lucky number?"
  };

  char answers[3][20];
  for (int i = 0; i < 3; i++) {
    printf("%s ", questions[i]);
    scanf("%s", answers[i]);
  }

  srand(time(0));
  int fortune_num = rand() % 3;
  switch (fortune_num) {
    case 0:
      printf("\n%s, your future looks bright! You will have a happy and successful life.\n", name);
      break;
    case 1:
      printf("\n%s, unfortunately, you will face some challenges in the near future. But don't worry, you have the skills and strength to overcome them.\n", name);
      break;
    case 2:
      printf("\n%s, your luck will soon change for the better. Stay optimistic and keep moving forward.\n", name);
      break;
    default:
      printf("\n%s, an error has occurred. Please try again later.\n", name);
      break;
  }

  return 0;
}