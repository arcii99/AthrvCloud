//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  char question[100];
  srand(time(NULL));
  int random_num = rand() % 5;

  printf("Welcome to the Automated Fortune Teller!\n");
  printf("Ask me a question about your future.\n");
  fgets(question, 100, stdin);

  switch (random_num) {
    case 0:
      printf("The stars say that your future is bright!\n");
      break;
    case 1:
      printf("Your future is filled with success and prosperity!\n");
      break;
    case 2:
      printf("You will face obstacles in your future, but you will overcome them!\n");
      break;
    case 3:
      printf("You will meet someone important in your future who will change your life!\n");
      break;
    case 4:
      printf("Your future holds great adventures and traveling!\n");
      break;
    default:
      printf("I cannot predict your future.\n");
      break;
  }

  return 0;
}