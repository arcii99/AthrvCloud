//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int genome[1000]; // represent a genome of 1000 characters
  int nucleotide_count[4] = {0, 0, 0, 0}; // represent the count of A, C, G, T nucleotides
  srand(time(NULL)); // seed the random number generator

  // populate the genome with random nucleotide values (0=A, 1=C, 2=G, 3=T)
  for (int i = 0; i < 1000; i++) {
    genome[i] = rand() % 4;
    nucleotide_count[genome[i]]++;
  }

  // print out the genome
  for (int i = 0; i < 1000; i++) {
    if (i % 10 == 0) {
      printf("\n");
    }
    printf("%d", genome[i]);
  }
  printf("\n");

  // print out nucleotide count
  printf("A: %d C: %d G: %d T: %d\n", nucleotide_count[0], nucleotide_count[1], nucleotide_count[2], nucleotide_count[3]);

  return 0;
}