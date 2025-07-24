//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

int main() {
  int speed, direction;

  printf("Remote Control Vehicle Simulation\n");

  do {
    printf("Enter speed (0-10): ");
    scanf("%d", &speed);
  } while (speed < 0 || speed > 10);

  do {
    printf("Enter direction (1-4): \n");
    printf("1. Forward\n");
    printf("2. Backward\n");
    printf("3. Left\n");
    printf("4. Right\n");

    scanf("%d", &direction);
  } while (direction < 1 || direction > 4);

  switch (direction) {
    case 1:
      printf("Vehicle moving forward at speed %d\n", speed);
      break;
    case 2:
      printf("Vehicle moving backward at speed %d\n", speed);
      break;
    case 3:
      printf("Vehicle turning left at speed %d\n", speed);
      break;
    case 4:
      printf("Vehicle turning right at speed %d\n", speed);
      break;
    default:
      printf("Invalid direction");
  }

  return 0;
}