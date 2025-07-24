//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  printf("Welcome to the Alien Invasion Probability Calculator!\n");

  int pop, military, tech;
  float prob;

  printf("\nEnter the population of your city: ");
  scanf("%d", &pop);

  printf("\nEnter the number of military personnel defending your city: ");
  scanf("%d", &military);

  printf("\nEnter the level of technology your city has (1-10): ");
  scanf("%d", &tech);

  srand(time(NULL));
  int randNum = rand() % 101; // generate a random number between 0 and 100

  if (tech > 5) {
    prob = ((float)military/pop) * (randNum/100.0) * ((float)tech/10); // high tech cities have a better chance of defending against alien invasion
  } else {
    prob = ((float)military/pop) * (randNum/100.0); // low tech cities have a lower chance of defending against alien invasion
  }

  printf("\nBased on the information you provided, the probability of your city surviving an alien invasion is %f%%.\n", prob*100);

  if (prob > 0.5) {
    printf("\nCongratulations, your city has a good chance of surviving an alien invasion! But don't let your guard down, keep up the defense!\n");
  } else {
    printf("\nOh no, your city has a low chance of surviving an alien invasion... You might want to consider evacuating or upgrading your defense technology.\n");
  }

  return 0;
}