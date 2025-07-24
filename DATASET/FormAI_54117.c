//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));
  int days = rand() % 365;
  int probability = rand() % 101;

  printf("There is a %d%% chance an alien invasion will happen in the next %d days.\n", probability, days);

  return 0;
}