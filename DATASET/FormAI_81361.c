//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 1000
#define MAX_SPEED 60
#define MAX_SECONDS 7200

int main() {
  int i, j, t;
  int cars[MAX_CARS][MAX_SECONDS] = {0};
  int num_cars = 0;
  int count_cars = 0;

  srand(time(0));
  
  // generate random cars
  for (t = 0; t < MAX_SECONDS; t+=10) {
    if (num_cars < MAX_CARS && rand() % 10 == 0) {
      cars[num_cars][t] = 1;
      num_cars++;
    }
  }

  // simulate traffic flow
  for (t = 0; t < MAX_SECONDS; t+=10) {
    count_cars = 0;
    for (i = 0; i < num_cars; i++) {
      if (cars[i][t] == 1) {
        cars[i][t] = 0;
        // check if car can move forward
        if (t == 0) {
          cars[i][t+10] = 1;
        }
        else {
          for (j = t-1; j >= 0; j-=10) {
            if (cars[i][j] == 0 && ((t-j)*6) <= MAX_SPEED) {
              cars[i][j] = 1;
              break;
            }
          }
          if (j < 0) {
            cars[i][t] = 1;
          }
        }
      }
      if (cars[i][t] == 1) {
        count_cars++;
      }
    }
    printf("time: %d, num_cars: %d, count_cars: %d\n", t, num_cars, count_cars);
  }
  
  return 0;
}