//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));   // seeding random number generator with current time
  int count_cars = 0;   // variable to count the number of cars that pass through simulation
  int time = 0;   // variable to keep track of simulation time

  // loop that simulates traffic flow for 20 seconds
  while (time < 20) {
    int num_cars = rand() % 10 + 1;   // generating random number of cars for each second (between 1 and 10)
    printf("Time: %d seconds\n", time);   // printing current simulation time

    // loop that simulates the movement of cars during each second
    for (int i = 0; i < num_cars; i++) {
      int speed = rand() % 40 + 20;   // generating random speed for each car (between 20 and 60 mph)
      int distance = speed;   // variable to keep track of distance traveled by car during the second
      int time_remaining = 1;   // variable to keep track of time remaining for the car's movement in the current second

      // loop that simulates the movement of the car during the current second
      while (time_remaining > 0) {
        printf("Car %d: %d mph (%d feet traveled)\n", i+1, speed, distance);   // printing car's speed and distance traveled
        distance += speed;   // updating distance traveled by car
        time_remaining--;   // decrementing time remaining for car's movement in the current second
      }

      count_cars++;   // incrementing car count
    }

    printf("\n");
    time++;   // incrementing simulation time
  }

  printf("%d cars passed through the simulation in 20 seconds.\n", count_cars);   // printing final car count
  
  return 0;
}