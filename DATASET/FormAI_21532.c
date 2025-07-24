//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define FLOORS 10
#define ELEVATORS 3

int currentFloor[ELEVATORS];
bool goingUp[ELEVATORS];
bool doorsOpen[ELEVATORS];

void initialize() {
  srand(time(NULL));
  for (int i = 0; i < ELEVATORS; i++) {
    currentFloor[i] = rand() % FLOORS;
    goingUp[i] = true;
    doorsOpen[i] = true;
  }
}

void printState() {
  printf("===============================\n");
  for (int i = 0; i < ELEVATORS; i++) {
    printf("| ELEVATOR %d |", i+1);
    printf(" FLOOR: %d |", currentFloor[i]);
    printf(" GOING: %s |", goingUp[i] ? "UP  " : "DOWN");
    printf(" DOORS: %s |\n", doorsOpen[i] ? "OPEN" : "CLOSED");
  }
}

void moveElevator(int id) {
  int step = goingUp[id] ? 1 : -1;
  currentFloor[id] += step;
  printf("===============================\n");
  printf("|   ELEVATOR %d IS MOVING    |\n", id+1);
  printf("|        FLOOR: %d         |\n", currentFloor[id]);
  printf("===============================\n");
}

void openDoors(int id) {
  doorsOpen[id] = true;
  printf("===============================\n");
  printf("|  ELEVATOR %d DOORS OPENING  |\n", id+1);
  printf("===============================\n");
}

void closeDoors(int id) {
  doorsOpen[id] = false;
  printf("===============================\n");
  printf("|  ELEVATOR %d DOORS CLOSING  |\n", id+1);
  printf("===============================\n");
}

int main() {
  initialize();
  printState();

  while (true) {
    for (int i = 0; i < ELEVATORS; i++) {
      if (currentFloor[i] == FLOORS-1) {
        goingUp[i] = false;
        closeDoors(i);
      } else if (currentFloor[i] == 0) {
        goingUp[i] = true;
        closeDoors(i);
      }

      if (doorsOpen[i] == true) {
        continue;
      }

      moveElevator(i);

      if (currentFloor[i] == FLOORS-1 || currentFloor[i] == 0) {
        openDoors(i);
      }
    }

    printState();
  }
  return 0;
}