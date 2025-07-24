//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int aliens; // number of aliens
  int days; // number of days
  double probability; // probability of invasion
  double rand_num;

  srand(time(NULL)); // seed random number generator with current time

  printf("ALIEN INVASION PROBABILITY CALCULATOR\n");
  printf("------------------------------------\n\n");

  printf("Enter the number of aliens: ");
  scanf("%d", &aliens);

  printf("Enter the number of days: ");
  scanf("%d", &days);

  probability = ((double) aliens * days) / RAND_MAX;

  rand_num = ((double) rand() / RAND_MAX);

  if (rand_num < probability) {
    printf("\nALERT: Alien invasion is probable.\n");
  } else {
    printf("\nNo immediate threat of alien invasion.\n");
  }

  return 0;
}