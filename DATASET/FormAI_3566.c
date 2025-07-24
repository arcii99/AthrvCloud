//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  srand(15);
  
  // Generate random DNA sequence
  char dna_seq[10000];
  for (int i = 0; i < 10000; i++) {
    int random_num = rand() % 4;
    switch (random_num) {
      case 0:
        dna_seq[i] = 'A';
        break;
      case 1:
        dna_seq[i] = 'T';
        break;
      case 2:
        dna_seq[i] = 'C';
        break;
      case 3:
        dna_seq[i] = 'G';
        break;
    }
  }

  // Print DNA sequence
  printf("DNA sequence:\n");
  for (int i = 0; i < 10000; i++) {
    printf("%c", dna_seq[i]);
  }
  printf("\n\n");

  // Simulate sequencing with errors
  char sequencing_errors[] = {'A', 'T', 'C', 'G', '-', 'N'};
  char dna_errors[10000];
  for (int i = 0; i < 10000; i++) {
    int random_num = rand() % 10;
    switch (random_num) {
      case 0:
      case 1:
        dna_errors[i] = sequencing_errors[4]; // Insertion
        break;
      case 2:
      case 3:
        dna_errors[i] = sequencing_errors[5]; // Ambiguous base
        break;
      case 4:
      case 5:
        dna_errors[i] = dna_seq[i]; // Good base
        break;
      case 6:
        dna_errors[i] = sequencing_errors[0]; // Mismatch
        break;
      case 7:
        dna_errors[i] = sequencing_errors[1]; // Mismatch
        break;
      case 8:
        dna_errors[i] = sequencing_errors[2]; // Mismatch
        break;
      case 9:
        dna_errors[i] = sequencing_errors[3]; // Mismatch
        break;
    }
  }

  // Print simulated DNA sequence with errors
  printf("Simulated sequencing with errors:\n");
  for (int i = 0; i < 10000; i++) {
    printf("%c", dna_errors[i]);
  }
  printf("\n\n");

  // Simulate genome assembly
  char genome_assembly[10000];
  int genome_length = 0;
  for (int i = 0; i < 10000; i++) {
    if (dna_errors[i] != '-') {
      genome_assembly[genome_length] = dna_errors[i];
      genome_length++;
      int j = i+1;
      while (j < 10000 && dna_errors[j] ==dna_errors[i]){
         genome_assembly[genome_length] = dna_errors[j];
         genome_length++;
         j++;
      }
      i = j-1;
    }
  }

  // Print genome assembly
  printf("Genome assembly:\n");
  for (int i = 0; i < genome_length; i++) {
    printf("%c", genome_assembly[i]);
  }
  printf("\n\n");
  return 0;
}