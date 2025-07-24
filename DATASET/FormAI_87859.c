//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int genome_length;
  printf("Enter the length of the genome: ");
  scanf("%d", &genome_length);

  char nucleotide[] = {'A', 'C', 'G', 'T'};
  int count[4] = {0, 0, 0, 0};

  srand(time(NULL)); // seed random number generator

  printf("Generated genome sequence:\n");

  for (int i = 0; i < genome_length; i++) {
    int random_number = rand() % 4; // generate random number between 0 and 3
    printf("%c", nucleotide[random_number]);
    count[random_number]++;
  }

  printf("\n\nNucleotide count:\nA: %d\nC: %d\nG: %d\nT: %d\n", count[0], count[1], count[2], count[3]);

  return 0;
}