//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FLOOR 10 // Maximum number of floors in the building
#define ELEVATOR_SPEED 2 // The speed of the elevator is 2 floors per second

// The Elevator structure
typedef struct {
  int floor; // The current floor of the elevator
  int direction; // The current direction of the elevator (1 for up, -1 for down, 0 for stopped)
  int goal_floor; // The floor the elevator is currently heading towards
  int doors_open; // 1 if the elevator doors are open, 0 otherwise
} Elevator;

// Function that returns a random integer between min and max
int random_int(int min, int max);

int main() {
  srand(time(NULL)); // Seed the random number generator using the current time
  Elevator elevator = {1, 1, 1, 0}; // Initialize the elevator to the first floor, heading up, with no goal floor and the doors closed
  int i;
  for (i = 1; i <= MAX_FLOOR; i++) {
    printf("Floor %d: ", i);
    if (i == elevator.floor) { // If the elevator is on this floor
      if (elevator.doors_open) { // If the doors are open
        printf("Elevator doors are open\n");
      } else { // If the doors are closed
        printf("Elevator doors are closed\n");
      }
    } else { // If the elevator is not on this floor
      printf("\n");
    }
    if (i == elevator.goal_floor && elevator.direction != 0) { // If the elevator has reached its goal floor
      printf("  Elevator has reached its goal floor\n");
      elevator.doors_open = 1; // Open the doors
      elevator.direction = 0; // Stop the elevator
    }
    if (i == elevator.floor && elevator.direction != 0 && !elevator.doors_open) { // If the elevator is on this floor and the doors are closed and it has a direction
      printf("  Elevator is moving ");
      if (elevator.direction == 1) { // If the elevator is moving up
        elevator.floor++;
        printf("up\n");
      } else { // If the elevator is moving down
        elevator.floor--;
        printf("down\n");
      }
    }
    if (i == elevator.floor && elevator.direction != 0 && elevator.doors_open) { // If the elevator is on this floor and the doors are open and it has a direction
      elevator.doors_open = 0; // Close the doors
    }
    if (i == elevator.floor && elevator.direction == 0) { // If the elevator is on this floor and has no direction
      printf("  Elevator doors are open\n");
    }
    if (i == random_int(1, MAX_FLOOR) && elevator.direction == 0) { // If a random person has entered the elevator
      elevator.goal_floor = random_int(1, MAX_FLOOR); // Set the goal floor to a random floor
      elevator.direction = (elevator.goal_floor > elevator.floor) ? 1 : -1; // Determine the direction the elevator should go based on the goal floor
      printf("  Someone has entered the elevator. Goal floor: %d\n", elevator.goal_floor);
    }
  }
  return 0;
}

int random_int(int min, int max) {
  return min + rand() % (max - min + 1);
}