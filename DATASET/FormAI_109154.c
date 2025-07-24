//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants to define the elevator capacity
#define ELEVATOR_CAPACITY 5
#define ELEVATOR_MAX_FLOOR 10
#define ELEVATOR_MIN_FLOOR 1

// Main function
int main() {
  // Seed to use in generating random numbers
  srand(time(0));

  // Variables to keep track of the elevator status
  int currentFloor = 1;
  int passengers = 0;
  int totalPassengers = 0;

  // Run the simulation for 100 rounds
  for (int i = 1; i <= 100; i++) {
    // Print the current round and elevator status
    printf("Round %d: current floor = %d, passengers = %d\n", i, currentFloor, passengers);

    // Check if there are passengers in the elevator
    if (passengers > 0) {
      // Randomly decide whether to let passengers off the elevator
      if (rand() % 2 == 0) {
        printf("Passengers getting off at floor %d\n", currentFloor);
        passengers = 0;
      }
    }

    // Check if the elevator is empty
    if (passengers == 0) {
      // Randomly decide whether to pick up new passengers
      if (rand() % 2 == 0) {
        // Randomly decide how many passengers to pick up
        int newPassengers = rand() % (ELEVATOR_CAPACITY - passengers) + 1;

        printf("Picking up %d passengers at floor %d\n", newPassengers, currentFloor);

        // Update the passenger counts
        passengers += newPassengers;
        totalPassengers += newPassengers;
      }
    }

    // Randomly decide whether to move the elevator up or down
    if (rand() % 2 == 0) {
      currentFloor++;
      if (currentFloor > ELEVATOR_MAX_FLOOR) {
        currentFloor = ELEVATOR_MAX_FLOOR;
      }
      printf("Moving up to floor %d\n", currentFloor);
    } else {
      currentFloor--;
      if (currentFloor < ELEVATOR_MIN_FLOOR) {
        currentFloor = ELEVATOR_MIN_FLOOR;
      }
      printf("Moving down to floor %d\n", currentFloor);
    }
  }

  // Print the total number of passengers carried
  printf("Total passengers carried: %d\n", totalPassengers);

  return 0;
}