//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  printf("Welcome to the Alien Invasion Probability Calculator!\n\n");

  // Setting up random seed
  srand(time(NULL));

  // Generating random probability values
  int probability1 = rand() % 101;
  int probability2 = rand() % 101;
  int probability3 = rand() % 101;
  
  // Generating random alien types
  char* alienType = NULL;
  int alienRandom = rand() % 3;
  if(alienRandom == 0) {
    alienType = "Zorgonians";
  } else if(alienRandom == 1) {
    alienType = "Xendarians";
  } else {
    alienType = "Traxians";
  }

  // Printing surrealistic output
  printf("Commencing improbable alien invasion probability calculations...\n\n");
  printf("Chance of %s using mind control on human leaders: %d%%\n", alienType, probability1);
  if(probability1 > 50) {
    printf("Oh dear, this does not bode well for our planet...\n");
  } else {
    printf("Phew, we might just be safe...\n");
  }

  printf("\nChance of %s using genetically modified creatures: %d%%\n", alienType, probability2);
  if(probability2 > 75) {
    printf("We are in big trouble, time to prepare for the worst...\n");
  } else {
    printf("Not too bad, we may be able to handle this...\n");
  }

  printf("\nChance of %s using advanced weaponry: %d%%\n", alienType, probability3);
  if(probability3 > 90) {
    printf("There's no escaping this, brace yourself for impact...\n");
  } else {
    printf("Well, it's not an ideal situation but we might just make it...\n");
  }

  printf("\nCalculations complete. Remember to always carry a towel with you!\n");

  return 0;
}