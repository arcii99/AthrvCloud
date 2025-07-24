//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int alienShips = 0; // Number of alien ships
  float earthDefenses = 0.0; // Earth's defenses (%)
  int invasionProbability = 0; // Invasion probability (%)

  // Get user inputs
  printf("Enter the number of alien ships: ");
  scanf("%d", &alienShips);

  printf("Enter Earth's defenses (0-100): ");
  scanf("%f", &earthDefenses);

  // Generate a random seed for the probability algorithm
  srand(time(0));

  // Calculate the invasion probability
  if (earthDefenses <= 0.0) {
    invasionProbability = 100; // Earth has no defenses
  }
  else if (earthDefenses >= 100.0) {
    invasionProbability = 0; // Earth has impenetrable defenses
  }
  else {
    invasionProbability = 80 - (alienShips * 10) + (rand() % 21) - earthDefenses;
    if (invasionProbability < 0) {
      invasionProbability = 0; // Probability cannot be negative
    }
    else if (invasionProbability > 100) {
      invasionProbability = 100; // Probability cannot exceed 100%
    }
  }

  // Print the invasion probability
  printf("\nAlien invasion probability: %d%%\n", invasionProbability);

  return 0;
}