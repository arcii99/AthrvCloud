//FormAI DATASET v1.0 Category: Computer Biology ; Style: active
#include <stdio.h>

int main() {
  char dna[] = "AGTCTGCAATCGGTAGCCTGAAGGTTCGAGTACGCGCTTA";
  int adenineCount = 0, cytosineCount = 0, guanineCount = 0, thymineCount = 0;

  for(int i = 0; dna[i] != '\0'; i++) {
    switch(dna[i]) {
      case 'A':
        adenineCount++;
        break;
      case 'C':
        cytosineCount++;
        break;
      case 'G':
        guanineCount++;
        break;
      case 'T':
        thymineCount++;
        break;
    }
  }

  printf("Number of Adenine: %d\n", adenineCount);
  printf("Number of Cytosine: %d\n", cytosineCount);
  printf("Number of Guanine: %d\n", guanineCount);
  printf("Number of Thymine: %d\n", thymineCount);

  return 0;
}