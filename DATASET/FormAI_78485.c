//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define GENOME_LENGTH 1000  // Define the length of the genome
#define NUCLEOTIDES "ATCG"  // Define the possible nucleotides

int main() {
  srand(time(NULL));  // Initialize the random number generator

  // Generate the genome randomly
  char genome[GENOME_LENGTH+1];
  for (int i = 0; i < GENOME_LENGTH; i++) {
    genome[i] = NUCLEOTIDES[rand() % strlen(NUCLEOTIDES)];
  }
  genome[GENOME_LENGTH] = '\0';

  // Print the genome
  printf("Genome: %s\n", genome);

  // Simulate genome sequencing
  printf("\nSimulating genome sequencing...\n\n");
  for (int i = 0; i < GENOME_LENGTH; i++) {
    // Introduce some errors in the sequencing
    if (rand() % 10 == 0) {
      printf("X");  // Denotes an error
      continue;
    }

    printf("%c", genome[i]);
  }

  printf("\n");

  return 0;
}