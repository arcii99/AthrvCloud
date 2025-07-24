//FormAI DATASET v1.0 Category: Computer Biology ; Style: expert-level
#include <stdio.h>

int main() {
  
  // Define the DNA sequence
  char dna_seq[] = "ATCGTAGCTAGCTAGCTAGCTAGCTAGCTAGCATGCGCGCGCGCGCGATCGTAGCTAGCTAGCTAGCTAGCTAGCT";

  // Print the original DNA sequence
  printf("Original DNA sequence: %s\n", dna_seq);

  // Reverse Complement the DNA sequence
  int dna_len = strlen(dna_seq);
  char rev_comp_seq[dna_len+1];
  for(int i=dna_len-1; i>=0; i--) {
    if(dna_seq[i] == 'A') {
      rev_comp_seq[dna_len-i-1] = 'T';
    } else if(dna_seq[i] == 'T') {
      rev_comp_seq[dna_len-i-1] = 'A';
    } else if(dna_seq[i] == 'C') {
      rev_comp_seq[dna_len-i-1] = 'G';
    } else if(dna_seq[i] == 'G') {
      rev_comp_seq[dna_len-i-1] = 'C';
    }
  }
  rev_comp_seq[dna_len] = '\0';

  // Print the Reversed Complement DNA sequence
  printf("Reversed Complement DNA sequence: %s\n", rev_comp_seq);
  
  // Find the Codons
  int num_codons = dna_len / 3;
  char codons[num_codons+1][4];
  for(int i=0; i<num_codons; i++) {
    for(int j=0; j<3; j++) {
      codons[i][j] = dna_seq[i*3+j];
    }
    codons[i][3] = '\0';
  }
  codons[num_codons][0] = '\0';

  // Print the Codons
  printf("Codons in the DNA sequence:\n");
  for(int i=0; i<num_codons; i++) {
    printf("%s ", codons[i]);
  }
  printf("\n");

  return 0;
}