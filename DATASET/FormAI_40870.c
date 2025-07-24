//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Initialize variables
  int i, j, k, l;
  int genomeLength = 100;
  char genome[100], nucleotide;
  int mutationRate = 10;
  int mutationCount = 0;

  // Seed random number generator
  srand(time(NULL));

  // Generate random genome
  for (i = 0; i < genomeLength; i++) {
    int r = rand() % 4;
    if (r == 0) {
      genome[i] = 'A';
    } else if (r == 1) {
      genome[i] = 'C';
    } else if (r == 2) {
      genome[i] = 'G';
    } else {
      genome[i] = 'T';
    }
  }

  // Print original genome
  printf("Original Genome:\n");
  for (i = 0; i < genomeLength; i++) {
    printf("%c", genome[i]);
  }
  printf("\n\n");

  // Mutate genome
  for (i = 0; i < genomeLength; i++) {
    int r = rand() % 100;
    if (r < mutationRate) {
      mutationCount++;
      do {
        j = rand() % genomeLength;
      } while (j == i);
      nucleotide = genome[j];
      do {
        k = rand() % genomeLength;
      } while (k == i || k == j);
      genome[k] = nucleotide;
    }
  }

  // Print mutated genome
  printf("Mutated Genome:\n");
  for (l = 0; l < genomeLength; l++) {
    printf("%c", genome[l]);
  }
  printf("\n\n");

  // Print mutation rate and count
  printf("Mutation rate: %d%%\n", mutationRate);
  printf("Number of mutations: %d\n", mutationCount);

  return 0;
}