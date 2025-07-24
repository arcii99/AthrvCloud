//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_SIZE 1000
#define MUTATION_RATE 0.01

char basePairs[4] = {'A', 'C', 'G', 'T'};

void mutate(char *genome) {
  for (int i = 0; i < GENOME_SIZE; i++) {
    if ((double)rand() / RAND_MAX < MUTATION_RATE) {
      genome[i] = basePairs[rand() % 4];
    }
  }
}

int main() {
  srand(time(NULL));

  char genome[GENOME_SIZE] = {0}; // Initialize genome to all 0's
  for (int i = 0; i < GENOME_SIZE; i++) {
    genome[i] = basePairs[rand() % 4]; // Initialize genome with random base pairs
  }

  printf("Original genome: %s\n", genome);

  for (int i = 0; i < 10; i++) {
    char mutatedGenome[GENOME_SIZE] = {0}; // Initialize new genome to all 0's
    for (int j = 0; j < GENOME_SIZE; j++) {
      mutatedGenome[j] = genome[j]; // Copy original genome to new genome
    }

    printf("Mutated genome %d: ", i + 1);
    mutate(mutatedGenome);
    printf("%s\n", mutatedGenome);

    // Set mutated genome to be the new original genome
    for (int j = 0; j < GENOME_SIZE; j++) {
      genome[j] = mutatedGenome[j];
    }
  }

  return 0;
}