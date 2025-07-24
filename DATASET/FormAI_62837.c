//FormAI DATASET v1.0 Category: Computer Biology ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SEQUENCE_LENGTH 10000
#define AMINO_ACIDS_COUNT 20

int main() {
  char dnaSeq[MAX_SEQUENCE_LENGTH], rnaSeq[MAX_SEQUENCE_LENGTH], proteinSeq[MAX_SEQUENCE_LENGTH];
  int dnaSeqLen, rnaSeqLen, proteinSeqLen;

  // Read the DNA sequence
  printf("Enter the DNA sequence:\n");
  fgets(dnaSeq, MAX_SEQUENCE_LENGTH, stdin);
  dnaSeqLen = strlen(dnaSeq);

  // Transcribe the DNA sequence into RNA sequence
  for (int i = 0; i < dnaSeqLen; ++i) {
    if (toupper(dnaSeq[i]) == 'T') {
      rnaSeq[i] = 'U';
    } else {
      rnaSeq[i] = toupper(dnaSeq[i]);
    }
  }
  rnaSeqLen = dnaSeqLen;

  // Translate the RNA sequence into protein sequence
  const char *aminoAcids[AMINO_ACIDS_COUNT] = {"ALA", "ARG", "ASN", "ASP", "CYS", "GLN", "GLU", "GLY",
                                               "HIS", "ILE", "LEU", "LYS", "MET", "PHE", "PRO", "SER",
                                               "THR", "TRP", "TYR", "VAL"};

  for (int i = 0; i < rnaSeqLen / 3; ++i) {
    char codon[4] = {rnaSeq[i * 3], rnaSeq[i * 3 + 1], rnaSeq[i * 3 + 2], '\0'};

    int aminoAcidIndex = -1;
    for (int j = 0; j < AMINO_ACIDS_COUNT; ++j) {
      if (strcmp(codon, aminoAcids[j]) == 0) {
        aminoAcidIndex = j;
        break;
      }
    }

    if (aminoAcidIndex == -1) {
      printf("Invalid codon %s\n", codon);
      exit(1);
    }

    proteinSeq[i] = aminoAcids[aminoAcidIndex][0];
    proteinSeq[i + 1] = aminoAcids[aminoAcidIndex][1];
    proteinSeq[i + 2] = aminoAcids[aminoAcidIndex][2];
  }
  proteinSeqLen = rnaSeqLen / 3;

  // Print the DNA, RNA, and protein sequences
  printf("DNA sequence:\n%s\n", dnaSeq);
  printf("RNA sequence:\n%s\n", rnaSeq);
  printf("Protein sequence:\n%s\n", proteinSeq);

  return 0;
}