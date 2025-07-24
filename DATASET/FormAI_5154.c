//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int num_of_aliens;
  float alien_invasion_probability;

  srand(time(0)); // seeding the random number generator with the current time

  printf("Welcome to the Alien Invasion Probability Calculator!\n");
  printf("Please enter the number of aliens you suspect may be coming: ");
  scanf("%d", &num_of_aliens);

  // generating a random probability based on the number of aliens
  if (num_of_aliens >= 1000) {
    alien_invasion_probability = (float)(rand() % 20) / 100.0; // 0.0-0.19
  } else if (num_of_aliens >= 500) {
    alien_invasion_probability = (float)(rand() % 10) / 100.0; // 0.0-0.09
  } else if (num_of_aliens >= 100) {
    alien_invasion_probability = (float)(rand() % 5) / 100.0; // 0.0-0.04
  } else if (num_of_aliens >= 10) {
    alien_invasion_probability = (float)(rand() % 2) / 100.0; // 0.0 or 0.01
  } else {
    alien_invasion_probability = 0.0; // no aliens, zero probability
  }

  printf("Based on the number of aliens you entered, the probability of an alien invasion is: %f\n", alien_invasion_probability);

  return 0;
}