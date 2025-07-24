//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Generate random start time
  srand(time(NULL));
  int startTime = rand() % 24;

  int flow = 10; // number of cars per minute
  int simulationTime = 60; // minutes
  int maxCapacity = 20; // maximum number of cars allowed on road
  int currentFlow = 0; // current number of cars on road
  int currentMinute = startTime;
  int numEmergencyVehicles = 0; // number of emergency vehicles currently on road

  printf("Traffic simulation starting at %d:00\n", startTime);

  // Run simulation for specified time
  while (currentMinute < startTime + simulationTime) {

    // Determine if an emergency vehicle will appear
    if (rand() % 10 == 1) {
      numEmergencyVehicles += 1;
      printf("EMERGENCY VEHICLE: Please clear the way! %d vehicles currently on road.\n", currentFlow);
    }

    // Determine if a car will enter road
    if (rand() % 10 < flow || currentFlow <= 0) {
      if (currentFlow < maxCapacity - numEmergencyVehicles) {
        currentFlow += 1;
        printf("Car entered road. %d vehicles currently on road.\n", currentFlow + numEmergencyVehicles);
      } else {
        printf("MAXIMUM CAPACITY REACHED. %d vehicles currently on road.\n", currentFlow + numEmergencyVehicles);
      }
    }

    // Determine if a car will exit road
    if (rand() % 10 < flow || currentFlow < maxCapacity / 2) {
      if (currentFlow > 0) {
        currentFlow -= 1;
        printf("Car exited road. %d vehicles currently on road.\n", currentFlow + numEmergencyVehicles);
      } else {
        printf("NO CARS ON ROAD. %d vehicles currently on road.\n", currentFlow + numEmergencyVehicles);
      }
    }

    // Increment minute
    currentMinute += 1;
  }

  printf("Simulation over. %d vehicles on road at end of simulation.", currentFlow + numEmergencyVehicles);

  return 0;
}