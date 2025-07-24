//FormAI DATASET v1.0 Category: Robot movement control ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

void move_forward(int distance) {
  printf("Moving forward %d meters\n", distance);
}

void turn_left(int angle) {
  printf("Turning left %d degrees\n", angle);
}

void turn_right(int angle) {
  printf("Turning right %d degrees\n", angle);
}

int main() {
  printf("Welcome to Robot Control System!\n");
  printf("Please enter the command (F/B/L/R) and the distance/angle:\n");
  char command;
  int value;
  scanf("%c %d", &command, &value);
  switch(command) {
    case 'F':
      move_forward(value);
      break;
    case 'B':
      move_forward(-value); // negative value to move backward
      break;
    case 'L':
      turn_left(value);
      break;
    case 'R':
      turn_right(value);
      break;
    default:
      printf("Invalid command!\n");
  }
  return 0;
}