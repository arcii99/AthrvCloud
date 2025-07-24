//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int alien_prob, human_defense;
  srand(time(NULL));
  alien_prob = rand() % 100 + 1;
  human_defense = rand() % 100 + 1;
  printf("Welcome to the Alien Invasion Probability Calculator!\n");
  printf("Calculating the probability of an alien invasion...\n");
  printf("The probability of an alien invasion is %d%%\n", alien_prob);
  printf("Calculating human defense capability...\n");
  printf("Human defense capability is %d%%\n", human_defense);
  
  if (alien_prob < human_defense) {
    printf("Great news! The probability of an alien invasion is lower than our defense capability. We are safe for now.\n");
  }
  
  else if (alien_prob == human_defense) {
    printf("Uh oh, the probability of an alien invasion is just as strong as our defense capability. We need to start preparing for an invasion immediately.\n");
  }
  
  else {
    printf("Unfortunately, the probability of an alien invasion is stronger than our defense capability. We must prepare for an imminent attack.\n");
  }
  
  return 0;
}