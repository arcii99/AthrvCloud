//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MIN_LEN 10       // minimum length of genome sequence
#define MAX_LEN 100      // maximum length of genome sequence
#define MUT_RATE 0.01    // mutation rate
#define RAND_RANGE 10000 // random number generation range

// Function to generate random numbers
int randInt(int range) {
  return rand() % range;
}

int main() {
  // Initialize random seed
  srand(time(NULL));
  
  // Generate a random genome sequence of length between MIN_LEN and MAX_LEN
  int length = randInt(MAX_LEN-MIN_LEN+1) + MIN_LEN;
  char genome[length+1];
  for (int i=0; i<length; i++) {
    genome[i] = "ACGT"[randInt(4)]; // randomly select A, C, G, or T
  }
  genome[length] = '\0';
  
  // Print the original genome sequence
  printf("Original Genome Sequence: %s\n", genome);
  
  // Simulate mutation
  for (int i=0; i<length; i++) {
    if ((double) rand() / RAND_MAX <= MUT_RATE) { // randomly decide to mutate or not
      genome[i] = "ACGT"[randInt(4)]; // randomly select A, C, G, or T as the new base
    }
  }
  
  // Print the mutated genome sequence
  printf("Mutated Genome Sequence: %s\n", genome);
  
  // Calculate the genome similarity score (% similarity)
  int score = 0;
  for (int i=0; i<length; i++) {
    if (genome[i] == "ACGT"[randInt(4)]) { // randomly select another base
      score++;
    }
  }
  double similarity = (double) score / length * 100;
  
  // Print the genome similarity score
  printf("Genome Similarity Score: %.2f%%\n", similarity);
  
  return 0;
}