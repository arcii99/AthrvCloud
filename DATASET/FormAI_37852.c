//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Conspiracy theories
  char *theories[] = {
    "Aliens are secretly controlling world governments",
    "The moon landing was a hoax",
    "The Illuminati are trying to take over the world",
    "Chemtrails are mind-control agents",
    "The government is hiding the cure for cancer",
    "Weather control technology is being used for nefarious purposes"
  };
  
  // Random seed
  srand(time(NULL));
  
  // Welcome message
  printf("Welcome to the Random Conspiracy Theory Generator!\n");
  printf("Press enter to generate a new theory.\n");
  
  // Main loop
  while(1) {
    getchar(); // Wait for user to press enter
    
    // Generate random theory
    int index = rand() % 6;
    char *theory = theories[index];
    
    // Display theory
    printf("\n%s\n", theory);
  }
  
  return 0;
}