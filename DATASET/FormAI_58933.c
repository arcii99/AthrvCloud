//FormAI DATASET v1.0 Category: Physics simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define GRAVITY 9.81 // constant gravitational acceleration

int main() {
  srand(time(NULL)); // seed random number generator with current time

  // define variables
  int height, time_elapsed, distance_fallen = 0;
  float initial_velocity;

  printf("Enter the height at which the object was dropped (in meters): ");
  scanf("%d", &height);

  printf("Enter the initial velocity of the object (in meters/second): ");
  scanf("%f", &initial_velocity);

  // calculate time required to reach ground
  time_elapsed = (int)(sqrt((2 * height) / GRAVITY));

  printf("The object will hit the ground after %d seconds.\n", time_elapsed);

  // simulate object falling
  for (int t = 0; t <= time_elapsed; t++) {
    int distance = (int)(0.5 * GRAVITY * t * t);
    if (distance > distance_fallen) {
      printf("Time elapsed: %2d seconds\tDistance fallen: %3d meters\n", t, distance);
      distance_fallen = distance;
    }
    // simulate drag force on object
    float drag_force = 0.2 * initial_velocity;
    float net_force = GRAVITY - drag_force;
    initial_velocity += net_force * 1; // update velocity due to net force
  }
  
  return 0;
}