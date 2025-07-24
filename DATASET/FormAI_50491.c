//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 100
#define MAX_SPEED 6
#define DISTANCE 100
#define CAR_LENGTH 3

typedef struct {
  int speed, position;
} Car;

int main(void) {
  srand(time(NULL));

  Car cars[MAX_CARS];
  int num_cars = 5 + rand() % MAX_CARS;

  for (int i = 0; i < num_cars; i++) {
    cars[i].speed = 2 + rand() % MAX_SPEED;
    cars[i].position = i * DISTANCE / num_cars;
  }

  for (int t = 0; t < 60; t++) {
    printf("Time: %d\n", t);
    for (int i = 0; i < num_cars; i++) {
      if (i == 0) {
        if (cars[i].speed < MAX_SPEED && cars[i].position < DISTANCE - CAR_LENGTH) {
          cars[i].speed++;
        }
      } else {
        int distance = cars[i-1].position - cars[i].position;
        if (distance < 0) {
          distance += DISTANCE;
        }
        if (distance < CAR_LENGTH) {
          cars[i].speed = cars[i-1].speed;
        } else if (cars[i].speed < MAX_SPEED && distance < cars[i].speed) {
          cars[i].speed = distance - 1;
        }
      }
      cars[i].position = (cars[i].position + cars[i].speed) % DISTANCE;
      printf("Car %d: %dkm/h, %dkm\n", i, cars[i].speed * 10, cars[i].position * 10);
    }
  }

  return 0;
}