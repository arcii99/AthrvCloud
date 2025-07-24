//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10
#define MAX_SPEED 60
#define ROAD_LENGTH 100

typedef struct {
  int position, speed;
} Car;

Car cars[MAX_CARS];
int carsCount = 0;

void moveCars(int timeElapsed) {
  for(int i = 0; i < carsCount; i++) {
    cars[i].position += cars[i].speed * timeElapsed / 60;
    cars[i].speed = (cars[i].speed + rand() % 2) % (MAX_SPEED + 1);
    if(cars[i].position > ROAD_LENGTH) {
      carsCount--;
      for(int j = i; j < carsCount; j++) {
        cars[j] = cars[j + 1];
      }
    }
  }
}

void showRoad() {
  for(int i = 0; i < ROAD_LENGTH; i++) {
    int carIndex = -1;
    for(int j = 0; j < carsCount; j++) {
      if(cars[j].position == i) {
        carIndex = j;
        break;
      }
    }
    if(carIndex != -1) {
      printf("C");
    } else {
      printf("-");
    }
  }
  printf("\n");
}

int main() {
  srand(time(NULL));
  
  while(carsCount < MAX_CARS) {
    int newPos = rand() % ROAD_LENGTH;
    int overlaps = 0;
    for(int i = 0; i < carsCount; i++) {
      if(abs(cars[i].position - newPos) <= 3) {
        overlaps++;
      }
    }
    if(!overlaps) {
      cars[carsCount].position = newPos;
      cars[carsCount].speed = rand() % (MAX_SPEED + 1);
      carsCount++;
    }
  }
  
  int timeElapsed = 0;
  
  while(carsCount > 0) {
    printf("Time elapsed: %d\n", timeElapsed);
    showRoad();
    moveCars(1);
    timeElapsed++;
    if(timeElapsed > 100) {
      printf("Simulation timed out\n");
      return 1;
    }
  }
  
  printf("All cars have left the simulation\n");
  
  return 0;
}