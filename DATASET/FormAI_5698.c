//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // seed random number generator 

  // define nucleotides
  char nucleotides[4] = {'A', 'C', 'G', 'T'};

  // define length of genome
  int genome_length = 1000;

  // create genome string
  char genome[genome_length];

  // generate genome
  int i;
  for (i=0; i<genome_length; i++) {
    int rand_num = rand() % 4; // get random number between 0 and 3
    genome[i] = nucleotides[rand_num]; // assign random nucleotide
  }

  // print genome
  printf("Genome sequence: %s\n", genome);
  
  return 0;
}