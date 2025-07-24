//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LANES 3
#define SIM_TIME 60
#define MAX_CARS_NEEDED 50

int main()
{
  printf("Starting Traffic Flow Simulation\n");
  
  // Initialize random number generator.
  srand(time(NULL));
  
  // Initialize variables.
  int lane[LANES] = {0};
  int carsAdded = 0;
  int carsRemoved = 0;
  int time = 0;
  int totalCarsStopped = 0;
  
  printf("Time\tLane 1\tLane 2\tLane 3\tCars Stopped\n");
  
  while (time < SIM_TIME || carsRemoved < carsAdded) {
    // Generate a random number between 0 and 1.
    int r = rand() % 2;
    
    // If r is 0, a car is added to the lane with the fewest cars.
    // If r is 1, no car is added.
    if (r == 0 && carsAdded < MAX_CARS_NEEDED) {
      // Find the lane with the fewest cars.
      int minLane = 0;
      for (int i = 1; i < LANES; i++) {
        if (lane[i] < lane[minLane]) {
          minLane = i;
        }
      }
      
      // Add a car to the lane with the fewest cars.
      lane[minLane]++;
      carsAdded++;
    }
    
    // Remove a car from each lane if there is one.
    for (int i = 0; i < LANES; i++) {
      if (lane[i] > 0) {
        lane[i]--;
        carsRemoved++;
        totalCarsStopped += lane[i];
      }
    }
    
    // Print out the lane information.
    printf("%d\t%d\t%d\t%d\t%d\n", time, lane[0], lane[1], lane[2], totalCarsStopped);
    
    // Increment the time.
    time++;
  }
  
  printf("Simulation complete\n");
  
  return 0;
}