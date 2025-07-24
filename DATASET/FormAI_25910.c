//FormAI DATASET v1.0 Category: Robot movement control ; Style: high level of detail
#include <stdio.h>

// Define direction constants
#define LEFT 0
#define RIGHT 1

// Define function to move robot left or right
void move_robot(int direction, int distance) {
  if (direction == LEFT) {
    printf("Moving robot left %d feet.\n", distance);
  } else if (direction == RIGHT) {
    printf("Moving robot right %d feet.\n", distance);
  } else {
    printf("Invalid direction. Robot can only move left or right.\n");
  }
}

int main() {
  // Prompt user for input
  printf("Enter direction (0 for left, 1 for right): ");
  int direction;
  scanf("%d", &direction);

  printf("Enter distance (in feet): ");
  int distance;
  scanf("%d", &distance);

  // Move robot
  move_robot(direction, distance);

  return 0;
}