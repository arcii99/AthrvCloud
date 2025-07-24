//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LANE_LENGTH 20
#define MAX_CARS 5
#define UPDATE_INTERVAL 2 // in seconds

typedef struct { // represents a car
  int speed;
  int position;
} Car;

int main() {
  Car lane[LANE_LENGTH] = {0}; // initialize lane with 0 cars
  int num_cars = 0;
  int ticks = 0;
  srand(time(NULL));
  
  while(1) {
    // Add new cars randomly
    if (rand() % 2 == 0 && num_cars < MAX_CARS) {
      lane[0] = (Car) {1 + rand() % 4, 0}; // add car with random speed (1-4) at beginning of lane
      num_cars++;
    }
    
    // Update car positions
    for (int i = LANE_LENGTH - 1; i >= 0; i--) {
      if (lane[i].speed > 0) { // car exists in this position
        if (i + lane[i].speed >= LANE_LENGTH) { // car would go off the end of the lane
          lane[i] = (Car) {0, 0};
          num_cars--;
        } else {
          lane[i + lane[i].speed] = lane[i];
          lane[i] = (Car) {0, 0};
        }
      }
    }
    
    // Print current lane state
    printf("Tick %d\n", ticks++);
    for (int i = 0; i < LANE_LENGTH; i++) {
      if (lane[i].speed > 0) {
        printf("%d", lane[i].speed);
      } else {
        printf("-");
      }
    }
    printf("\n");
    
    // Wait for update interval
    sleep(UPDATE_INTERVAL);
  }
  
  return 0;
}