//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROADS 4
#define ROAD_LENGTH 20

int traffic[NUM_ROADS][ROAD_LENGTH];

void print_traffic() {
  for (int i = 0; i < ROAD_LENGTH; i++) {
    for (int j = 0; j < NUM_ROADS; j++) {
      printf("%c ", traffic[j][i] == 1 ? '*' : '-');
    }
    printf("\n");
  }
}

void move_cars() {
  for (int i = ROAD_LENGTH - 1; i >= 0; i--) {
    for (int j = 0; j < NUM_ROADS; j++) {
      if (traffic[j][i] == 1) {
        if (i == ROAD_LENGTH - 1) {
          traffic[j][i] = 0;
        } else {
          traffic[j][i+1] = 1;
          traffic[j][i] = 0;
        }
      }
    }
  }
}

void generate_cars() {
  for (int i = 0; i < NUM_ROADS; i++) {
    if (rand() % 2 == 1) {
      traffic[i][0] = 1;
    }
  }
}

int main() {
  srand(time(NULL));

  for (int i = 0; i < NUM_ROADS; i++) {
    for (int j = 0; j < ROAD_LENGTH; j++) {
      traffic[i][j] = 0;
    }
  }

  int tick = 0;
  while (tick < 50) {
    generate_cars();
    move_cars();
    printf("Tick %d:\n", tick);
    print_traffic();
    printf("\n");
    tick++;
    usleep(500000);
  }

  return 0;
}