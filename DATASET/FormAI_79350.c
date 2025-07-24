//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 50
#define MAX_ROADS 5
#define MAX_LANE 3

// This program generates a surrealistic simulation of traffic flow

typedef struct Car {
  int id;
  int lane;
  int speed;
  int distance;
} Car;

typedef struct Road {
  int length;
  int lanes;
  int grid[MAX_LANE][MAX_CARS]; // grid[x][y] = id_car or -1 (empty)
} Road;

int update_position(Car* car, Road* road, int delta);
void generate_cars(Road* road);
void print_road(Road* road);

int main() {
  Road roads[MAX_ROADS];
  srand(time(NULL));

  // initialize roads
  for (int i = 0; i < MAX_ROADS; i++) {
    roads[i].length = rand() % 50 + 50;
    roads[i].lanes = rand() % 2 + 2;
    for (int j = 0; j < MAX_LANE; j++) {
      for (int k = 0; k < MAX_CARS; k++) {
        roads[i].grid[j][k] = -1;
      }
    }
  }

  while (1) {
    // generate new cars on each road
    for (int i = 0; i < MAX_ROADS; i++) {
      generate_cars(&roads[i]);
    }

    // move cars on each road
    for (int i = 0; i < MAX_ROADS; i++) {
      for (int j = 0; j < roads[i].lanes; j++) {
        for (int k = 0; k < MAX_CARS; k++) {
          if (roads[i].grid[j][k] != -1) {
            Car* car = (Car*) malloc(sizeof(Car));
            car->id = roads[i].grid[j][k];
            car->lane = j;
            car->distance = k;
            car->speed = rand() % 5 + 5;
            int delta = rand() % 3 + 1;
            int new_position = update_position(car, &roads[i], delta);
            roads[i].grid[j][k] = -1;
            if (new_position >= roads[i].length) {
              free(car);
            } else {
              car->distance = new_position;
              roads[i].grid[j][new_position] = car->id;
            }
          }
        }
      }
    }

    // print current road state
    system("clear");
    for (int i = 0; i < MAX_ROADS; i++) {
      printf("Road %d:\n", i+1);
      print_road(&roads[i]);
      printf("\n");
    }

    // wait a moment
    for (long int i = 0; i < 150000000; i++);

  }

  return 0;
}

int update_position(Car* car, Road* road, int delta) {
  int new_position = car->distance + car->speed * delta;
  if (new_position >= road->length) {
    new_position = road->length - 1;
  } else {
    for (int i = car->distance+1; i < new_position; i++) {
      if (road->grid[car->lane][i] != -1) {
        new_position = i - 1;
        break;
      }
    }
  }
  return new_position;
}

void generate_cars(Road* road) {
  for (int i = 0; i < road->lanes; i++) {
    if (road->grid[i][0] == -1) {
      int id_car = rand() % 900 + 100;
      road->grid[i][0] = id_car;
    }
  }
}

void print_road(Road* road) {
  for (int i = 0; i < road->lanes; i++) {
    for (int j = 0; j < road->length; j++) {
      if (road->grid[i][j] == -1) {
        printf("_");
      } else {
        printf("%d", road->grid[i][j] % 10);
      }
    }
    printf("\n");
  }
}