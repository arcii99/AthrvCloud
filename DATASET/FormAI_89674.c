//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SEQUENCE_LENGTH 1000

// Define the possible nucleotides in DNA
#define A 0
#define C 1
#define G 2
#define T 3

int main() {
  int genome[SEQUENCE_LENGTH];

  // Seed random number generator
  srand(time(NULL));

  // Generate random genome
  for (int i = 0; i < SEQUENCE_LENGTH; i++) {
    genome[i] = rand() % 4;
  }

  // Output genome as sequence of letters
  for (int i = 0; i < SEQUENCE_LENGTH; i++) {
    switch (genome[i]) {
      case A:
        putchar('A');
        break;
      case C:
        putchar('C');
        break;
      case G:
        putchar('G');
        break;
      case T:
        putchar('T');
        break;
    }
  }

  return 0;
}