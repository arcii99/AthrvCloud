//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 20

int main() {
  int num_cars = 0, i = 0, j = 0, k = 0;
  int current_pos[MAX_CARS], next_pos[MAX_CARS];
  char road[MAX_CARS][MAX_CARS];

  srand(time(NULL));

  // Initialize road array with empty spaces
  for (i = 0; i < MAX_CARS; i++) {
    for (j = 0; j < MAX_CARS; j++) {
      road[i][j] = '.';
    }
  }

  // Add cars to the road
  num_cars = rand() % MAX_CARS;
  for (i = 0; i < num_cars; i++) {
    current_pos[i] = rand() % MAX_CARS;
    road[0][current_pos[i]] = 'C';
  }

  // Start simulation
  for (i = 0; i < MAX_CARS - 1; i++) {
    for (j = 0; j < MAX_CARS; j++) {
      if (road[i][j] == 'C') {
        // Move car forward
        if (j != MAX_CARS - 1) {
          next_pos[k] = j + 1;
          k++;
        }
      }
    }

    // Update road array with new car positions
    for (j = 0; j < num_cars; j++) {
      road[i+1][next_pos[j]] = 'C';
      road[i][current_pos[j]] = '.';
    }

    // Reset next_pos array
    for (j = 0; j < num_cars; j++) {
      next_pos[j] = 0;
    }

    // Print current state of the road
    for (j = 0; j < MAX_CARS; j++) {
      printf("%c", road[i][j]);
    }
    printf("\n");
  }

  return 0;
}