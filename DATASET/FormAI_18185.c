//FormAI DATASET v1.0 Category: Computer Biology ; Style: brave
/* BRAVE C COMPUTER BIOLOGY PROGRAM */

#include <stdio.h> 

int main() {

  // Displaying a bold message
  printf("\n\n\t BRAVE C COMPUTER BIOLOGY PROGRAM\n");
  printf("\t----------------------------------\n\n");

  // Initializing variables
  int num_chromosomes = 46; 
  float gene_density = 0.022;
  char nucleobase = 'A';
  double mutation_rate = 0.000001;

  // Printing out the variables with some elaboration
  printf("The human genome contains %d chromosomes.\n", num_chromosomes);
  printf("The gene density of the human genome is %f genes per Kb.\n", gene_density); 
  printf("The nucleobase %c is one of the four fundamental units of the genetic code.\n", nucleobase);
  printf("The mutation rate of the human genome is approximately %e per nucleotide per generation.\n", mutation_rate);

  // Performing a simple calculation based on user input
  printf("Please enter the number of amino acids in your protein: ");
  int num_aa;
  scanf("%d", &num_aa);

  printf("Assuming one codon per amino acid, your protein would require %d nucleotides.\n", 3*num_aa);

  // Displaying a concluding message
  printf("\n\n\t BRAVERY IN BIOLOGY AND COMPUTERS!\n");
  printf("\t----------------------------------\n\n");

  return 0;
}