//FormAI DATASET v1.0 Category: Robot movement control ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Welcome to C Robot Movement Control!\n");
  
  // Initializing Variables
  int x_axis = 0; // denotes the movement on x-axis
  int y_axis = 0; // denotes the movement on y-axis
  int direction = 0; // denotes the direction in which robot is facing. 0 - North, 1 - East, 2 - South, 3 - West

  // Looping until the user exits
  while (1) {
    printf("Enter a command (F - Move Forward, B - Move Backward, L - Turn Left, R - Turn Right): ");
    char command = getchar();

    // Flushing the input buffer
    while (getchar() != '\n');

    switch (command) {
      case 'F':
        switch (direction) {
          case 0:
            y_axis += 1;
            break;
          case 1:
            x_axis += 1;
            break;
          case 2:
            y_axis -= 1;
            break;
          case 3:
            x_axis -= 1;
            break;
        }
        break;
      case 'B':
        switch (direction) {
          case 0:
            y_axis -= 1;
            break;
          case 1:
            x_axis -= 1;
            break;
          case 2:
            y_axis += 1;
            break;
          case 3:
            x_axis += 1;
            break;
        }
        break;
      case 'L':
        direction = (direction + 3) % 4;
        break;
      case 'R':
        direction = (direction + 1) % 4;
        break;
      case 'E':
        printf("Exiting...\n");
        exit(0);
        break;
      default:
        printf("Invalid Command!\n");
        break;
    }

    printf("Current Position: (%d, %d)\n", x_axis, y_axis);
    printf("Current Direction: ");
    switch (direction) {
      case 0:
        printf("North\n");
        break;
      case 1:
        printf("East\n");
        break;
      case 2:
        printf("South\n");
        break;
      case 3:
        printf("West\n");
        break;
    }
  }

  return 0;
}