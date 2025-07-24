//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SEQUENCE_LEN 1000
#define MUTATION_RATE 0.05

char random_base() {
  int r = rand() % 4;
  switch (r) {
    case 0: return 'A';
    case 1: return 'T';
    case 2: return 'G';
    case 3: return 'C';
  }
  return 'N'; /* Shouldn't happen */
}

void generate_sequence(char seq[]) {
  for (int i = 0; i < SEQUENCE_LEN; i++) {
    seq[i] = random_base();
  }
  seq[SEQUENCE_LEN] = '\0';
}

void mutate_sequence(char seq[], double rate) {
  for (int i = 0; i < SEQUENCE_LEN; i++) {
    double r = (double)rand() / RAND_MAX;
    if (r < rate) {
      seq[i] = random_base();
    }
  }
}

int main() {
  srand(42); /* Seed the random number generator */
  char original[SEQUENCE_LEN + 1];
  char mutant[SEQUENCE_LEN + 1];
  generate_sequence(original);
  strncpy(mutant, original, SEQUENCE_LEN + 1);
  mutate_sequence(mutant, MUTATION_RATE);
  printf("Original sequence: %s\n", original);
  printf("Mutant sequence:   %s\n", mutant);
  return 0;
}