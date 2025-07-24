//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROAD_LENGTH 20
#define MAX_CARS 5

struct Car {
  int position;
  int speed;
};

void update_positions(struct Car * cars, int n) {
  int delta;
  for(int i=0; i<n; i++) {
    delta = cars[i].speed;
    for(int j=0; j<delta; j++) {
      if(cars[i].position+j+1 >= ROAD_LENGTH) {
        break;
      }
      cars[i].position++;
    }
  }
}

void update_speeds(struct Car * cars, int n) {
  int delta;
  for(int i=0; i<n; i++) {
    delta = (rand() % 3) - 1;
    cars[i].speed += delta;
    if(cars[i].speed < 0) cars[i].speed = 0;
  }
}

void print_road(struct Car * cars, int n) {
  for(int i=0; i<n; i++) {
    for(int j=0; j<cars[i].position; j++) {
      printf("-");
    }
    printf("C");
    for(int j=cars[i].position+1; j<ROAD_LENGTH; j++) {
      printf("-");
    }
    printf("\n");
  }
  for(int i=0; i<ROAD_LENGTH; i++) {
    printf("=");
  }
  printf("\n");
}

int main() {
  srand(time(NULL));
  struct Car cars[MAX_CARS];
  for(int i=0; i<MAX_CARS; i++) {
    cars[i].position = i*2;
    cars[i].speed = 0;
  }
  while(1) {
    printf("\033[2J\033[1;1H"); // clear screen
    update_speeds(cars, MAX_CARS);
    update_positions(cars, MAX_CARS);
    print_road(cars, MAX_CARS);
    sleep(1);
  }
  return 0;
}