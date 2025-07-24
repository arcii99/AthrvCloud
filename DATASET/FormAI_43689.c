//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
  int max_range;
  printf("Enter the maximum guess range for the secret number: ");
  scanf("%d", &max_range);

  // Generate random number
  srand(time(NULL));
  int secret_num = rand() % max_range + 1;

  printf("Guess a number between 1 and %d\n", max_range);
  int guess, tries=0;
  do {
    printf("Enter your guess: ");
    scanf("%d", &guess);
    tries++;

    if(guess > secret_num) {
      printf("Too high!\n");
    } else if(guess < secret_num) {
      printf("Too low!\n");
    } else {
      printf("You win!\n");
    }
  } while(guess != secret_num);

  printf("It took you %d tries to guess the secret number %d!\n", tries, secret_num);
  return 0;
}