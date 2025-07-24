//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // Seed for random probability
  
  printf("*******************************************************\n");
  printf("*                 Alien Invasion Calculator            *\n");
  printf("*******************************************************\n");
  
  float probability = (rand() % 101) / 100.0; // Random probability between 0 and 1

  printf("Current probability of an Alien Invasion: %f\n", probability);
  
  if (probability > 0.5) {
    printf("ALERT! Probability of Alien Invasion is HIGH!\n");
  } else {
    printf("Probability of Alien Invasion is low.\n");
  }
  
  printf("Do you want to calculate again? (Y/N)\n");
  char answer;
  scanf("%c", &answer);
  
  while (answer == 'Y' || answer == 'y') {
    probability = (rand() % 101) / 100.0;
    
    printf("Current probability of an Alien Invasion: %f\n", probability);
    
    if (probability > 0.5) {
      printf("ALERT! Probability of Alien Invasion is HIGH!\n");
    } else {
      printf("Probability of Alien Invasion is low.\n");
    }
    
    printf("Do you want to calculate again? (Y/N)\n");
    scanf(" %c", &answer); // space before %c to clear input buffer
  }
  
  printf("Thank you for using our Alien Invasion Probability Calculator.\n");
  
  return 0;
}