//FormAI DATASET v1.0 Category: Computer Biology ; Style: portable
#include <stdio.h>

int main() {
  // Define variables for DNA sequence and nucleotide counts
  char dna_seq[101];
  int a_count = 0, c_count = 0, g_count = 0, t_count = 0;

  // Ask user for DNA sequence input
  printf("Please enter a DNA sequence (up to 100 nucleotides):\n");
  scanf("%s", dna_seq);

  // Loop through each nucleotide in sequence and count occurrence of A, C, G, T
  for (int i = 0; dna_seq[i] != '\0'; i++) {
    if (dna_seq[i] == 'A') {
      a_count++;
    } else if (dna_seq[i] == 'C') {
      c_count++;
    } else if (dna_seq[i] == 'G') {
      g_count++;
    } else if (dna_seq[i] == 'T') {
      t_count++;
    }
  }

  // Output nucleotide counts and calculate GC content
  float gc_content = ((float)(g_count + c_count) / (float)(a_count + c_count + g_count + t_count)) * 100;
  printf("Nucleotide counts:\nA: %d\nC: %d\nG: %d\nT: %d\n", a_count, c_count, g_count, t_count);
  printf("GC Content: %.2f%%\n", gc_content);

  return 0;
}