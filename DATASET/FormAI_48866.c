//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int recursive_traffic_flow(int num_cars, int num_lanes) {
  // Base case: if there are no cars, traffic flow is 0
  if (num_cars == 0) {
    return 0;
  }
  // Recursive case: simulate traffic flow for each lane
  else {
    int total_flow = 0;
    for (int i = 0; i < num_lanes; i++) {
      // Generate random car speed between 20 and 80 mph
      int speed = rand() % 61 + 20;
      // Calculate traffic flow for the lane
      int flow = speed / (2 * num_cars);
      // Add lane flow to total traffic flow
      total_flow += flow;
    }
    // Simulate traffic flow for remaining cars on all lanes
    return total_flow + recursive_traffic_flow(num_cars - num_lanes, num_lanes);
  }
}

int main() {
  // Seed random number generator with system time
  srand(time(NULL));
  // Set number of cars and lanes
  int num_cars = 100;
  int num_lanes = 4;
  // Simulate traffic flow recursively
  int traffic_flow = recursive_traffic_flow(num_cars, num_lanes);
  // Output total traffic flow
  printf("Total traffic flow: %d\n", traffic_flow);
  return 0;
}