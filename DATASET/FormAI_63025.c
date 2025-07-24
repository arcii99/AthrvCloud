//FormAI DATASET v1.0 Category: Robot movement control ; Style: safe
#include <stdio.h>

int main() {
  // initialize variables
  int x = 0;
  int y = 0;
  int direction = 0; // 0 = north, 1 = east, 2 = south, 3 = west

  // loop forever until program is terminated
  while (1) {
    printf("Current position: (%d, %d)\n", x, y);
    printf("Enter a valid movement command (F, B, L, R): ");
    char command = getchar();

    // move forward
    if (command == 'F') {
      if (direction == 0) {
        y++;
      } else if (direction == 1) {
        x++;
      } else if (direction == 2) {
        y--;
      } else {
        x--;
      }
    }

    // move backward
    else if (command == 'B') {
      if (direction == 0) {
        y--;
      } else if (direction == 1) {
        x--;
      } else if (direction == 2) {
        y++;
      } else {
        x++;
      }
    }

    // turn left
    else if (command == 'L') {
      direction = (direction + 3) % 4;
    }

    // turn right
    else if (command == 'R') {
      direction = (direction + 1) % 4;
    }

    // invalid command
    else {
      printf("Invalid command!\n");
    }

    // clear input buffer
    while ((command = getchar()) != '\n' && command != EOF);

    // ensure robot stays within safe boundaries
    if (x < -10 || x > 10 || y < -10 || y > 10) {
      printf("Robot has gone out of bounds. Terminating program...\n");
      break;
    }
  }

  return 0;
}