//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: detailed
// Unique C Elevator Simulation Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define maxCapacity 10  // Maximum capacity of the elevator
#define floors 10        // Number of floors in the building
#define timePerFloor 2   // Time taken by the elevator to cover one floor

// Struct for elevator
typedef struct {
  int currentFloor;
  int nextFloor;
  int capacity;
  int passengers[maxCapacity];
} elevator;

// Function to initialize the elevator
void initializeElevator(elevator *e) {
  e->currentFloor = 0;
  e->nextFloor = 0;
  e->capacity = 0;
  memset(e->passengers, -1, sizeof(e->passengers));
}

// Function to check if the elevator is empty
bool isElevatorEmpty(elevator *e) {
  return e->capacity == 0;
}

// Function to check if the elevator is full
bool isElevatorFull(elevator *e) {
  return e->capacity == maxCapacity;
}

// Function to check if the elevator is on the first floor
bool isElevatorOnFirstFloor(elevator *e) {
  return e->currentFloor == 0;
}

// Function to check if the elevator is on the top floor
bool isElevatorOnTopFloor(elevator *e) {
  return e->currentFloor == floors - 1;
}

// Function to check if the elevator is going up
bool isElevatorGoingUp(elevator *e) {
  return e->currentFloor < e->nextFloor;
}

// Function to check if the elevator is going down
bool isElevatorGoingDown(elevator *e) {
  return e->currentFloor > e->nextFloor;
}

// Function to add a passenger to the elevator
void addPassenger(elevator *e, int passenger) {
  if (isElevatorFull(e)) {
    printf("Elevator is full, cannot add passenger %d\n", passenger);
    return;
  }
  
  for (int i = 0; i < maxCapacity; i++) {
    if (e->passengers[i] == -1) {
      e->passengers[i] = passenger;
      e->capacity++;
      printf("Added passenger %d to elevator\n", passenger);
      return;
    }
  }
}

// Function to remove a passenger from the elevator
void removePassenger(elevator *e, int passenger) {
  for (int i = 0; i < maxCapacity; i++) {
    if (e->passengers[i] == passenger) {
      e->passengers[i] = -1;
      e->capacity--;
      printf("Removed passenger %d from elevator\n", passenger);
      return;
    }
  }
}

// Function to move the elevator to the next floor
void moveElevatorToNextFloor(elevator *e) {
  if (isElevatorOnFirstFloor(e) || isElevatorOnTopFloor(e)) {
    return;
  }
  
  if (isElevatorGoingUp(e)) {
    e->currentFloor++;
    printf("Elevator moved up to floor %d\n", e->currentFloor);
  } else {
    e->currentFloor--;
    printf("Elevator moved down to floor %d\n", e->currentFloor);
  }
}

// Main function
int main() {
  srand(time(NULL)); // Set random seed
  
  elevator e;
  initializeElevator(&e);
  
  // Simulation loop
  for (int i = 0; i < floors; i++) {
    printf("Elevator arrived at floor %d\n", i);
    
    // Randomly add and remove passengers
    if (rand() % 2 == 0) {
      int nextPassenger = rand() % 100;
      addPassenger(&e, nextPassenger);
    } else if (!isElevatorEmpty(&e)) {
      int passengerIndex = rand() % e.capacity;
      int passenger = e.passengers[passengerIndex];
      removePassenger(&e, passenger);
    }
    
    if (isElevatorEmpty(&e)) {
      e.nextFloor = rand() % floors;
    } else if (isElevatorGoingUp(&e)) {
      e.nextFloor = rand() % (floors - 1 - e.currentFloor) + e.currentFloor + 1;
    } else {
      e.nextFloor = rand() % (e.currentFloor - 1) + 1;
    }
    
    // Move elevator to next floor
    while (e.currentFloor != e.nextFloor) {
      moveElevatorToNextFloor(&e);
      sleep(timePerFloor); // Wait for elevator to move to next floor
    }
  }
  
  return 0;
}