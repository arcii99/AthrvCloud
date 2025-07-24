//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ALIEN_PROBABILITY 0.1 // chance of an alien invasion

void displayIntro(void);
float calculateAlienInvasionProbability(void);
int calculateNumberOfAlienShips(float probability);
void displayAlienInvasionDetails(int numberOfShips);

int main(void) {
  float probability;
  int numberOfShips;

  srand(time(NULL)); // seed random number generator

  displayIntro();

  probability = calculateAlienInvasionProbability();
  numberOfShips = calculateNumberOfAlienShips(probability);

  displayAlienInvasionDetails(numberOfShips);

  return 0;
}

void displayIntro(void) {
  printf("Welcome to the Alien Invasion Probability Calculator!\n\n");
  printf("This program will calculate the probability of an alien invasion\n");
  printf("and estimate the number of alien ships that would invade Earth.\n\n");
}

float calculateAlienInvasionProbability(void) {
  float probability = (float) rand() / RAND_MAX;

  printf("Calculating probability of alien invasion...\n");
  printf("Probability of alien invasion: %.2f\n\n", probability);

  return probability > ALIEN_PROBABILITY ? probability : 0;
}

int calculateNumberOfAlienShips(float probability) {
  int numberOfShips = (int) (probability * 100);

  printf("Calculating number of alien ships...\n");
  printf("Number of alien ships: %d\n\n", numberOfShips);

  return numberOfShips;
}

void displayAlienInvasionDetails(int numberOfShips) {
  if (numberOfShips > 0) {
    printf("ALERT! ALERT! ALIEN INVASION IMMINENT!\n");
    printf("Number of alien ships: %d\n", numberOfShips);
    printf("Take cover immediately!\n");
  } else {
    printf("Phew! No alien invasion today.\n");
  }
}