//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: Romeo and Juliet
#include <stdio.h>

int main() {
  int currentFloor = 1;
  int desiredFloor;

  printf("Welcome to the Elevator!\n");
  printf("You are currently on floor %d\n", currentFloor);

  // Loop to simulate elevator movement
  while (1) {
    printf("Please enter your desired floor (1-10): ");
    scanf("%d", &desiredFloor);

    // Check if desired floor is within range
    if (desiredFloor < 1 || desiredFloor > 10) {
      printf("Invalid floor number, please try again.\n");
    } else if (desiredFloor == currentFloor) {
      printf("You are already on this floor.\n");
    } else {
      // Move elevator up or down to desired floor
      if (desiredFloor > currentFloor) {
        printf("Going up...\n");
        while (currentFloor < desiredFloor) {
          currentFloor++;
          printf("Now on floor %d\n", currentFloor);
        }
      } else {
        printf("Going down...\n");
        while (currentFloor > desiredFloor) {
          currentFloor--;
          printf("Now on floor %d\n", currentFloor);
        }
      }

      // Exit loop once elevator reaches desired floor
      printf("You have reached floor %d. Thank you for using the Elevator!\n", desiredFloor);
      break;
    }
  }

  return 0;
}