//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  srand(time(NULL)); // Set random seed using current time
  int alienProb = rand() % 101; // Generate random integer from 0 to 100 for alien invasion probability
  printf("Welcome to the Alien Invasion Probability Calculator!\n\n");

  if(alienProb == 0) // No chance of alien invasion
  {
    printf("There is a 0%% chance of an alien invasion. Phew, we're safe!\n");
  }
  else if(alienProb > 0 && alienProb <= 25) // Low chance of alien invasion
  {
    printf("There is a %d%% chance of an alien invasion. It's always good to be prepared, just in case!\n", alienProb);
  }
  else if(alienProb > 25 && alienProb <= 50) // Moderate chance of alien invasion
  {
    printf("There is a %d%% chance of an alien invasion. We should start brainstorming strategies now!\n", alienProb);
  }
  else // High chance of alien invasion
  {
    printf("There is a %d%% chance of an alien invasion. WE MUST PREPARE FOR THE WORST!\n", alienProb);
  }

  return 0;
}