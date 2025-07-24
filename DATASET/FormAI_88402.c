//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define DNA_LENGTH 30 // length of the DNA strand to be simulated
#define BASES "ACTG" // possible bases in DNA strand

int main() {
  
  // declare variables
  char dna[DNA_LENGTH];
  int i, j, k;
  srand(time(NULL)); // seed random number generator with current time
  
  // initialize DNA strand with random bases
  for(i=0; i<DNA_LENGTH; i++) {
    dna[i] = BASES[rand()%4];
  }
  
  // print original DNA strand
  printf("Original DNA strand: ");
  for(i=0; i<DNA_LENGTH; i++) {
    printf("%c", dna[i]);
  }
  printf("\n");
  
  // create three mutated DNA strands
  char dna1[DNA_LENGTH], dna2[DNA_LENGTH], dna3[DNA_LENGTH];
  
  // create mutation #1 by changing one random base
  j = rand()%DNA_LENGTH; // choose random index
  dna1[j] = BASES[rand()%4]; // change random base
  for(i=0; i<DNA_LENGTH; i++) {
    if(i!=j) { // copy unchanged bases from original DNA strand
      dna1[i] = dna[i];
    }
  }
  
  // create mutation #2 by inserting one random base
  j = rand()%DNA_LENGTH; // choose random index
  for(i=0; i<DNA_LENGTH; i++) {
    if(i<j) { // copy bases before insert position from original DNA strand
      dna2[i] = dna[i];
    } else if(i==j) { // insert random base
      dna2[i] = BASES[rand()%4];
    } else { // copy remaining bases from original DNA strand
      dna2[i] = dna[i-1];
    }
  }
  
  // create mutation #3 by deleting one random base
  j = rand()%DNA_LENGTH; // choose random index
  k = 0; // initialize loop counter
  for(i=0; i<DNA_LENGTH; i++) {
    if(i!=j) { // copy bases from original DNA strand except for deleted base
      dna3[k] = dna[i];
      k++; // increment loop counter
    }
  }
  
  // print all mutated DNA strands
  printf("Mutation 1: ");
  for(i=0; i<DNA_LENGTH; i++) {
    printf("%c", dna1[i]);
  }
  printf("\n");
  
  printf("Mutation 2: ");
  for(i=0; i<DNA_LENGTH; i++) {
    printf("%c", dna2[i]);
  }
  printf("\n");
  
  printf("Mutation 3: ");
  for(i=0; i<DNA_LENGTH-1; i++) { // print only first 29 bases
    printf("%c", dna3[i]);
  }
  printf("\n");
  
  return 0;
}