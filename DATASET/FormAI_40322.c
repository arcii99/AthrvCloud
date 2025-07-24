//FormAI DATASET v1.0 Category: Computer Biology ; Style: beginner-friendly
#include <stdio.h>

int main() {
  char dnaSequence[] = "ACAGATGTAGCGTACTGCGACTAGTACG";

  // Count the number of adenine (A) nucleotides in the DNA sequence
  int countA = 0;
  for(int i = 0; i < strlen(dnaSequence); i++) {
    if(dnaSequence[i] == 'A') {
      countA++;
    }
  }
  printf("Number of adenine nucleotides: %d\n", countA);

  // Count the number of thymine (T) nucleotides in the DNA sequence
  int countT = 0;
  for(int i = 0; i < strlen(dnaSequence); i++) {
    if(dnaSequence[i] == 'T') {
      countT++;
    }
  }
  printf("Number of thymine nucleotides: %d\n", countT);

  // Count the number of guanine (G) nucleotides in the DNA sequence
  int countG = 0;
  for(int i = 0; i < strlen(dnaSequence); i++) {
    if(dnaSequence[i] == 'G') {
      countG++;
    }
  }
  printf("Number of guanine nucleotides: %d\n", countG);

  // Count the number of cytosine (C) nucleotides in the DNA sequence
  int countC = 0;
  for(int i = 0; i < strlen(dnaSequence); i++) {
    if(dnaSequence[i] == 'C') {
      countC++;
    }
  }
  printf("Number of cytosine nucleotides: %d\n", countC);

  // Calculate the GC content of the DNA sequence
  float gcContent = (float)(countG + countC) / strlen(dnaSequence);
  printf("GC content: %.2f\n", gcContent);

  return 0;
}