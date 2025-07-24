//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/* defining constants */
#define FLOORS 10
#define ELEVATORS 3

/* defining variables for elevator and floor */
int elevators[ELEVATORS];
int floors[FLOORS];

/* function to update elevator's floor */
void updateElevatorFloor(int e, int f) {
  elevators[e] = f;
}

/* function to get a random floor */
int getRandomFloor() {
  srand(time(0));
  return (rand() % FLOORS) + 1;
}

/* function to find nearest elevator */
int getNearestElevator(int floor) {
  int nearest = -1, diff = FLOORS+1;
  for (int i = 0; i < ELEVATORS; ++i) {
    if(abs(elevators[i] - floor) < diff) {
      diff = abs(elevators[i] - floor);
      nearest = i;
    }
  }
  return nearest;
}

/* function to simulate elevator movement */
void simulateElevatorMovement(int e, int f) {
  printf("\nElevator %d moving from floor %d to floor %d", e, elevators[e], f);
  for (int i = elevators[e]; i <= f; ++i) {
    printf("\nElevator %d at floor %d", e, i);
    updateElevatorFloor(e, i);
  }
  printf("\nElevator %d reached floor %d", e, f);
}

/* function to simulate elevator stopping at a floor */
void simulateElevatorStopping(int e) {
  printf("\nElevator %d stopping at floor %d", e, elevators[e]);
}

/* main function */
int main() {
  /* initializing elevators and floors */
  for (int i = 0; i < ELEVATORS; ++i) {
    elevators[i] = 1;
  }
  for (int i = 0; i < FLOORS; ++i) {
    floors[i] = 0;
  }

  /* simulating elevator requests */
  int requests = 10;
  printf("Simulating elevator requests...\n");
  for (int i = 0; i < requests; ++i) {
    int floor = getRandomFloor();
    int nearestElevator = getNearestElevator(floor);
    if (elevators[nearestElevator] != floor) {
      simulateElevatorMovement(nearestElevator, floor);
    }
    simulateElevatorStopping(nearestElevator);
    floors[floor-1] += 1;
  }

  /* displaying elevator and floor statistics */
  printf("\nElevator statistics:");
  for (int i = 0; i < ELEVATORS; ++i) {
    printf("\nElevator %d at floor %d", i, elevators[i]);
  }
  printf("\nFloor statistics:");
  for (int i = 0; i < FLOORS; ++i) {
    printf("\nFloor %d has been visited %d times", i+1, floors[i]);
  }

  return 0;
}