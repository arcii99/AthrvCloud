//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: active
#include <stdio.h>

int main() {
  int currentFloor = 0; // the starting floor
  int destinationFloor;

  // loop continuously until the user requests to quit
  while (1) {
    printf("You are currently on floor %d\n", currentFloor);
    printf("Which floor would you like to go to? (Enter -1 to quit) ");
    scanf("%d", &destinationFloor);

    // check to see if the user wants to quit
    if (destinationFloor == -1) {
      printf("Exiting program...\n");
      break;
    }

    // check to see if the requested floor is valid
    if (destinationFloor < 0 || destinationFloor > 10 || destinationFloor == currentFloor) {
      printf("Invalid destination floor. Please try again.\n");
      continue;
    }

    printf("\nElevator going up...\n");

    // simulate the elevator moving up floors
    while (currentFloor < destinationFloor) {
      currentFloor++;
      printf("Floor %d...\n", currentFloor);
    }

    printf("\nYou have arrived at floor %d!\n\n", currentFloor);
  }

  return 0;
}