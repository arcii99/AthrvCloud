//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 1000000
#define MAX_MUTATIONS 100000
#define MUTATION_RATE 0.001

char random_nucleotide() {
  int r = rand() % 4;
  switch (r) {
    case 0: return 'A';
    case 1: return 'C';
    case 2: return 'G';
    case 3: return 'T';
  }
}

char mutate_nucleotide(char n) {
  if ((double)rand() / RAND_MAX < MUTATION_RATE) {
    return random_nucleotide();
  } else {
    return n;
  }
}

void generate_genome(char genome[]) {
  int i;
  for (i = 0; i < GENOME_LENGTH; i++) {
    genome[i] = random_nucleotide();
  }
}

void mutate_genome(char genome[], int num_mutations) {
  int i;
  for (i = 0; i < num_mutations; i++) {
    int pos = rand() % GENOME_LENGTH;
    genome[pos] = mutate_nucleotide(genome[pos]);
  }
}

void print_genome(char genome[]) {
  int i;
  for (i = 0; i < GENOME_LENGTH; i++) {
    putchar(genome[i]);
  }
  putchar('\n');
}

int main() {
  char genome[GENOME_LENGTH];
  srand(time(NULL));
  generate_genome(genome);
  mutate_genome(genome, MAX_MUTATIONS);
  print_genome(genome);
  return 0;
}