//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

int main() {
  int numFloors, maxCapacity, currFloor, targetFloor, passengers, totalPassengers = 0;
  printf("Enter the number of floors in the building: ");
  scanf("%d", &numFloors);
  printf("Enter the maximum capacity of the elevator: ");
  scanf("%d", &maxCapacity);
  printf("Elevator has arrived at floor 1.\nEnter the number of passengers entering the elevator: ");
  scanf("%d", &passengers);
  if (passengers > maxCapacity) {
    printf("ERROR: Number of passengers exceeds elevator capacity. Program will now terminate.");
    exit(1);
  }
  totalPassengers += passengers;
  printf("Enter the target floor: ");
  scanf("%d", &targetFloor);

  while (1) {
    if (targetFloor < currFloor) {
      printf("The elevator is descending to floor %d.\n", targetFloor);
      while (currFloor != targetFloor) {
        currFloor--;
        printf("Elevator has arrived at floor %d.\n", currFloor);
      }
    } else if (targetFloor > currFloor) {
      printf("The elevator is ascending to floor %d.\n", targetFloor);
      while (currFloor != targetFloor) {
        currFloor++;
        printf("Elevator has arrived at floor %d.\n", currFloor);
      }
    }
    printf("Elevator has arrived at floor %d.\nEnter the number of passengers exiting the elevator: ", currFloor);
    scanf("%d", &passengers);
    totalPassengers -= passengers;
    printf("Enter the number of passengers entering the elevator: ");
    scanf("%d", &passengers);
    if (passengers + totalPassengers > maxCapacity) {
      printf("ERROR: Number of passengers exceeds elevator capacity. Program will now terminate.");
      exit(1);
    }
    totalPassengers += passengers;
    printf("Enter the target floor: ");
    scanf("%d", &targetFloor);
  }
  return 0;
}