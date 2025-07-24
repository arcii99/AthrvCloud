//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>

int main() {
  int speed = 0;

  printf("Welcome to the Remote Control Vehicle Simulator!\n\n");
  printf("Controls:\n");
  printf("1. Press the UP arrow to accelerate.\n");
  printf("2. Press the DOWN arrow to decelerate.\n");
  printf("3. Press the SPACEBAR to stop the vehicle.\n\n");

  printf("Current speed: %d\n", speed);

  char input;
  while (1) {
    input = getchar();

    if (input == '\033') { // escape sequence
      getchar(); // skip [
      switch(getchar()) {
        case 'A': // up arrow
          speed += 10;
          printf("Current speed: %d\n", speed);
          break;
        case 'B': // down arrow
          speed -= 10;
          if (speed < 0) speed = 0;
          printf("Current speed: %d\n", speed);
          break;
      }
    } else if (input == ' ') { // spacebar
      speed = 0;
      printf("Vehicle stopped.\n");
    }
  }

  return 0;
}