//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000 // length of genome sequence
#define MUTATION_RATE 0.01 // probability of a random mutation

int main() {
  // initialize genome sequence
  char genome[N];
  for (int i = 0; i < N; i++) {
    genome[i] = rand() % 4; // randomly assign nucleotide A,C,G or T
  }

  // simulate mutations
  srand(time(NULL)); // initialize random seed
  for (int i = 0; i < N; i++) {
    if ((float) rand() / RAND_MAX < MUTATION_RATE) {
      genome[i] = rand() % 4; // randomly mutate nucleotide
    }
  }

  // output genome sequence
  printf("The genome sequence is:\n");
  for (int i = 0; i < N; i++) {
    switch (genome[i]) {
      case 0:
        printf("A");
        break;
      case 1:
        printf("C");
        break;
      case 2:
        printf("G");
        break;
      case 3:
        printf("T");
        break;
      default:
        printf("Error: invalid nucleotide");
        exit(1);
    }
  }
  
  return 0;
}