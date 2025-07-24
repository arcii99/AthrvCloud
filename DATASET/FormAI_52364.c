//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ALIEN_PROB_THRESHOLD 75
#define MAX_NUM_ALIENS 1000
#define MAX_NUM_DAYS 100

void initializeRandomGenerator() {
  srand(time(NULL));
}

int getRandomIntInRange(int min, int max) {
  return (rand() % (max - min + 1)) + min;
}

int calculateAlienProbability(int numDays) {
  int probability = 0;
  for (int i = 0; i < numDays; i++) {
    probability += getRandomIntInRange(1, 20);
  }
  return probability;
}

int calculateNumAliens(int probability) {
  int numAliens = 0;
  if (probability >= ALIEN_PROB_THRESHOLD) {
    numAliens = getRandomIntInRange(1, MAX_NUM_ALIENS);
  }
  return numAliens;
}

void printResults(int numDays, int probability, int numAliens) {
  printf("After %d days, the probability of an alien invasion is %d percent.\n", numDays, probability);
  if (numAliens > 0) {
    printf("A total of %d aliens have invaded Earth!\n", numAliens);
  } else {
    printf("No aliens have invaded Earth today.\n");
  }
}

int main() {
  int numDays = getRandomIntInRange(1, MAX_NUM_DAYS);
  initializeRandomGenerator();
  int probability = calculateAlienProbability(numDays);
  int numAliens = calculateNumAliens(probability);
  printResults(numDays, probability, numAliens);
  return 0;
}