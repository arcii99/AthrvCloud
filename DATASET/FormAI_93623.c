//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: irregular
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {
  srand(time(NULL)); // seed random number generator with current time

  int posX = 0, posY = 0; // starting position of vehicle
  int facing = rand() % 4; // random starting direction (0 = up, 1 = right, 2 = down, 3 = left)

  int command;
  printf("Use 'w', 'a', 's', and 'd' to move the virtual RC vehicle. Press 'q' to quit.\n");

  while (1) {
    printf("\nCurrent position: (%d, %d)    Current direction: ", posX, posY);
    switch (facing) {
      case 0:
        printf("up");
        break;
      case 1:
        printf("right");
        break;
      case 2:
        printf("down");
        break;
      case 3:
        printf("left");
        break;
    }

    printf("\nEnter command: ");
    command = getchar();

    switch (command) {
      case 'w':
        posY--;
        break;
      case 'a':
        posX--;
        break;
      case 's':
        posY++;
        break;
      case 'd':
        posX++;
        break;
      case 'q':
        printf("\nGoodbye!\n");
        return 0;
      default:
        printf("\nInvalid command\n");
        continue;
    }

    if (posX < 0 || posX > 9 || posY < 0 || posY > 9) {
      // vehicle has gone off the grid
      printf("\nYou drove the vehicle off the grid!\n");
      break;
    }

    // randomly change direction occasionally
    if (rand() % 10 == 0) {
      facing = rand() % 4;
      printf("\nThe virtual RC vehicle has turned!\n");
    }

    // simulate delay to make it feel more real
    int delayMillis = rand() % 1001;
    printf("\nVehicle is moving...\n");
    usleep(delayMillis * 1000);
  }

  return 0;
}