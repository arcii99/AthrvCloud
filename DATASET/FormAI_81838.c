//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int invasion_prob;
  
  srand((unsigned)time(NULL)); // initialize rand() function with the system time
  
  // Calculate probability of invasion using random numbers
  invasion_prob = (rand() % 100) + 1; // generate a random number between 1 to 100.
  printf("Probability of an alien invasion: %d%%\n", invasion_prob);
  
  if (invasion_prob >= 70) { // set probability threshold at 70%
    printf("Attention! There is a high probability of an alien invasion. Seek shelter immediately!\n");
  }
  else {
    printf("No immediate threat of an alien invasion detected.\n");
  }
  
  return 0;
}