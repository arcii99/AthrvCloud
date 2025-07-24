//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  
  // Welcome message
  printf("Welcome to the C Genome Sequencing Simulator!\n\n");

  // Prompt user for genome length
  int genome_length;
  printf("Please enter the length of the genome to simulate (in base pairs):\n");
  scanf("%d", &genome_length);

  // Allocate memory for genome sequence
  char* genome_sequence = malloc(genome_length * sizeof(char));

  // Seed random number generator
  srand(42);

  // Generate random genome sequence
  int i;
  for (i = 0; i < genome_length; i++) {
    int random_nucleotide = rand() % 4;
    switch (random_nucleotide) {
      case 0:
        genome_sequence[i] = 'A';
        break;
      case 1:
        genome_sequence[i] = 'C';
        break;
      case 2:
        genome_sequence[i] = 'G';
        break;
      case 3:
        genome_sequence[i] = 'T';
        break;
    }
  }

  // Print genome sequence
  printf("\nYour simulated genome sequence is:\n%s\n", genome_sequence);

  // Free memory allocated for genome sequence
  free(genome_sequence);

  // Exit program
  return 0;
}