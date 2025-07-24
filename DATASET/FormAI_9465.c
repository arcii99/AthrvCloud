//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: puzzling
#include <stdio.h>

int main() {
  char dnaSeq[1000];
  int n;

  printf("Enter the DNA sequence: ");
  scanf("%s", dnaSeq);

  printf("\nSequence: %s\n", dnaSeq);

  printf("\nEnter the number of base pairs to read: ");
  scanf("%d", &n);

  printf("\nReading DNA sequence in groups of %d base pairs:\n\n", n);

  int i, j;
  for (i = 0; dnaSeq[i] != '\0'; i += n) {
    for (j = i; j < i + n && dnaSeq[j] != '\0'; j++) {
      printf("%c", dnaSeq[j]);
    }
    printf("\n");
  }

  return 0;
}