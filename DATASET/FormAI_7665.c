//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

#define NUM_CARS 10
#define MAX_SPEED 5
#define ROAD_LENGTH 100

typedef struct {
  int position;
  int speed;
} Car;

int main() {
  Car cars[NUM_CARS];
  int i, j, k;
  
  // Initialize cars randomly
  for(i = 0; i < NUM_CARS; i++) {
    cars[i].position = rand() % ROAD_LENGTH;
    cars[i].speed = rand() % MAX_SPEED + 1;
  }
  
  // Main simulation loop
  for(k = 0; k < 1000; k++) {
    // Move each car forward
    for(i = 0; i < NUM_CARS; i++) {
      // Check if the car can move forward without colliding
      for(j = i+1; j < NUM_CARS; j++) {
        if(cars[i].position + cars[i].speed >= cars[j].position) {
          cars[i].speed = cars[j].speed - 1; // Adjust speed to avoid collision
          break;
        }
      }
      
      // Move the car forward
      cars[i].position += cars[i].speed;
      if(cars[i].position >= ROAD_LENGTH) {
        cars[i].position -= ROAD_LENGTH;
      }
    }
    
    // Print the current state of the road
    for(i = 0; i < ROAD_LENGTH; i++) {
      int car_index = -1;
      for(j = 0; j < NUM_CARS; j++) {
        if(cars[j].position == i) {
          car_index = j;
          break;
        }
      }
      if(car_index != -1) {
        printf("X");
      } else {
        printf("_");
      }
    }
    printf("\n");
  }
  
  return 0;
}