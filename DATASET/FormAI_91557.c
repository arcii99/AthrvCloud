//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

int main() {
  int scale = 100;
  int probability = rand() % scale;
  printf("=====================================\n");
  printf("|   C ALIEN INVASION PROBABILITY    |\n");
  printf("=====================================\n");
  printf("\n");
  printf("Calculating probability of alien invasion...\n");
  printf("\n");
  printf("Please stand by...\n");
  printf("\n");
  printf("Probability of alien invasion: %d%%\n", probability);
  printf("\n");
  printf("Determining potential threat level...\n");
  printf("\n");

  if (probability < 20) {
    printf("Threat level: Low\n");
    printf("\n");
    printf("No need to worry, carry on with daily activities.\n");
  }
  else if (probability >= 20 && probability <50) {
    printf("Threat level: Moderate\n");
    printf("\n");
    printf("Keep a watchful eye on the skies, and be prepared for possible invasion.\n");
  }
  else if (probability >= 50 && probability < 80) {
    printf("Threat level: High\n");
    printf("\n");
    printf("Prepare for possible evacuation, and avoid going out alone at night.\n");
  }
  else {
    printf("Threat level: Extreme\n");
    printf("\n");
    printf("Evacuate immediately, and seek shelter in secure locations.\n");
  }

  return 0;
}