//FormAI DATASET v1.0 Category: Computer Biology ; Style: beginner-friendly
#include <stdio.h>

int main() {
  int dna[10] = {0, 1, 2, 3, 0, 3, 2, 1, 0, 2};
  char protein[10] = {'A', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'K', 'L'};
  int length = sizeof(dna) / sizeof(dna[0]);
  
  printf("DNA Sequence: ");
  for (int i = 0; i < length; i++) {
    printf("%d ", dna[i]);
  }
  printf("\n");

  printf("Protein Sequence: ");
  for (int i = 0; i < length; i++) {
    int index = dna[i];
    printf("%c ", protein[index]);
  }
  printf("\n");
  
  return 0;
}