//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: relaxed
#include <stdio.h>

#define FLOORS 10

int main() {
  int floor, currentFloor = 0;
  char choice;

  printf("Welcome to the elevator simulation program.\n");
  printf("Press 'u' to go up one floor.\n");
  printf("Press 'd' to go down one floor.\n");
  printf("Press 'q' to quit.\n\n");

  while(1) {
    printf("You are on floor %d\n", currentFloor);
    printf("Where would you like to go? ");
    scanf(" %c", &choice);

    switch(choice) {
      case 'u':
        if (currentFloor < FLOORS) {
          currentFloor++;
          printf("Going up to floor %d.\n\n", currentFloor);
        } else {
          printf("You are already on the top floor!\n\n");
        }
        break;
      case 'd':
        if (currentFloor > 0) {
          currentFloor--;
          printf("Going down to floor %d.\n\n", currentFloor);
        } else {
          printf("You are already on the ground floor!\n\n");
        }
        break;
      case 'q':
        printf("Exiting elevator simulation program.\n");
        return 0;
      default:
        printf("Invalid choice.\n\n");
        break;
    }
  }
}