//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 80
#define DISTANCE_BETWEEN_CARS 10
#define NUM_CARS 10
#define SIMULATION_TIME 60

int main() {
  srand(time(NULL)); // set seed for randomness

  // initialize the positions and speeds of cars
  int positions[NUM_CARS];
  int speeds[NUM_CARS];
  for (int i = 0; i < NUM_CARS; i++) {
    positions[i] = i * DISTANCE_BETWEEN_CARS;
    speeds[i] = rand() % MAX_SPEED + 1;
  }

  // run the simulation
  for (int t = 0; t < SIMULATION_TIME; t++) {
    // print the current positions of the cars
    printf("Time %d:\n", t);
    for (int i = 0; i < NUM_CARS; i++) {
      printf("Car %d: %d\n", i, positions[i]);
    }
    printf("\n");

    // update the positions of the cars
    for (int i = 0; i < NUM_CARS; i++) {
      // calculate the distance to the car in front
      int distance_to_car_in_front = NUM_CARS * DISTANCE_BETWEEN_CARS;
      for (int j = 0; j < NUM_CARS && j != i; j++) {
        int distance = positions[j] - positions[i];
        if (distance > 0 && distance < distance_to_car_in_front) {
          distance_to_car_in_front = distance;
        }
      }

      // calculate the new speed of the car
      int new_speed = speeds[i];
      if (distance_to_car_in_front < MAX_SPEED) {
        new_speed = distance_to_car_in_front;
      }
      if (new_speed > speeds[i]) {
        new_speed--;
      }

      // update the position of the car
      positions[i] += new_speed;
      speeds[i] = new_speed;
    }
  }

  return 0;
}