//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  char base_pairs[] = {'A', 'C', 'G', 'T'};
  int num_bp = sizeof(base_pairs) / sizeof(base_pairs[0]);
  int seq_length;
  printf("Enter the desired length of the sequence: ");
  scanf("%d", &seq_length);
  if (seq_length < 1) {
    printf("Error: Sequence length must be at least 1\n");
    return 1;
  }
  
  printf("Simulating genome sequencing...\n");
  char* sequence = (char*) malloc((seq_length + 1) * sizeof(char));
  srand(time(NULL));
  for (int i = 0; i < seq_length; i++) {
    sequence[i] = base_pairs[rand() % num_bp];
  }
  sequence[seq_length] = '\0';
  
  printf("Sequence: %s\n", sequence);
  free(sequence);

  return 0;
}