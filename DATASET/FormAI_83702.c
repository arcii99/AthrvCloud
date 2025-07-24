//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(0));                    // Seed the random number generator
  int attack_chance = rand() % 100;  // Generate a random number between 0 and 99
  printf("ALIEN INVASION PROBABILITY CALCULATOR\n");
  printf("-------------------------------------\n");
  printf("The alien attack probability today is %d%%.\n", attack_chance);

  if (attack_chance >= 80) {
    printf("Warning! Imminent attack is highly likely.\n");
    printf("Please take shelter and be prepared for the worst.\n");
  } else if (attack_chance >= 50) {
    printf("Caution! The threat of an alien attack is moderate.\n");
    printf("Stay informed and be ready to take action if necessary.\n");
  } else {
    printf("No need to panic! The probability of an alien attack is low.\n");
    printf("Nevertheless, it is always wise to be prepared for any situation.\n");
  }

  return 0;
}