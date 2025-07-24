//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROADS 4
#define MAX_CARS 10
#define MAX_TIME 60

int main() {
  int roads[NUM_ROADS][MAX_TIME];
  int cars[MAX_CARS];
  int num_cars = 0;
  
  srand(time(NULL));
  
  // initialize roads to 0
  for (int i = 0; i < NUM_ROADS; i++) {
    for (int j = 0; j < MAX_TIME; j++) {
      roads[i][j] = 0;
    }
  }
  
  // randomly generate cars
  for (int i = 0; i < MAX_CARS; i++) {
    cars[i] = rand() % 4;
    num_cars++;
  }
  
  // simulate traffic flow
  for (int t = 0; t < MAX_TIME; t++) {
    printf("===== Time %d =====\n", t);
    
    // add cars to roads
    for (int i = 0; i < num_cars; i++) {
      int road = cars[i];
      if (roads[road][t] == 0) {
        roads[road][t] = 1;
        printf("Car %d added to road %d\n", i, road);
      } else {
        printf("Road %d is full, car %d is stuck\n", road, i);
      }
    }
    
    // move cars forward
    for (int i = 0; i < NUM_ROADS; i++) {
      for (int j = 0; j < MAX_TIME-1; j++) {
        if (roads[i][j] == 1) {
          if (roads[i][j+1] == 0) {
            roads[i][j] = 0;
            roads[i][j+1] = 1;
            printf("Car on road %d moved from %d to %d\n", i, j, j+1);
          } else {
            printf("Car on road %d at position %d is stuck\n", i, j);
          }
        }
      }
    }
    
    // remove cars from end of road
    for (int i = 0; i < NUM_ROADS; i++) {
      if (roads[i][MAX_TIME-1] == 1) {
        roads[i][MAX_TIME-1] = 0;
        printf("Car on road %d was removed\n", i);
      }
    }
    
    printf("\n");
  }
  
  return 0;
}