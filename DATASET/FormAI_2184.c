//FormAI DATASET v1.0 Category: Error handling ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

int main() {

  FILE *file_ptr = NULL;
  char file_name[] = "example.txt";

  // Attempt to open file
  if ((file_ptr = fopen(file_name, "r")) == NULL) {
    fprintf(stderr, "Error opening file.\n");
    exit(1);
  }

  // Continue with program if file was successfully opened
  printf("File opened successfully!\n");

  // Close file pointer before exiting program
  fclose(file_ptr);

  return 0;
}