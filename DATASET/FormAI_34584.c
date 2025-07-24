//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: energetic
#include <stdio.h>

int main() {
  // Initialize variables and constants
  int numCars = 50;
  int carSpeeds[numCars];
  int trafficDensity = 3;
  int numIterations = 100;
  int timer = 0;

  // Generate initial car speeds randomly
  for (int i=0; i<numCars; i++) {
    carSpeeds[i] = rand() % 30 + 20;
  }

  // Simulate traffic flow
  for (int i=0; i<numIterations; i++) {
    printf("Iteration %d\n", i+1);

    // Move cars forward
    for (int j=0; j<numCars; j++) {
      if (carSpeeds[j] > 0) {
        carSpeeds[j]--;
      }
    }

    // Randomly slow down cars based on traffic density
    for (int j=0; j<numCars-1; j++) {
      if (carSpeeds[j]/trafficDensity > carSpeeds[j+1]) {
        carSpeeds[j]--;
      }
    }

    // Add new cars to the simulation
    if (timer % 10 == 0) {
      numCars++;
      carSpeeds[numCars-1] = rand() % 30 + 20;
    }

    // Print car speeds for debugging
    for (int j=0; j<numCars; j++) {
      printf("Car %d: Speed %d\n", j+1, carSpeeds[j]);
    }

    // Increment timer
    timer++;
  }

  return 0;
}