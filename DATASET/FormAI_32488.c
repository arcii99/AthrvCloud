//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: happy
#include <stdio.h>

int main() {
  int steps = 0;

  printf("Welcome to your unique C Fitness Tracker!\n");

  while(1) {
    printf("How many steps have you taken today? (Enter a number) ");
    int input;
    scanf("%d", &input);

    steps += input;

    printf("Current steps taken today: %d\n", steps);

    if(steps >= 10000) {
      printf("Congratulations! You've reached your daily goal of 10,000 steps!\n");
      printf("Keep up the great work!\n");
    }

    printf("Would you like to enter more steps? (Yes/No) ");
    char answer[4];
    scanf("%s", answer);

    if(strcmp(answer, "No") == 0 || strcmp(answer, "no") == 0) {
      break;
    }
  }

  printf("Thanks for using the C Fitness Tracker! Keep moving and stay healthy!\n");

  return 0;
}