//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROAD_LENGTH 10 // in meters
#define CAR_LENGTH 5 // in meters
#define MAX_CARS 50 // maximum number of cars

int road[ROAD_LENGTH]; // an array to represent the road as a series of cells
int num_cars = 0; // current number of cars on the road

void init_road() {
  for (int i = 0; i < ROAD_LENGTH; i++) {
    road[i] = -1; // -1 means the cell is empty
  }
}

void print_road() {
  for (int i = 0; i < ROAD_LENGTH; i++) {
    printf("%c ", (road[i] == -1) ? '_' : 'X'); // _ means empty cell, X means occupied cell
  }
  printf("\n");
}

void add_car() {
  if (num_cars < MAX_CARS) {
    int pos = rand() % ROAD_LENGTH;
    while (road[pos] != -1) {
      pos = rand() % ROAD_LENGTH;
    }
    road[pos] = CAR_LENGTH;
    num_cars++;
  }
}

void move_cars() {
  int cars_moved = 0;
  for (int i = ROAD_LENGTH - 1; i >= 0; i--) {
    if (road[i] == -1) {
      continue;
    }
    if (i + road[i] >= ROAD_LENGTH || road[i + road[i]] != -1) {
      road[i]--;
    } else {
      road[i + road[i]] = road[i];
      road[i] = -1;
      cars_moved++;
    }
  }
  num_cars -= cars_moved;
}

int main() {
  srand(time(NULL)); // seed the random number generator
  init_road();
  add_car();
  
  for (int i = 0; i < 10; i++) { // simulate 10 time steps
    print_road();
    move_cars();
    add_car(); // add a new car
  }
  
  return 0;
}