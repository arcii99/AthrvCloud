//FormAI DATASET v1.0 Category: Robot movement control ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // Seed the random number generator with current time

  int xPos = 0; // Robot's starting x position
  int yPos = 0; // Robot's starting y position

  printf("Starting Robot position: (%d, %d)\n", xPos, yPos);

  // Move the Robot randomly for 10 steps
  for (int i = 0; i < 10; i++) {
    int direction = rand() % 4; // Randomly choose a direction (0-3)

    switch (direction) { // Move the Robot based on the chosen direction
      case 0: // Move up
        yPos++;
        printf("Robot moved up!\n");
        break;
      
      case 1: // Move down
        yPos--;
        printf("Robot moved down!\n");
        break;

      case 2: // Move right
        xPos++;
        printf("Robot moved right!\n");
        break;

      case 3: // Move left
        xPos--;
        printf("Robot moved left!\n");
        break;
    }

    printf("Current position: (%d, %d)\n", xPos, yPos);
  }

  printf("Final Robot position: (%d, %d)\n", xPos, yPos);

  return 0;
}