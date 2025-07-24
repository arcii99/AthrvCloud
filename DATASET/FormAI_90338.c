//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

int main() {
  int steps = 0;
  int goal = 10000;

  printf("Welcome to Your Fitness Tracker! Let's get moving.\n");
  
  while (steps < goal) {
    printf("Please enter the number of steps you took today: ");
    scanf("%d", &steps);

    if (steps < 0) {
      printf("Negative steps? That can't be right. Let's start over.\n");
      steps = 0;
      continue;
    }

    printf("You've taken %d steps so far today.\n", steps);

    if (steps >= goal) {
      printf("Congratulations! You've reached your goal of %d steps for today!\n", goal);
    } else {
      printf("You have %d steps left to reach your goal of %d steps for today.\n", goal - steps, goal);
    }
  }

  printf("Great job today! Keep up the good work.\n");
  return 0;
}