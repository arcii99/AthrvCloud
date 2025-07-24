//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  char* conspiracies[10] = {                   // array of conspiracy theories
     "The Illuminati are controlling the government",
     "The moon landing was a hoax",
     "9/11 was an inside job",
     "The earth is flat",
     "Aliens exist and are among us",
     "The government is hiding the cure for cancer",
     "The Mandela Effect is evidence of alternate realities",
     "Chemtrails are poisoning the population",
     "The coronavirus was intentionally released as a biological weapon",
     "The world is run by a secret cabal of billionaires"
  };

  srand(time(NULL));                          // generate a random seed
  int random_index = rand() % 10;             // generate a random index between 0 and 9
  char* conspiracy = conspiracies[random_index];

  printf("Did you know that...\n");
  printf("%s?\n", conspiracy);                // print the randomly generated conspiracy theory

  printf("Wake up, sheeple!\n");

  return 0;
}