//FormAI DATASET v1.0 Category: Error handling ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void error_handling(int err_code);

int main() {
  int num, rand_num;

  srand(time(NULL));
  rand_num = rand() % 100 + 1;

  printf("Guess the number between 1 and 100: ");
  scanf("%d", &num);

  if(num < 1 || num > 100) {
    error_handling(1);
    return 1;
  }

  if(num == rand_num) {
    printf("Congratulations! You guessed the number!\n");
    return 0;
  }

  printf("Sorry, you did not guess the number. The correct answer was %d.\n", rand_num);

  return 0;
}

void error_handling(int err_code) {
  switch(err_code) {
    case 1:
      printf("Error: Invalid input. Please enter a number between 1 and 100.\n");
      break;
    default:
      printf("An unknown error has occurred.\n");
  }
}