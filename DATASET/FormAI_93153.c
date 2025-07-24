//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SEQUENCE_LENGTH 1000

int main() {

  // Input genome sequences
  char sequence1[MAX_SEQUENCE_LENGTH], sequence2[MAX_SEQUENCE_LENGTH];
  printf("Enter genome sequence 1: ");
  fgets(sequence1, MAX_SEQUENCE_LENGTH, stdin);
  printf("Enter genome sequence 2: ");
  fgets(sequence2, MAX_SEQUENCE_LENGTH, stdin);

  // Convert sequences to uppercase
  for (int i = 0; i < strlen(sequence1); i++) {
    sequence1[i] = toupper(sequence1[i]);
  }
  for (int i = 0; i < strlen(sequence2); i++) {
    sequence2[i] = toupper(sequence2[i]);
  }

  // Print the sequences
  printf("Sequence 1: %s\n", sequence1);
  printf("Sequence 2: %s\n", sequence2);

  // Determine the shorter sequence length
  int sequenceLength = strlen(sequence1);
  if (strlen(sequence2) < sequenceLength) {
    sequenceLength = strlen(sequence2);
  }

  // Generate random mutations
  int mutationCount = sequenceLength / 10;
  for (int i = 0; i < mutationCount; i++) {
    int index = rand() % sequenceLength;
    char newBase = 'A';
    while (newBase == sequence1[index] || newBase == sequence2[index]) {
      newBase = rand() % 4;
      switch (newBase) {
        case 0:
          newBase = 'A';
          break;
        case 1:
          newBase = 'C';
          break;
        case 2:
          newBase = 'G';
          break;
        case 3:
          newBase = 'T';
          break;
      }
    }
    printf("Mutation at index %d: %c -> %c\n", index, sequence1[index], newBase);
    sequence1[index] = newBase;
    sequence2[index] = newBase;
  }

  // Print the mutated sequences
  printf("Mutated sequence 1: %s\n", sequence1);
  printf("Mutated sequence 2: %s\n", sequence2);

  return 0;
}