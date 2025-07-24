//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: shape shifting
// Shape shifting C Remote Control Vehicle Simulation
// By [Your Name]

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to simulate the shape shifting of the remote control vehicle
void shapeShift(int mode) {
  if (mode == 0) {
    printf("Vehicle is in car mode!\n");
  } else {
    printf("Vehicle is in plane mode!\n");
  }
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  int mode = 0;

  // Initial shape shifting of the vehicle
  shapeShift(mode);

  // Loop to allow user to control the vehicle
  while (1) {
    // Randomly generate a number to determine the next mode of the vehicle
    int random = rand() % 2;

    // Prompt the user to enter a command to control the vehicle
    printf("Enter a command to control the vehicle (c to switch to car mode, p to switch to plane mode): ");
    char command;
    scanf(" %c", &command);

    // Handle the user's command
    switch (command) {
      case 'c':
        mode = 0; // Switch to car mode
        break;
      case 'p':
        mode = 1; // Switch to plane mode
        break;
      default:
        printf("Invalid command!\n");
        break;
    }

    // Display the current mode of the vehicle
    shapeShift(mode);

    // Check if the user has won the game
    if (mode == random) {
      printf("Congratulations, you won the game!\n");
      break;
    }
  }

  return 0;
}