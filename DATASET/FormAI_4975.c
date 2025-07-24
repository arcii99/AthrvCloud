//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int carPos = 0;
  int direction = 0;
  int steps = 0;
  
  srand(time(NULL));

  printf("Welcome to the Remote Control Vehicle Simulation!\n");
  printf("Press '1' to move the car forward, '2' to move it backward and '0' to stop.\n");

  do {
    printf("Current Position: %d\n", carPos);

    // generate a random direction if the user has not selected one
    if (direction == 0) {
      direction = rand() % 2 == 0 ? -1 : 1;
    }

    printf("Enter direction: ");
    scanf("%d", &direction);

    if (direction == 1) {
      printf("Enter number of steps: ");
      scanf("%d", &steps);
      carPos += steps;
    } else if (direction == 2) {
      printf("Enter number of steps: ");
      scanf("%d", &steps);
      carPos -= steps;
    } else {
      printf("Car stopped. Final position: %d\n", carPos);
      break;
    }

    printf("New position: %d\n", carPos);

    // reset direction to zero to generate a new random direction next time
    direction = 0;
  } while (1);

  return 0;
}