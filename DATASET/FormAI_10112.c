//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROAD_LENGTH 100
#define CAR_DENSITY 0.3
#define MAX_SPEED 5
#define BRAKING_PROBABILITY 0.1

int main() {
  // Initializing the random number generator
  srand(time(NULL));

  // Initializing the variables representing the road and the cars
  int road[ROAD_LENGTH];
  int speeds[ROAD_LENGTH];

  // Generating the initial state of the road
  for (int i = 0; i < ROAD_LENGTH; i++) {
    speeds[i] = 0;
    if ((double)rand() / RAND_MAX < CAR_DENSITY) {
      speeds[i] = rand() % MAX_SPEED + 1;
    }
    road[i] = -1;
  }

  // Running the simulation
  for (int t = 0; t < 100; t++) {
    // Printing the current state of the road
    printf("t = %d\n", t);
    for (int i = 0; i < ROAD_LENGTH; i++) {
      if (speeds[i] > 0) {
        printf("%c", speeds[i] + '0');
      } else {
        printf("-");
      }
    }
    printf("\n");

    // Updating the speed of each car
    for (int i = 0; i < ROAD_LENGTH; i++) {
      if (speeds[i] > 0) {
        // Calculating the distance to the next car
        int d = 1;
        while (speeds[(i + d) % ROAD_LENGTH] == 0) {
          d++;
        }

        // Checking if the car should slow down
        if (speeds[i] < d && (double)rand() / RAND_MAX < BRAKING_PROBABILITY) {
          speeds[i]--;
        } else {
          speeds[i] = speeds[i] < MAX_SPEED ? speeds[i] + 1 : MAX_SPEED;
        }
      }
    }

    // Moving each car to its new position
    for (int i = 0; i < ROAD_LENGTH; i++) {
      if (speeds[i] > 0) {
        road[i] = -1;
        road[(i + speeds[i]) % ROAD_LENGTH] = i;
      }
    }
  }

  return 0;
}