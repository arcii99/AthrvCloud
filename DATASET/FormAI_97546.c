//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declare constants for the four bases
#define A 0
#define T 1
#define C 2
#define G 3
#define BASES "ATCG"

int main() {

  // Seed the random number generator
  srand(time(NULL));

  // Generate a random length for our sequence
  int length = rand() % 1000 + 1000; // Random number between 1000 and 1999

  // Allocate memory for the sequence
  char *sequence = (char*) malloc(length+1); // +1 to include terminating null byte

  // Generate the sequence
  for (int i = 0; i < length; i++) {
    // Generate a random index for the bases array
    int index = rand() % 4;
    // Assign the base to the sequence
    sequence[i] = BASES[index];
  }

  // Terminate the sequence with a null byte
  sequence[length] = '\0';

  // Print the sequence
  printf("Sequence generated: %s\n", sequence);

  // Free the memory allocated for the sequence
  free(sequence);

  return 0;
}