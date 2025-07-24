//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int numCars = 0, numBikes = 0, numTrucks = 0;
  int maxVehicles = 20;
  
  srand(time(NULL)); // Initialize random seed
  
  printf("Simulating traffic flow...\n");
  
  while (numCars + numBikes + numTrucks < maxVehicles) {
    int randNum = rand() % 3; // Generate random number between 0-2
    
    switch (randNum) {
      case 0:
        if (numCars < 5) {
          numCars++;
          printf("Added car to traffic flow.\n");
        }
        break;
      case 1:
        if (numBikes < 10) {
          numBikes++;
          printf("Added bike to traffic flow.\n");
        }
        break;
      case 2:
        if (numTrucks < 5) {
          numTrucks++;
          printf("Added truck to traffic flow.\n");
        }
        break;
    }
  }
  
  printf("Traffic simulation complete.\n");
  printf("Total vehicles: %d (Cars: %d, Bikes: %d, Trucks: %d)\n", numCars + numBikes + numTrucks, numCars, numBikes, numTrucks);
  
  return 0;
}