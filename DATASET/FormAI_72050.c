//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 1000 /* Define genome length in number of base pairs */
#define MUTATION_RATE 0.01 /* Define mutation rate */

/* Function to generate a random base */
char random_base() {
  int r = rand() % 4;
  switch (r) {
    case 0:
      return 'A';
    case 1:
      return 'C';
    case 2:
      return 'G';
    case 3:
      return 'T';
  }
}

/* Function to simulate genome sequencing */
void simulate_genome_sequencing(char genome[GENOME_LENGTH]) {
  /* Create a copy of the genome */
  char genome_copy[GENOME_LENGTH];
  for (int i = 0; i < GENOME_LENGTH; i++) {
    genome_copy[i] = genome[i];
  }

  /* Mutate the genome copy */
  for (int i = 0; i < GENOME_LENGTH; i++) {
    if ((double)rand() / RAND_MAX < MUTATION_RATE) {
      genome_copy[i] = random_base();
    }
  }

  /* Print the original genome */
  printf("Original genome:\n");
  for (int i = 0; i < GENOME_LENGTH; i++) {
    printf("%c", genome[i]);
  }
  printf("\n");

  /* Print the mutated genome */
  printf("Mutated genome:\n");
  for (int i = 0; i < GENOME_LENGTH; i++) {
    printf("%c", genome_copy[i]);
  }
  printf("\n");
}

int main() {
  /* Seed the random number generator */
  srand(time(NULL));

  /* Generate a random genome */
  char genome[GENOME_LENGTH];
  for (int i = 0; i < GENOME_LENGTH; i++) {
    genome[i] = random_base();
  }

  /* Simulate genome sequencing */
  simulate_genome_sequencing(genome);

  return 0;
}