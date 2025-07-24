//FormAI DATASET v1.0 Category: Computer Biology ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROTEIN_LENGTH 10000

char *dna_sequence = "ATGCGTACTCGAGCATGACGATCGAGGAAGCGTCTACGATCGATCGATACTCGAGCGATC";
char **codon_to_amino = {"UUU F ", "CUU L ", "AUU I ", "GUU V ", "UUC F ", "CUC L ", 
                         "AUC I ", "GUC V ", "UUA L ", "CUA L ", "AUA I ", "GUA V ",
                         "UUG L ", "CUG L ", "AUG M ", "GUG V ", "UCU S ", "CCU P ",
                         "ACU T ", "GCU A ", "UCC S ", "CCC P ", "ACC T ", "GCC A ",
                         "UCA S ", "CCA P ", "ACA T ", "GCA A ", "UCG S ", "CCG P ",
                         "ACG T ", "GCG A ", "UAU Y ", "CAU H ", "AAU N ", "GAU D ",
                         "UAC Y ", "CAC H ", "AAC N ", "GAC D ", "UAA Stop", "CAA Q ",
                         "AAA K ", "GAA E ", "UAG Stop", "CAG Q ", "AAG K ", "GAG E ",
                         "UGU C ", "CGU R ", "AGU S ", "GGU G ", "UGC C ", "CGC R ",
                         "AGC S ", "GGC G ", "UGA Stop", "CGA R ", "AGA R ", "GGA G ",
                         "UGG W ", "CGG R ", "AGG R ", "GGG G "};
                         
char amino_sequence[MAX_PROTEIN_LENGTH];
int amino_index = 0;

void translate_codon(char *codon) {
  for (int i = 0; i < 64; i++) {
    if (strcmp(codon_to_amino[i], codon) == 0) {
      amino_sequence[amino_index] = codon_to_amino[i][4];
      amino_index++;
      return;
    }
  }
}

int main() {
  int dna_length = strlen(dna_sequence);
  for (int i = 0; i < dna_length - 2; i += 3) {
    char codon[4] = {dna_sequence[i], dna_sequence[i+1], dna_sequence[i+2], '\0'};
    translate_codon(codon);
  }
  printf("DNA Sequence: %s\n", dna_sequence);
  printf("Amino Acid Sequence: %s\n", amino_sequence);
  return 0;
}