//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_SIZE 1000000 // size of genome to be sequenced
#define READ_SIZE 100 // size of reads to be generated
#define NUM_READS 10000 // number of reads to be generated
#define ERROR_RATE 0.01 // probability of error in each read

int main() {
  // randomize seed for generating genome and reads
  srand(time(NULL));
  
  // generate random genome
  char genome[GENOME_SIZE];
  for (int i = 0; i < GENOME_SIZE; i++) {
    genome[i] = "ACGT"[rand() % 4];
  }
  
  // generate reads from genome with random errors
  char reads[NUM_READS][READ_SIZE];
  for (int i = 0; i < NUM_READS; i++) {
    int start = rand() % (GENOME_SIZE - READ_SIZE); // randomly choose starting position in genome
    for (int j = 0; j < READ_SIZE; j++) {
      // introduce error with probability ERROR_RATE
      char base = genome[start + j];
      if ((double) rand() / RAND_MAX < ERROR_RATE) { // randomly decide if error should be introduced
        base = "ACGT"[rand() % 3]; // randomly choose a different base
      }
      reads[i][j] = base;
    }
  }
  
  // print generated genome and reads to console
  printf("Generated genome:\n");
  for (int i = 0; i < GENOME_SIZE; i++) {
    printf("%c", genome[i]);
  }
  printf("\n\n");
  
  printf("Generated reads:\n");
  for (int i = 0; i < NUM_READS; i++) {
    for (int j = 0; j < READ_SIZE; j++) {
      printf("%c", reads[i][j]);
    }
    printf("\n");
  }
  
  return 0;
}