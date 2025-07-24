//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define BASES "ACGT"

int main() {
  // Generate a random DNA sequence
  srand(time(NULL));
  char sequence[101];
  for (int i = 0; i < 100; i++) {
    sequence[i] = BASES[rand() % strlen(BASES)];
  }
  sequence[100] = '\0';

  printf("Original sequence:\n%s\n", sequence);

  // Simulate a sequencing error rate of 1%
  char errors[101];
  for (int i = 0; i < 100; i++) {
    if (rand() % 100 == 0) {
      errors[i] = BASES[rand() % (strlen(BASES) - 1)];
    } else {
      errors[i] = sequence[i];
    }
  }
  errors[100] = '\0';

  printf("Sequence with errors:\n%s\n", errors);

  // Simulate genome sequencing
  char genome[100];
  int coverage[100];
  for (int i = 0; i < 100; i++) {
    genome[i] = '\0';
    coverage[i] = 0;
  }

  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      if (genome[j] == '\0' || genome[j] == errors[i]) {
        genome[j] = errors[i];
        coverage[j]++;
        break;
      }
    }
  }

  printf("Sequenced genome:\n%s\n", genome);

  // Print coverage information
  printf("Coverage information:\n");
  for (int i = 0; i < 100; i++) {
    if (genome[i] == '\0') {
      printf("Base %d: Not covered\n", i+1);
    } else {
      printf("Base %d: Covered %d time(s)\n", i+1, coverage[i]);
    }
  }

  return 0;
}