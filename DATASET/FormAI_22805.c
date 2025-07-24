//FormAI DATASET v1.0 Category: Computer Biology ; Style: portable
#include <stdio.h>

int main() {
  // Prompt user for DNA sequence input
  printf("Enter a DNA sequence: ");
  
  // Declare and initialize variables
  char ch;
  int adenine = 0, cytosine = 0, guanine = 0, thymine = 0, length = 0;
  
  // Read input character by character until end of line
  while ((ch = getchar()) != '\n') {
    switch (ch) {
      case 'A':
      case 'a':
        adenine++;
        break;
      case 'C':
      case 'c':
        cytosine++;
        break;
      case 'G':
      case 'g':
        guanine++;
        break;
      case 'T':
      case 't':
        thymine++;
        break;
      default:
        printf("Invalid character %c\n", ch);
        break;
    }
    
    length++;
  }
  
  // Output results
  printf("Adenine: %d\n", adenine);
  printf("Cytosine: %d\n", cytosine);
  printf("Guanine: %d\n", guanine);
  printf("Thymine: %d\n", thymine);
  printf("Length: %d\n", length);
  
  return 0;
}