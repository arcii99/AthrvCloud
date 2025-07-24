//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: post-apocalyptic
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {
  srand(time(NULL));
  int v1 = rand() % 3 + 1;
  int v2 = rand() % 3 + 1;
  int v3 = rand() % 3 + 1;
  int t = 10;
  printf("Starting Traffic Light Controller!\n\n");

  while (t > 0) {
    printf("Time left: %d seconds\n", t);

    if (v1 == 1) {
      printf("North-South traffic light is green\n");
    } else {
      printf("North-South traffic light is red\n");
    }

    if (v2 == 1) {
      printf("East-West traffic light is green\n");
    } else {
      printf("East-West traffic light is red\n");
    }

    if (v3 == 1) {
      printf("Pedestrian traffic light is green\n");
    } else {
      printf("Pedestrian traffic light is red\n");
    }

    printf("\n");

    t--;
    v1 = rand() % 3 + 1;
    v2 = rand() % 3 + 1;
    v3 = rand() % 3 + 1;
  }

  printf("Traffic Light Controller has ended!\n");

  return 0;
}