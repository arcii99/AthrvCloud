//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the base pairs of DNA
#define A 'A'
#define C 'C'
#define G 'G'
#define T 'T'

// Define the length of the genome sequence
#define GENOME_LENGTH 100

// Define the mutation rate
#define MUTATION_RATE 0.01

// Define the function to randomly select a base pair
char randomBasePair() {
  int randomNum = rand() % 4;
  switch(randomNum) {
    case 0:
      return A;
      break;
    case 1:
      return C;
      break;
    case 2:
      return G;
      break;
    case 3:
      return T;
      break;
  }
}

// Define the function to mutate a base pair
char mutateBasePair(char basePair) {
  if(rand() < MUTATION_RATE * RAND_MAX) {
    return randomBasePair();
  } else {
    return basePair;
  }
}

int main() {
  
  srand(time(NULL)); // Seed the random number generator with the current time
  
  char genome[GENOME_LENGTH]; // Create the genome sequence
  
  // Generate the genome sequence
  for(int i = 0; i < GENOME_LENGTH; i++) {
    if(i == 0) {
      genome[i] = randomBasePair(); // The first base pair is random
    } else {
      genome[i] = mutateBasePair(genome[i-1]); // Each subsequent base pair may mutate
    }
  }
  
  // Print the genome sequence
  for(int i = 0; i < GENOME_LENGTH; i++) {
    printf("%c", genome[i]);
  }
  
  printf("\n"); // Print a newline
  
  return 0;
}