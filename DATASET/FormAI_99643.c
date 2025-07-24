//FormAI DATASET v1.0 Category: Robot movement control ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int position = 0; // initialize starting position as zero
  char direction;

  printf("Welcome to Robot Movement Control Program!\n");
  printf("Enter 'F' to move Forward or 'B' to move Backward, 'S' to Stop the Robot.\n");

  while (1) {
    printf("Current Position: %d\n", position);
    printf("Enter Direction: ");
    scanf(" %c", &direction);

    // check for input validation
    if ((direction != 'F') && (direction != 'B') && (direction != 'S')) {
      printf("Invalid Direction! Try Again.\n");
      continue;
    }

    srand(time(0)); // generate random number seed for robot's movement
    int steps = rand() % 10 + 1; // generate random number of steps between 1 and 10

    if (direction == 'F') {
      position += steps;
      printf("Moving Forward %d steps...\n", steps);
    } else if (direction == 'B') {
      position -= steps;
      printf("Moving Backward %d steps...\n", steps);
    } else {
      printf("Stopping Robot...\n");
      break;
    }
  }

  printf("Final Position: %d\n", position);
  printf("Thank You for Using Robot Movement Control Program!\n");

  return 0;
}