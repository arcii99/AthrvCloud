//FormAI DATASET v1.0 Category: File handling ; Style: Sherlock Holmes
#include <stdio.h>

int main() {
  // Our file name is a clue to the mystery
  char filename[] = "the-adventure-of-the-speckled-band.txt";

  // First, we need to open the file
  FILE *file = fopen(filename, "r");

  // If the file cannot be opened, it's a dead end
  if (!file) {
    printf("Alas, the case is unsolvable. The file could not be opened!\n");
    return 1; // Exit the program
  }

  // Let's search for the evidence we need in the file
  char keyword[] = "speckled band";
  char line[256];
  int line_number = 1;
  int found = 0;

  while (fgets(line, sizeof(line), file)) {
    // If we find the keyword in the line, we've cracked the case.
    if (strstr(line, keyword)) {
      printf("Aha! The speckled band was found in line %d of the file!\n", line_number);
      found = 1;
      break; // Case solved
    }

    line_number++;
  }

  // If we didn't find the evidence, the case remains unsolved
  if (!found) {
    printf("It appears the speckled band was not found in the file. The case remains unsolved.\n");
  }

  // Once we're done with the file, we close it
  fclose(file);

  return 0; // Case closed
}