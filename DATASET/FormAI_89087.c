//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define floor constants
#define LANDING_FLOOR 0
#define MAX_FLOORS 5

// Define direction constants
#define UP 1
#define DOWN -1

// Define elevator status constants
#define DOORS_CLOSED 0
#define DOORS_OPEN 1

// Define elevator struct
struct elevator {
  int currentFloor;
  int direction;
  int doors;
} elevator;

// Function to move the elevator up or down
void moveElevator() {
  if (elevator.direction == UP && elevator.currentFloor < MAX_FLOORS) {
    elevator.currentFloor++;
  } else if (elevator.direction == DOWN && elevator.currentFloor > LANDING_FLOOR) {
    elevator.currentFloor--;
  }
}

// Function to open the elevator doors
void openDoors() {
  if (elevator.doors == DOORS_CLOSED) {
    printf("The doors creakily open.\n");
    elevator.doors = DOORS_OPEN;
  }
}

// Function to close the elevator doors
void closeDoors() {
  if (elevator.doors == DOORS_OPEN) {
    printf("The doors creakily close.\n");
    elevator.doors = DOORS_CLOSED;
  }
}

int main() {
  srand(time(0)); // Set random seed

  // Initialize elevator struct
  elevator.currentFloor = LANDING_FLOOR;
  elevator.direction = UP;
  elevator.doors = DOORS_CLOSED;

  // Start the elevator simulation loop
  int i = 0;
  while (i < 100) {

    // Determine if the elevator should change direction at landing floor
    if (elevator.currentFloor == LANDING_FLOOR) {
      elevator.direction = rand() % 2 == 0 ? UP : DOWN;
    }

    // Move the elevator
    moveElevator();

    // Check if the elevator is at a floor
    if (elevator.currentFloor == LANDING_FLOOR && elevator.doors == DOORS_CLOSED) {
      openDoors();
    } else if (elevator.currentFloor != LANDING_FLOOR && elevator.doors == DOORS_OPEN) {
      closeDoors();
    } else if (elevator.currentFloor == MAX_FLOORS) {
      elevator.direction = DOWN;
    } else if (elevator.currentFloor == LANDING_FLOOR && elevator.direction == DOWN) {
      elevator.direction = UP;
    }

    printf("Elevator is at floor %d, moving %s, doors %s\n", 
          elevator.currentFloor, 
          elevator.direction == UP ? "up" : "down",
          elevator.doors == DOORS_OPEN ? "open" : "closed");

    // Pause for a moment before continuing
    for (int j = 0; j < 10000000; j++);
    
    i++;
  }
  
  return 0;
}