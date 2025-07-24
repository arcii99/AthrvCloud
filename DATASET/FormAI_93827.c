//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // Seed random number generator
  int invasion_prob = rand() % 101; // Generate random invasion probability (0-100)

  if(invasion_prob > 50) {
    printf("ALERT! ALIEN INVASION PROBABILITY IS %d%%.\n", invasion_prob);
    printf("Run for your lives!\n");
  } else {
    printf("Phew! Alien invasion probability is only %d%%.\n", invasion_prob);
    printf("We can relax for now.\n");
  }

  return 0;
}