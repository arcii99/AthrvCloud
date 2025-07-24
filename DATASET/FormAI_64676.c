//FormAI DATASET v1.0 Category: Computer Biology ; Style: relaxed
#include <stdio.h>

int main() {
  // In this program, we will be simulating the transcription process in biology.
  // RNA polymerase reads DNA and creates a complementary strand of RNA.

  char DNA_sequence[100];
  char RNA_sequence[100];

  printf("Enter a DNA sequence: ");
  scanf("%s", DNA_sequence);

  // Generate complementary RNA strand
  for(int i=0; DNA_sequence[i]!='\0'; i++) {
    if(DNA_sequence[i] == 'A') {
      RNA_sequence[i] = 'U';
    } else if(DNA_sequence[i] == 'T') {
      RNA_sequence[i] = 'A';
    } else if(DNA_sequence[i] == 'C') {
      RNA_sequence[i] = 'G';
    } else if(DNA_sequence[i] == 'G') {
      RNA_sequence[i] = 'C';
    } else {
      // If there's a character that's not A, T, C, or G, then exit the program
      printf("Invalid DNA sequence!\n");
      return 0;
    }
  }

  // Print out RNA sequence
  printf("RNA sequence: %s\n", RNA_sequence);

  return 0;
}