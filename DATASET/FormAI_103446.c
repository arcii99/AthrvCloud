//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  srand(time(NULL));

  // Generate random base pairs
  char basePairs[1000];
  for (int i = 0; i < sizeof(basePairs) - 1; i++) {
    int randomNumber = rand() % 4;
    switch (randomNumber) {
      case 0:
        basePairs[i] = 'A';
        break;
      case 1:
        basePairs[i] = 'T';
        break;
      case 2:
        basePairs[i] = 'C';
        break;
      case 3:
        basePairs[i] = 'G';
        break;
    }
  }

  // Print out base pairs
  printf("Base pairs: %s\n", basePairs);

  // Generate mutations
  int numberOfMutations = rand() % 10 + 1;
  for (int i = 0; i < numberOfMutations; i++) {
    int randomIndex = rand() % sizeof(basePairs) - 1;
    int randomNumber = rand() % 4;
    switch (randomNumber) {
      case 0:
        basePairs[randomIndex] = 'A';
        break;
      case 1:
        basePairs[randomIndex] = 'T';
        break;
      case 2:
        basePairs[randomIndex] = 'C';
        break;
      case 3:
        basePairs[randomIndex] = 'G';
        break;
    }
  }

  // Print out mutated base pairs
  printf("Mutated base pairs: %s\n", basePairs);

  return 0;
}