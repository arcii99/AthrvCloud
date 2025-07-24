//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // seed the random number generator
  
  char nucleotides[] = {'A', 'C', 'G', 'T'}; // array of possible nucleotides
  int genome_length = 1000; // length of genome to be sequenced
  
  char* genome = (char*)malloc(genome_length * sizeof(char)); // allocate memory for genome
  
  // generate random nucleotide sequence for genome
  for (int i = 0; i < genome_length; i++) {
    int rand_index = rand() % 4; // generate random index for nucleotides array
    genome[i] = nucleotides[rand_index]; // assign random nucleotide to genome
  }
  
  // print the generated genome
  printf("Generated genome: \n%s\n", genome);
  
  // randomly select a section of the genome to simulate sequencing
  int start_index = rand() % (genome_length / 2); // start index for sequencing
  int end_index = start_index + (rand() % (genome_length / 2)); // end index for sequencing
  
  // simulate sequencing by copying selected section to new array with mutations
  char* sequenced_genome = (char*)malloc((end_index - start_index + 1) * sizeof(char)); // allocate memory for sequenced genome
  for (int i = start_index; i <= end_index; i++) {
    char nucleotide = genome[i];
    int mutation_chance = rand() % 10; // 10% chance of mutation
    if (mutation_chance == 0) { // mutation occurs
      int replace_index = rand() % 3 + 1; // index of nucleotide to replace with
      char mutation = nucleotides[(nucleotide + replace_index) % 4]; // find new nucleotide for mutation
      sequenced_genome[i - start_index] = mutation; // assign new nucleotide to sequenced genome
    } else { // no mutation occurs
      sequenced_genome[i - start_index] = nucleotide; // copy nucleotide to sequenced genome
    }
  }
  
  // print the sequenced genome
  printf("Simulated sequenced genome from index %d to %d: \n%s\n", start_index, end_index, sequenced_genome);
  
  // free dynamically allocated memory
  free(genome);
  free(sequenced_genome);
  
  return 0;
}