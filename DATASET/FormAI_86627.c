//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define FLOORS 10
#define NUM_ELEVATORS 3

struct Elevator {
  int currentFloor;
  bool isMovingUp;
  bool isMovingDown;
  bool doorsOpen;
  bool doorsClose;
} elevators[NUM_ELEVATORS];

void initializeElevators() {
  for (int i = 0; i < NUM_ELEVATORS; i++) {
    elevators[i].currentFloor = 0;
    elevators[i].isMovingUp = false;
    elevators[i].isMovingDown = false;
    elevators[i].doorsOpen = false;
    elevators[i].doorsClose = true;
  }
}

void moveElevator(int elevatorIndex, int destinationFloor) {
  if (elevators[elevatorIndex].currentFloor < destinationFloor) {
    elevators[elevatorIndex].isMovingUp = true;
    elevators[elevatorIndex].isMovingDown = false;
    printf("Elevator %d moving up\n", elevatorIndex + 1);
    while (elevators[elevatorIndex].currentFloor < destinationFloor) {
      elevators[elevatorIndex].currentFloor++;
      printf("Elevator %d at floor %d\n", elevatorIndex + 1, elevators[elevatorIndex].currentFloor);
    }
  }
  else {
    elevators[elevatorIndex].isMovingUp = false;
    elevators[elevatorIndex].isMovingDown = true;
    printf("Elevator %d moving down\n", elevatorIndex + 1);
    while (elevators[elevatorIndex].currentFloor > destinationFloor) {
      elevators[elevatorIndex].currentFloor--;
      printf("Elevator %d at floor %d\n", elevatorIndex + 1, elevators[elevatorIndex].currentFloor);
    }
  }
}

void openElevatorDoors(int elevatorIndex) {
  elevators[elevatorIndex].doorsClose = false;
  elevators[elevatorIndex].doorsOpen = true;
  printf("Elevator %d doors opening\n", elevatorIndex + 1);
}

void closeElevatorDoors(int elevatorIndex) {
  elevators[elevatorIndex].doorsClose = true;
  elevators[elevatorIndex].doorsOpen = false;
  printf("Elevator %d doors closing\n", elevatorIndex + 1);
}

void elevatorSimulation() {
  int peopleWaiting[FLOORS] = {0}; 
  int peopleInElevator[NUM_ELEVATORS] = {0}; 

  srand(time(NULL)); 

  for (int i = 0; i < 50; i++) { 
    int currentFloor = rand() % FLOORS; 
    int numPeople = rand() % 5 + 1; 
    peopleWaiting[currentFloor] += numPeople; 
  }

  for (int i = 0; i < NUM_ELEVATORS; i++) {
    int elevatorTime = rand() % 5 + 1; 
    int destinationFloor = rand() % FLOORS; 
    moveElevator(i, destinationFloor); 
    elevatorTime = rand() % 5 + 1; 
    openElevatorDoors(i); 
    peopleInElevator[i] = peopleWaiting[elevators[i].currentFloor];
    printf("Elevator %d picked up %d people at floor %d\n", i + 1, peopleInElevator[i], elevators[i].currentFloor); 
    peopleWaiting[elevators[i].currentFloor] -= peopleInElevator[i]; 
    closeElevatorDoors(i); 
  }

  for (int floor = 0; floor < FLOORS; floor++) {
    if (peopleWaiting[floor] > 0) {
      for (int elevatorIndex = 0; elevatorIndex < NUM_ELEVATORS; elevatorIndex++) {
        if (elevators[elevatorIndex].doorsOpen && elevators[elevatorIndex].currentFloor == floor) {
          printf("Elevator %d picked up %d people at floor %d\n", elevatorIndex + 1, peopleWaiting[floor], floor); 
          peopleInElevator[elevatorIndex] = peopleWaiting[floor];
          peopleWaiting[floor] = 0; 
          break;
        }
      }
    }
  }

  for (int i = 0; i < NUM_ELEVATORS; i++) {
    int elevatorTime = rand() % 5 + 1; 
    int destinationFloor = rand() % FLOORS; 
    moveElevator(i, destinationFloor); 
    elevatorTime = rand() % 5 + 1; 
    openElevatorDoors(i); 
    printf("Elevator %d dropped off %d people at floor %d\n", i + 1, peopleInElevator[i], elevators[i].currentFloor); 
    closeElevatorDoors(i); 
  }
}

int main() {
  initializeElevators(); 
  elevatorSimulation(); 
  return 0;
}