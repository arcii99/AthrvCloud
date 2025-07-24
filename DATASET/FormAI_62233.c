//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: Donald Knuth
/* Traffic Flow Simulation Program */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROAD_LENGTH 100 // Max length of the road
#define MAX_SPEED 5 // max speed of car
#define T_DELAY 200 // Time delay between each iteration

int road[ROAD_LENGTH]; // array to store cars on the road

// function to initialize the road with cars
void initialize_road() {
  for(int i=0; i<ROAD_LENGTH; i++) {
    road[i] = rand()%2; // randomly place cars on the road
  }
}

// function to print the current state of the road
void print_road() {
  for(int i=0; i<ROAD_LENGTH; i++) {
    if(road[i]==1) {
      printf("C");
    } else {
      printf("-");
    }
  }
  printf("\n");
}

// function to move the cars on the road
void move_cars() {
  for(int i=0; i<ROAD_LENGTH; i++) {
    if(road[i]==1) {
      road[i] = 0; // remove the car from the current position
      int speed = rand()%MAX_SPEED;
      if(i + speed >= ROAD_LENGTH) {
        road[0] = 1; // place the car at the beginning of the road
      } else {
        road[i + speed] = 1; // place the car at the new position
      }
    }
  }
}

// main function
int main() {
  srand(time(0)); // Seed for random number generator
  initialize_road();
  while(1) { // simulation loop
    system("clear"); // clear the console
    print_road();
    move_cars();
    usleep(T_DELAY); // sleep for a short period of time
  }
  return 0;
}