//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int nucleotide_count = 1000; // the length of the genome sequence
  char nucleotides[nucleotide_count]; // an array to store the nucleotides

  char nucleobases[] = {'A', 'C', 'G', 'T'}; // the four nucleobases A, C, G, and T

  srand(time(0)); // seed the random number generator

  // generate the random genome sequence
  for (int i = 0; i < nucleotide_count; i++) {
    int random_base_index = rand() % 4;
    char random_base = nucleobases[random_base_index];
    nucleotides[i] = random_base;
  }

  // print the genome sequence
  printf("Genome Sequence:\n");
  for (int i = 0; i < nucleotide_count; i++) {
    printf("%c", nucleotides[i]);
  }
  printf("\n");

  // count the number of each nucleobase in the genome sequence
  int A_count = 0;
  int C_count = 0;
  int G_count = 0;
  int T_count = 0;
  for (int i = 0; i < nucleotide_count; i++) {
    if (nucleotides[i] == 'A') {
      A_count++;
    } else if (nucleotides[i] == 'C') {
      C_count++;
    } else if (nucleotides[i] == 'G') {
      G_count++;
    } else if (nucleotides[i] == 'T') {
      T_count++;
    }
  }

  // print the count of each nucleobase
  printf("Nucleobase Counts:\n");
  printf("A: %d\n", A_count);
  printf("C: %d\n", C_count);
  printf("G: %d\n", G_count);
  printf("T: %d\n", T_count);

  return 0;
}