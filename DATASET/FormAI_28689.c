//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Initialize variables
  int speed = 0;
  int direction = 0;
  int battery = 100;
  int isMoving = 0;

  // Loop until battery runs out
  while (battery > 0) {

    // Prompt user for speed and direction input
    printf("Enter speed (0-100): ");
    scanf("%d", &speed);
    printf("Enter direction (0-359): ");
    scanf("%d", &direction);

    // Check if the RC vehicle is moving
    if (speed > 0) {
      isMoving = 1;
    } else {
      isMoving = 0;
    }

    // Update battery level based on usage
    if (isMoving == 1) {
      battery = battery - (speed / 10);
    }

    // Print out current status
    printf("Speed: %d, Direction: %d, Battery: %d%%\n", speed, direction, battery);

  }

  // End program
  printf("Battery level too low. Exiting simulation...");
  return 0;
}