//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define FLOORS 10
#define ELEVATORS 3

enum Status { UP, DOWN, STOPPED };

struct Elevator {
  int currentFloor;
  int destinationFloor;
  enum Status status;
};

typedef struct Elevator elevator_t;

int main() {
  elevator_t elevators[ELEVATORS];
  int requests[FLOORS] = {0};
  int i, j;

  // initialize all elevators and set their starting floor to 1
  for (i = 0; i < ELEVATORS; i++) {
    elevators[i].currentFloor = 1;
    elevators[i].destinationFloor = -1;
    elevators[i].status = STOPPED;
  }

  printf("Welcome to the Elevator Simulation\n");

  // Start simulation loop
  while (1) {
    // Print current status of elevators
    for (i = 0; i < ELEVATORS; i++) {
      printf("Elevator %d is currently on Floor %d and is ", i + 1, elevators[i].currentFloor);

      if (elevators[i].status == UP) {
        printf("going UP\n");
      } else if (elevators[i].status == DOWN) {
        printf("going DOWN\n");
      } else {
        printf("STOPPED\n");
      }
    }

    printf("\n");

    // Check for elevator requests and assign the closest elevator to the floor
    for (i = 0; i < FLOORS; i++) {
      if (requests[i] != 0) {
        // find the closest elevator to the requested floor
        int min_dist = 100;
        int closest_elevator;
        for (j = 0; j < ELEVATORS; j++) {
          int dist = abs(i+1 - elevators[j].currentFloor);
          if (dist < min_dist) {
            min_dist = dist;
            closest_elevator = j;
          }
        }

        // assign closest elevator to the floor
        elevators[closest_elevator].destinationFloor = i+1;
        if (elevators[closest_elevator].currentFloor < i+1) {
          elevators[closest_elevator].status = UP;
        } else if (elevators[closest_elevator].currentFloor > i+1) {
          elevators[closest_elevator].status = DOWN;
        }

        // reset request flag for the floor
        requests[i] = 0;

        printf("Elevator %d has been assigned to Floor %d\n", closest_elevator+1, i+1);
      }
    }

    printf("\n");

    // Move all elevators
    for (i = 0; i < ELEVATORS; i++) {
      if (elevators[i].status == UP) {
        elevators[i].currentFloor++;
        printf("Elevator %d is on Floor %d\n", i+1, elevators[i].currentFloor);
        if (elevators[i].currentFloor == elevators[i].destinationFloor) {
          elevators[i].status = STOPPED;
        }
      } else if (elevators[i].status == DOWN) {
        elevators[i].currentFloor--;
        printf("Elevator %d is on Floor %d\n", i+1, elevators[i].currentFloor);
        if (elevators[i].currentFloor == elevators[i].destinationFloor) {
          elevators[i].status = STOPPED;
        }
      }
    }

    printf("\n");

    // Check for new requests
    printf("Choose Floor to Request Elevator (1 - 10): ");
    int floor;
    scanf("%d", &floor);
    if (floor > 0 && floor <= FLOORS) {
      requests[floor-1] = 1;
    }

    printf("\n");
  }

  return 0;
}