//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: safe
/* This C program is a traffic flow simulation example that demonstrates how 
   cars move through a two-lane road system with a traffic light at a 
   busy intersection. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 50  // maximum number of cars on the road
#define TIME_DELAY 1000  // time delay in milliseconds

int main() {
  int num_cars = 0, time_elapsed = 0;
  /* The lane arrays hold the location of each car in that lane. Each element in 
     the array represents a segment of the lane where each car can fit. */
  int left_lane[MAX_CARS] = {0}, right_lane[MAX_CARS] = {0};
  int traffic_light = 0;  // 0 means green light, 1 means red light
  srand(time(NULL));  // initialize random seed

  /* main traffic flow loop */
  while (1) {
    /* generate a new car with probability of 1/4 every 2 seconds */
    if (rand() % 4 == 0 && num_cars < MAX_CARS) {
      right_lane[num_cars] = 0;
      num_cars++;
      printf("New car added in right lane\n");
    }
    /* move all the cars forward one segment if there is no car in front */
    for (int i = 0; i < num_cars; i++) {
      if (right_lane[i] != MAX_CARS - 1) {
        if (right_lane[i] + 1 == left_lane[i]) { // check collision
          printf("CRASH! Car %i collided with left lane car\n", i);
          exit(0);
        }
        right_lane[i]++;
        printf("Car %i moved forward in right lane\n", i);
      }
    }
    /* check traffic light and switch it every 10 seconds */
    if (time_elapsed % 10 == 0) {
      if (traffic_light == 0) {
        traffic_light = 1;
        printf("Traffic light turned red\n");
      }
      else {
        traffic_light = 0;
        printf("Traffic light turned green\n");
      }
    }
    /* move all the cars waiting at the red light forward when the light turns green */
    if (traffic_light == 0) {
      for (int i = 0; i < num_cars; i++) {
        if (right_lane[i] == 0) {
          if (i == 0 || right_lane[i-1] != 1) {
            right_lane[i]++;
            printf("Car %i moved forward on green light\n", i);
          }
        }
      }
    }
    /* print out current traffic flow status */
    printf("============================\n");
    printf("Number of cars: %i\n", num_cars);
    printf("Traffic Light: %s\n", (traffic_light == 0 ? "Green" : "Red"));
    printf("Right Lane: ");
    for (int i = 0; i < num_cars; i++) {
      printf("%i ", right_lane[i]);
    }
    printf("\n");
    printf("Left Lane: ");
    for (int i = 0; i < num_cars; i++) {
      printf("%i ", left_lane[i]);
    }
    printf("\n");
    printf("============================\n");
    /* sleep for the time delay in milliseconds */
    struct timespec t;
    t.tv_sec = 0;
    t.tv_nsec = TIME_DELAY * 1000000;
    nanosleep(&t, NULL);
    time_elapsed++;
  }

  return 0;
}