//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(0)); // seed the random generator with the current time

  int invasion_probability = rand() % 101; // generate a number between 0 and 100

  printf("Welcome to the Alien Invasion Probability Calculator!\n\n");

  printf("Based on our analysis, the probability of an alien invasion is %d%%.\n\n", invasion_probability);

  if (invasion_probability < 25) {
    printf("Looks like we're safe from an alien invasion for now.\n");
  } else if (invasion_probability < 50) {
    printf("There's a small chance of an alien invasion, but it's unlikely.\n");
  } else if (invasion_probability < 75) {
    printf("An alien invasion is possible, but it's not very probable.\n");
  } else {
    printf("The probability of an alien invasion is high. We need to prepare for the worst.\n");
  }

  return 0;
}