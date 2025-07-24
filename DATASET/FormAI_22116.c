//FormAI DATASET v1.0 Category: Error handling ; Style: portable
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  FILE *file;
  char *filename = "nonexistent_file.txt";

  // Try to open file and check for errors
  file = fopen(filename, "r");
  if (file == NULL) {
    perror("Error opening file");
    exit(EXIT_FAILURE);
  }

  // Do something with the file

  // Close file and check for errors
  if (fclose(file) != 0) {
    perror("Error closing file");
    exit(EXIT_FAILURE);
  }

  return 0;
}