//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 100
#define MAX_SPEED 120
#define MIN_DISTANCE 5

void simulate_traffic(int num_cars, int road_length) {
  int speed[MAX_CARS];
  int distance[MAX_CARS];
  int position[MAX_CARS];
  int i, j, t;

  // Initialize cars at random speed and distance
  srand(time(NULL));
  for (i = 0; i < num_cars; i++) {
    speed[i] = rand() % MAX_SPEED + 1;
    distance[i] = rand() % (road_length - MIN_DISTANCE) + MIN_DISTANCE;
    position[i] = distance[i];
  }

  // Simulate traffic for 1 hour
  for (t = 0; t < 60 * 60; t++) {
    // Update car positions and distances
    for (i = 0; i < num_cars; i++) {
      position[i] += speed[i];
      distance[i] = position[(i + 1) % num_cars] - position[i];
    }

    // Adjust speeds based on distances
    for (i = 0; i < num_cars; i++) {
      for (j = i + 1; j < num_cars; j++) {
        if (distance[i] < distance[j]) {
          if (speed[i] > speed[j]) {
            speed[i]--;
            speed[j]++;
          }
        } else {
          if (speed[i] < speed[j]) {
            speed[i]++;
            speed[j]--;
          }
        }
      }
    }

    // Print current state of traffic
    printf("Time: %d seconds\n", t);
    printf("+");
    for (i = 0; i < road_length; i++) {
      printf("-");
    }
    printf("+\n");
    for (i = 0; i < num_cars; i++) {
      printf("|");
      for (j = 0; j < position[i]; j++) {
        printf(" ");
      }
      printf("*");
      for (j = position[i] + 1; j < road_length; j++) {
        printf(" ");
      }
      printf("|\n");
    }
    printf("+");
    for (i = 0; i < road_length; i++) {
      printf("-");
    }
    printf("+\n");

    // Wait for 1 second before next iteration
    sleep(1);
  }
}

int main() {
  int num_cars = 10;
  int road_length = 50;
  simulate_traffic(num_cars, road_length);
  return 0;
}