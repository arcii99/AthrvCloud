//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  srand(time(NULL)); // Initialize random seed
  
  int alien_ships = rand() % 1000 + 1; // Generate random number of alien ships
  int defense_guns = rand() % 50 + 1; // Generate random number of defense guns

  printf("ALIEN INVASION PROBABILITY CALCULATOR\n\n");
  
  printf("Number of Alien Ships: %d\n", alien_ships);
  printf("Number of Defense Guns: %d\n", defense_guns);

  printf("\nCalculating invasion probability...\n");

  // Calculate invasion probability
  float probability = (float) defense_guns / alien_ships;

  if (probability < 0.25)
  {
    printf("\n*** Invasion probability is low. There is minimal threat to the planet. ***\n");
  }
  else if (probability >= 0.25 && probability < 0.5)
  {
    printf("\n*** Invasion probability is moderate. There is some threat to the planet. ***\n");
  }
  else if (probability >= 0.5 && probability < 0.75)
  {
    printf("\n*** Invasion probability is high. There is significant threat to the planet. ***\n");
  }
  else
  {
    printf("\n*** Invasion probability is critical. The planet is in imminent danger. ***\n");
  }

  return 0;
}