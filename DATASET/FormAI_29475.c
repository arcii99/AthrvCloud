//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: beginner-friendly
/*
  Traffic Flow Simulation
  This program simulates the flow of vehicle traffic
  on a stretch of road with multiple lanes.

  The program uses two functions: generateTraffic() 
  and moveTraffic(), to simulate the movement of 
  vehicles through the road.

  Author: [Your Name]
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_SPEED 60 // Maximum speed limit in km/h
#define MIN_DISTANCE 10 // Minimum distance between vehicles
#define ROAD_LENGTH 1000 // Length of the road in meters

// Function to generate traffic
void generateTraffic(int lanes, int vehicles, int* positions, int* speeds) {
  int i;
  int laneLength = ROAD_LENGTH / lanes;
  int minGap = MIN_DISTANCE + (rand() % 5);
  int maxSpeed = MAX_SPEED - (rand() % 10);

  for(i = 0; i < vehicles; i++) {
    positions[i] = (rand() % laneLength) + (laneLength * (i % lanes));
    speeds[i] = maxSpeed - (rand() % 20);
    if(i >= lanes) {
      int j;
      for(j = i - lanes; j < i; j++) {
         if(abs(positions[i] - positions[j]) <= minGap) {
           i--;
           break;
         }
      }
    }
  }
}

// Function to move traffic
void moveTraffic(int lanes, int vehicles, int* positions, int* speeds) {
  int i;
  int laneLength = ROAD_LENGTH / lanes;
  int maxPosition = laneLength * lanes;

  for(i = 0; i < vehicles; i++) {
    positions[i] += speeds[i];
    if(positions[i] >= maxPosition) {
      positions[i] -= maxPosition;
    }
  }
}

// Main Function
int main() {
  srand(time(NULL)); // Set seed for random number generation

  int lanes = 3;
  int vehicles = 15;
  int positions[vehicles];
  int speeds[vehicles];

  generateTraffic(lanes, vehicles, positions, speeds);

  int iterations = 10;
  int i, j;

  for(i = 0; i < iterations; i++) {
    moveTraffic(lanes, vehicles, positions, speeds);

    int laneLength = ROAD_LENGTH / lanes;
    printf("\nIteration %d:", i+1);
    for(j = 0; j < lanes; j++) {
      printf("\nLane %d - ", j+1);
      int k;
      for(k = 0; k < vehicles; k++) {
        if(positions[k] >= (j * laneLength) && positions[k] < ((j+1) * laneLength)) {
          printf("%.2f ", (float)positions[k] / (float)laneLength);
        }
      }
    }
  }

  return 0;
}