//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_SIZE 1000000

int main() {
  srand(time(NULL));  // Set random seed based on current time
  char genome[GENOME_SIZE];
  
  // Initialize genome with random nucleotides (A, C, G, T)
  for (int i = 0; i < GENOME_SIZE; i++) {
    char nucleotide;
    int random = rand() % 4;
    switch (random) {
      case 0:
        nucleotide = 'A';
        break;
      case 1:
        nucleotide = 'C';
        break;
      case 2:
        nucleotide = 'G';
        break;
      case 3:
        nucleotide = 'T';
        break;
    }
    genome[i] = nucleotide;
  }
  
  // Print first 10 nucleotides of genome
  printf("First 10 nucleotides of genome: ");
  for (int i = 0; i < 10; i++) {
    printf("%c ", genome[i]);
  }
  printf("\n");
  
  // Simulate genome sequencing
  int num_reads;
  printf("Enter number of reads: ");
  scanf("%d", &num_reads);
  
  for (int i = 0; i < num_reads; i++) {
    int read_length = rand() % 100 + 50;  // Generate random read length between 50 and 149
    int start_pos = rand() % (GENOME_SIZE - read_length + 1);  // Generate random starting position
    char read[read_length];  // Initialize read
    for (int j = 0; j < read_length; j++) {
      read[j] = genome[start_pos + j];
    }
    printf("Read %d: %s\n", i+1, read);
  }
  
  return 0;
}