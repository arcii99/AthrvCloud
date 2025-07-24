//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 100 // maximum speed limit
#define MAX_DIST 500 // maximum distance between two cars
#define MAX_CARS 10 // maximum number of cars on road
#define ACCEL 2 // acceleration rate
#define BRAKE 4 // braking rate

int main() {
  int cars[MAX_CARS] = {0}; // initialize all cars to 0
  int speeds[MAX_CARS] = {0}; // initialize all speeds to 0
  srand(time(NULL)); // initialize random seed

  // populate cars with random distances
  for(int i = 0; i < MAX_CARS; i++) {
    cars[i] = rand() % MAX_DIST;
  }

  printf("Initial Cars' Distances:\n");
  for(int i = 0; i < MAX_CARS; i++) {
    printf("%d ", cars[i]);
  }

  printf("\n\nSimulation Start:\n");
  int time = 0;
  while(cars[MAX_CARS-1] < MAX_DIST) {
    time++; // increment time
    for(int i = MAX_CARS-1; i >= 0; i--) {

      // calculate speed based on distance from car ahead
      if(i == 0) {
        speeds[i] += ACCEL; // first car always accelerates
      } else {
        int dist = cars[i] - cars[i-1];
        if(speeds[i] >= dist) {
          speeds[i] = dist; // cannot go faster than car ahead
        } else if(speeds[i] > speeds[i-1] + BRAKE) {
          speeds[i] -= BRAKE; // brake if going too fast
        } else {
          speeds[i] += ACCEL; // accelerate if going too slow
        }
      }

      // move car based on speed
      if(speeds[i] > MAX_SPEED) {
        speeds[i] = MAX_SPEED; // cannot exceed speed limit
      }
      cars[i] += speeds[i];

      // print car location
      printf("%02d:%02d - ", time/60, time%60);
      for(int j = 0; j < MAX_CARS; j++) {
        if(cars[i] == cars[j] && i != j) {
          printf("X "); // collision occurred!
        } else if(cars[i] == cars[j] - 1 && i != j) {
          printf(">"); // too close for comfort
        } else {
          printf("- "); // road is clear
        }
      }
      printf("\n");

      // check for collision
      for(int j = 0; j < MAX_CARS; j++) {
        if(cars[i] == cars[j] && i != j) {
          printf("CAR %d collided with CAR %d\n", i+1, j+1);
          return 1; // exit program
        }
      }
    }
    printf("\n");
  }
  printf("All cars have reached their destination!\n");
  return 0; // exit program
}