//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: introspective
#include <stdio.h>

// elevator parameters
#define MAX_FLOORS 10
#define NUM_ELEVATORS 2

// elevator state enumeration
typedef enum {
  ELEVATOR_UP,
  ELEVATOR_DOWN,
  ELEVATOR_IDLE
} ElevatorState;

// elevator data structure
typedef struct {
  int currentFloor;
  ElevatorState state;
  int destinations[MAX_FLOORS];
  int numDestinations;
} Elevator;

// function prototypes
void printElevatorStatus(Elevator* elevator);
void addDestination(Elevator* elevator, int destination);
void moveElevator(Elevator* elevator);

int main() {
  // initialize two elevators
  Elevator elevators[NUM_ELEVATORS];
  for(int i = 0; i < NUM_ELEVATORS; i++) {
    elevators[i].currentFloor = 0;
    elevators[i].state = ELEVATOR_IDLE;
    elevators[i].numDestinations = 0;
    for(int j = 0; j < MAX_FLOORS; j++) {
      elevators[i].destinations[j] = 0;
    }
  }
  
  // set elevator destinations
  addDestination(&elevators[0], 5);
  addDestination(&elevators[0], 2);
  addDestination(&elevators[1], 8);
  
  // simulate elevator movement
  for(int i = 0; i < 15; i++) {
    printf("*********\n");
    for(int j = 0; j < NUM_ELEVATORS; j++) {
      moveElevator(&elevators[j]);
      printElevatorStatus(&elevators[j]);
    }
    printf("*********\n");
  }
  
  return 0;
}

void printElevatorStatus(Elevator* elevator) {
  printf("current floor: %d\n", elevator->currentFloor);
  switch(elevator->state) {
    case ELEVATOR_UP:
      printf("state: up\n");
      break;
    case ELEVATOR_DOWN:
      printf("state: down\n");
      break;
    case ELEVATOR_IDLE:
      printf("state: idle\n");
      break;
  }
  printf("destinations: ");
  for(int i = 0; i < MAX_FLOORS; i++) {
    if(elevator->destinations[i]) {
      printf("%d ", i);
    }
  }
  printf("\n");
}

void addDestination(Elevator* elevator, int destination) {
  elevator->destinations[destination] = 1;
  elevator->numDestinations++;
}

void moveElevator(Elevator* elevator) {
  if(elevator->numDestinations > 0) {
    if(elevator->currentFloor < MAX_FLOORS-1 && elevator->state == ELEVATOR_UP) {
      elevator->currentFloor++;
    }
    else if(elevator->currentFloor > 0 && elevator->state == ELEVATOR_DOWN) {
      elevator->currentFloor--;
    }
    else {
      elevator->state = ELEVATOR_IDLE;
      elevator->destinations[elevator->currentFloor] = 0;
      elevator->numDestinations--;
      for(int i = elevator->currentFloor+1; i < MAX_FLOORS; i++) {
        if(elevator->destinations[i]) {
          elevator->state = ELEVATOR_UP;
          break;
        }
      }
      if(elevator->state == ELEVATOR_IDLE) {
        for(int i = elevator->currentFloor-1; i >= 0; i--) {
          if(elevator->destinations[i]) {
            elevator->state = ELEVATOR_DOWN;
            break;
          }
        }
      }
    }
  }
}