//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

enum Direction { FORWARD, BACKWARD, LEFT, RIGHT};

void move(enum Direction direction) {
  switch (direction) {
    case FORWARD:
      printf("Moving forward..\n");
      break;
    case BACKWARD:
      printf("Moving backward..\n");
      break;
    case LEFT:
      printf("Turning left..\n");
      break;
    case RIGHT:
      printf("Turning right..\n");
      break;
    default:
      printf("Invalid direction. Please try again.\n");
  }
}

int main() {
  int choice;
  enum Direction direction;

  printf("Welcome to the Remote Control Vehicle Simulation!\n\n");

  while (1) {
    printf("Enter a direction (0 = forward, 1 = backward, 2 = left, 3 = right): ");
    scanf("%d", &choice);

    direction = (enum Direction) choice;
    move(direction);
  }

  return 0;
}