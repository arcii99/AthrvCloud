//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Set the seed for the random number generator
  srand(time(NULL));

  // Define the genome sequence
  char genome[10] = {'A', 'C', 'G', 'T'};

  // Generate a random genome sequence of length 10
  char sequence[11];
  for (int i = 0; i < 10; i++) {
    int random_index = rand() % 4;
    sequence[i] = genome[random_index];
  }
  sequence[10] = '\0';

  // Print the generated sequence
  printf("Generated genome sequence: %s\n", sequence);

  // Mutate the genome sequence
  int mutation_rate = 10; // 10% mutation rate
  for (int i = 0; i < 10; i++) {
    int random_number = rand() % 100;
    if (random_number < mutation_rate) {
      int random_index = rand() % 4;
      sequence[i] = genome[random_index];
    }
  }

  // Print the mutated sequence
  printf("Mutated genome sequence: %s\n", sequence);

  return 0;
}