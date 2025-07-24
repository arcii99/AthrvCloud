//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Set up the random seed: current time
  srand(time(NULL));
  // Initialize the position of the remote vehicle in the center of the field
  int x = 25;
  int y = 25;
  // Display the initial position of the remote vehicle
  printf("The remote vehicle is at position (%d, %d)\n\n", x, y);
  // Prompt the user for the direction to move the remote vehicle
  printf("Enter a direction to move the remote vehicle (N, S, E, W): ");
  // Read the user input
  char direction = getchar();
  // Move the remote vehicle in the chosen direction
  if (direction == 'N') {
    y = y - 1;
  } else if (direction == 'S') {
    y = y + 1;
  } else if (direction == 'E') {
    x = x + 1;
  } else if (direction == 'W') {
    x = x - 1;
  } else {
    // If an invalid direction is entered, display an error message and exit the program
    printf("Invalid direction entered\n");
    return 1;
  }
  // Display the new position of the remote vehicle
  printf("\nThe remote vehicle has moved to position (%d, %d)\n", x, y);
  // Generate a random event
  int event = rand() % 3;
  // Perform the event
  if (event == 0) {
    printf("The remote vehicle has run into a castle wall!\n");
  } else if (event == 1) {
    printf("The remote vehicle has discovered a secret passage!\n");
  } else if (event == 2) {
    printf("The remote vehicle has been ambushed by bandits!\n");
  }
  // Exit the program
  return 0;
}