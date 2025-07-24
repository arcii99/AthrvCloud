//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  printf("Welcome to the Genome Sequencing Simulator!\n");
  
  // Setup variables
  srand(time(0));
  char nucleotides[4] = {'A', 'C', 'G', 'T'};
  int length, numMutations;
  
  // Get user input
  printf("Enter the desired length of the genome: ");
  scanf("%d", &length);
  printf("Enter the desired number of mutations: ");
  scanf("%d", &numMutations);
  
  // Generate genome
  char* genome = (char*) malloc(length + 1);
  int i;
  for (i = 0; i < length; i++) {
    int index = rand() % 4;
    genome[i] = nucleotides[index];
  }
  genome[length] = '\0';
  printf("Generated genome: %s\n", genome);
  
  // Introduce mutations
  int j;
  for (j = 0; j < numMutations; j++) {
    int index = rand() % length;
    int mutation = rand() % 4;
    genome[index] = nucleotides[mutation];
  }
  printf("Mutated genome: %s\n", genome);
  
  // Cleanup
  free(genome);
  
  return 0;
}