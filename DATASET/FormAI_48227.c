//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double calculateProbability(int aliens, int people) {
  double probability;
  if (aliens == 0) {
    probability = 0;
  } else if (people == 0) {
    probability = 1;
  } else {
    probability = aliens * 1.0 / (aliens + people);
  }
  return probability;
}

int main() {
  srand(time(NULL));

  int aliens = rand() % 100 + 1;
  int people = rand() % 1000 + 1;
  double probability = calculateProbability(aliens, people);

  printf("Aliens: %d\n", aliens);
  printf("People: %d\n", people);
  printf("Probability of alien invasion: %.2f\n", probability);

  return 0;
}