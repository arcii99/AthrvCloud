//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10          // maximum number of cars that can be on the road
#define MAX_SPEED 60         // maximum speed of a car in mph
#define ROAD_LENGTH 5280     // length of the road in feet
#define SIMULATION_DURATION 60  // duration of the simulation in seconds
#define CAR_WIDTH 6          // width of the car in feet

int cars_on_road = 0;        // number of cars currently on the road

// function to generate a random speed for each car
int generate_speed() {
  return (rand() % MAX_SPEED) + 1;
}

// function to simulate a car's movement on the road
void move_car(int position, int speed) {
  int i;
  for (i = 0; i < speed / 2; i++) {
    printf(" ");
  }
  printf("o");
  for (i = 0; i < speed / 2 - 1; i++) {
    printf(" ");
  }
  printf("\n");
}

int main() {
  int i, j;
  int positions[MAX_CARS];      // array to store position of each car
  int speeds[MAX_CARS];         // array to store speed of each car
  int next_car_position = 0;    // position of next car to be added to the road
  int seconds = 0;              // current second of the simulation

  srand(time(NULL));            // seed the random number generator

  // print the initial state of the road
  printf("\nRoad at time 0: \n\n");
  for (i = 0; i < ROAD_LENGTH / CAR_WIDTH; i++) {
    printf("-");
  }
  printf("\n\n");

  // main simulation loop
  while (seconds < SIMULATION_DURATION) {
    // add a new car to the road if there's room and the interval is right
    if (cars_on_road < MAX_CARS && next_car_position < ROAD_LENGTH) {
      positions[cars_on_road] = next_car_position;
      speeds[cars_on_road] = generate_speed();
      next_car_position += speeds[cars_on_road] * CAR_WIDTH;
      cars_on_road++;
    }

    // print the current state of the road
    printf("Road at time %d: \n\n", seconds);
    for (i = 0; i < cars_on_road; i++) {
      for (j = 0; j < positions[i] / CAR_WIDTH; j++) {
        printf("-");
      }
      move_car(positions[i], speeds[i]);
    }
    printf("\n\n");

    // update the position of each car
    for (i = 0; i < cars_on_road; i++) {
      positions[i] += speeds[i] * CAR_WIDTH;
      if (positions[i] >= ROAD_LENGTH) {
        cars_on_road--;    // remove car from the road when it reaches the end
        positions[i] = -1;
      }
    }

    // move time forward by 1 second
    seconds++;
  }

  return 0;
}