//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 100
#define MUTATION_RATE 0.1

int main()
{
  char genome[GENOME_LENGTH];
  int i;
  srand(time(NULL)); // Setting seed for random number generation
  
  // Generating random genome
  for (i=0; i<GENOME_LENGTH; i++) {
    int r = rand() % 4;
    switch (r) {
      case 0:
        genome[i] = 'A';
        break;
      case 1:
        genome[i] = 'C';
        break;
      case 2:
        genome[i] = 'G';
        break;
      case 3:
        genome[i] = 'T';
        break;
    }
  }
  genome[GENOME_LENGTH] = '\0'; // Adding null terminator to string
  
  // Printing original genome
  printf("Original Genome: %s\n", genome);
  
  // Introducing mutations to genome
  for (i=0; i<GENOME_LENGTH; i++) {
    double mutation_chance = (double) rand() / RAND_MAX;
    if (mutation_chance < MUTATION_RATE) {
      int r = rand() % 3;
      switch (r) {
        case 0:
          genome[i] = 'A';
          break;
        case 1:
          genome[i] = 'C';
          break;
        case 2:
          genome[i] = 'G';
          break;
        case 3:
          genome[i] = 'T';
          break;
      }
    }
  }
  
  // Printing mutated genome
  printf("Mutated Genome: %s\n", genome);
  
  return 0;
}