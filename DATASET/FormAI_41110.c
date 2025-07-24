//FormAI DATASET v1.0 Category: Computer Biology ; Style: beginner-friendly
#include <stdio.h>

int main() {
  char dna_sequence[100];
  int i, c = 0, g = 0, a = 0, t = 0;

  printf("Enter a DNA sequence (up to 100 characters): ");
  gets(dna_sequence);

  for(i = 0; dna_sequence[i] != '\0'; i++) {
    switch(dna_sequence[i]) {
      case 'c': c++; break;
      case 'g': g++; break;
      case 'a': a++; break;
      case 't': t++; break;
      default: break;
    }
  }

  printf("\nDNA Sequence Analysis\n");
  printf("=====================\n");
  printf("Sequence: %s\n", dna_sequence);
  printf("Length: %d\n", i);

  float gc_percentage = ((float)(g + c) / i) * 100;
  printf("GC Content: %.2f%%\n", gc_percentage);

  if(a > t) {
    printf("Adenine-rich sequence\n");
  } else if(a < t) {
    printf("Thymine-rich sequence\n");
  } else {
    printf("Balanced sequence\n");
  }

  return 0;
}