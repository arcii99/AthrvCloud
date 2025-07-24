//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENE_LENGTH 1000

void mutate(char gene[]);
void print_gene(char gene[]);

int main() {
  srand(time(NULL)); // seed random with current time
  char gene[GENE_LENGTH] = {0}; // initialize gene to all zeros

  // randomly assign values to gene
  for (int i = 0; i < GENE_LENGTH; i++) {
    gene[i] = rand() % 4; // 0-3
  }

  // Print original gene
  printf("Original Gene: \n");
  print_gene(gene);

  // Simulate mutation
  printf("\nSimulating mutation...\n");
  mutate(gene);

  // Print mutated gene
  printf("\nMutated Gene: \n");
  print_gene(gene);

  return 0;
}

void mutate(char gene[]) {
  int num_mutations = rand() % GENE_LENGTH; // number of mutations to make
  for (int i = 0; i < num_mutations; i++) {
    int index = rand() % GENE_LENGTH; // choose random index to mutate
    gene[index] = rand() % 4; // randomly assign new value
  }
}

void print_gene(char gene[]) {
  for (int i = 0; i < GENE_LENGTH; i++) {
    switch (gene[i]) {
      case 0:
        printf("A ");
        break;
      case 1:
        printf("C ");
        break;
      case 2:
        printf("G ");
        break;
      case 3:
        printf("T ");
        break;
    }
  }
  printf("\n");
}