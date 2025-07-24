//FormAI DATASET v1.0 Category: Robot movement control ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

/* Robot Movement Control Program */

int main() {
  printf("Welcome to the Robot Movement Control Program!\n");

  int direction = 0;
  int energy = 100; 
  printf("Starting direction: FORWARD\n");
  printf("Current energy level: %d\n", energy);

  while (energy > 0) {
    printf("Enter a direction (0 for FORWARD, 1 for BACKWARD): ");
    scanf("%d", &direction);

    if (direction == 0) {
      printf("Moving FORWARD\n");
      energy -= 10;
      printf("Current energy level: %d\n", energy);
    }
    else if (direction == 1) {
      printf("Moving BACKWARD\n");
      energy -= 20;
      printf("Current energy level: %d\n", energy);
    }
    else {
      printf("Invalid direction! Please enter 0 or 1.\n");
    }
  }

  printf("Current energy level: %d\n", energy);
  printf("Out of energy! Robot cannot move anymore.\n");

  return 0;
}