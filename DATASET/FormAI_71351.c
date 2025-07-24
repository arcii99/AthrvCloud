//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

int main() {
  int speed = 0;
  int direction = 0;

  printf("Welcome to the Remote Control Vehicle Simulation!\n");

  while (1) {
    printf("\nEnter a speed (0-100): ");
    scanf("%d", &speed);

    if (speed < 0 || speed > 100) {
      printf("Invalid speed, please enter a value between 0 and 100.\n");
      continue;
    }

    printf("Enter a direction (0-360): ");
    scanf("%d", &direction);

    if (direction < 0 || direction > 360) {
      printf("Invalid direction, please enter a value between 0 and 360.\n");
      continue;
    }

    printf("You are now moving at a speed of %d and a direction of %d.\n", speed, direction);
  }

  return 0;
}