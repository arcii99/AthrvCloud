//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // set random seed

  int traffic_lights[4] = {0, 0, 0, 0}; // red light = 0, green light = 1
  int cars_waiting[4] = {0, 0, 0, 0}; // number of cars waiting at each intersection
  int car_counter = 0; // count the number of cars passing through

  printf("Welcome to the Surrealist Traffic Flow Simulation\n");

  while (1) {
    printf("\nTime: %d\n", car_counter);

    // randomly change traffic lights
    for (int i = 0; i < 4; i++) {
      int r = rand() % 10;
      if (r == 0) traffic_lights[i] = (traffic_lights[i] == 0) ? 1 : 0; // change light
    }

    // randomly add cars to each intersection
    for (int i = 0; i < 4; i++) {
      int r = rand() % 10;
      if (r == 0) cars_waiting[i] += 1; // add car
    }

    // let cars pass through intersections
    for (int i = 0; i < 4; i++) {
      if (traffic_lights[i] == 1) {
        int r = rand() % (cars_waiting[i] + 1);
        if (r > 0) {
          printf("Car %d passes through Intersection %d\n", car_counter, i+1);
          cars_waiting[i] -= 1;
          car_counter += 1;
        }
      }
    }
    sleep(1); // wait for 1 second
  }

  return 0;
}