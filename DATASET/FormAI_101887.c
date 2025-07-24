//FormAI DATASET v1.0 Category: Robot movement control ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Initialize the global variables for the robot position and movement
int x_pos = 0;
int y_pos = 0;
int direction = 0;

// Function to move the robot in a shape-shifting style
void move_robot(int moves) {

  // Move the robot through the specified number of moves
  for (int i = 0; i < moves; i++) {
    // Generate a random number between 0 and 3
    int r = rand() % 4;

    // Update the robot's direction based on the random number
    if (r == 0) {
      direction = (direction + 3) % 4;
    } else if (r == 1) {
      direction = (direction + 1) % 4;
    } else if (r == 2) {
      x_pos += 1;
    } else if (r == 3) {
      y_pos += 1;
    }

    // Print out the current position and movement of the robot
    printf("Moved %d units in direction %d.\n", i+1, direction);
    printf("Current position: (%d, %d)\n", x_pos, y_pos);
    printf("-----------------\n");
  }
}

int main() {
  // Set the seed for the random number generator
  srand(time(0));

  // Move the robot through a series of shape-shifting moves
  move_robot(10);

  // End the program
  return 0;
}