//FormAI DATASET v1.0 Category: Robot movement control ; Style: calm
#include <stdio.h>

int main() {
  // Variables to store robot position and direction
  int x = 0;
  int y = 0;
  char direction = 'N';

  // Example robot movement commands
  char commands[] = "FFRFLB";

  // Loop through each command and update robot position and direction
  for (int i = 0; i < strlen(commands); i++) {
    char command = commands[i];

    switch(command) {
      case 'F':
        // Move forward in the current direction
        if (direction == 'N') {
          y++;
        } else if (direction == 'E') {
          x++;
        } else if (direction == 'S') {
          y--;
        } else if (direction == 'W') {
          x--;
        }
        break;
      
      case 'B':
        // Move backward in the current direction
        if (direction == 'N') {
          y--;
        } else if (direction == 'E') {
          x--;
        } else if (direction == 'S') {
          y++;
        } else if (direction == 'W') {
          x++;
        }
        break;

      case 'L':
        // Turn left from the current direction
        if (direction == 'N') {
          direction = 'W';
        } else if (direction == 'E') {
          direction = 'N';
        } else if (direction == 'S') {
          direction = 'E';
        } else if (direction == 'W') {
          direction = 'S';
        }
        break;

      case 'R':
        // Turn right from the current direction
        if (direction == 'N') {
          direction = 'E';
        } else if (direction == 'E') {
          direction = 'S';
        } else if (direction == 'S') {
          direction = 'W';
        } else if (direction == 'W') {
          direction = 'N';
        }
        break;

      default:
        printf("Invalid command: %c\n", command);
        break;
    }
  }

  // Print final robot position and direction
  printf("Robot position: (%d, %d)\n", x, y);
  printf("Robot direction: %c\n", direction);

  return 0;
}