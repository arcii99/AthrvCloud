//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 1000

char generateNucleotide() {
  int r = rand() % 4;
  if (r == 0) {
    return 'A';
  } else if (r == 1) {
    return 'C';
  } else if (r == 2) {
    return 'G';
  } else {
    return 'T';
  }
}

void generateSequence(char* seq, int length) {
  srand(time(0));
  for (int i = 0; i < length; i++) {
    seq[i] = generateNucleotide();
  }
  seq[length] = '\0';
}

int main() {
  char seq[MAX_LENGTH];
  int length;
  printf("Enter the length of the sequence: ");
  scanf("%d", &length);
  if (length > MAX_LENGTH) {
    printf("Length cannot exceed %d\n", MAX_LENGTH);
    return 1;
  }
  generateSequence(seq, length);
  printf("Generated sequence: %s\n", seq);
  return 0;
}