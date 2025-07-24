//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Welcome to the Happy Metadata Extractor!\n");
  char filename[100];
  printf("Please enter the name of the file you wish to extract metadata from: ");
  scanf("%s", filename);

  FILE *file_ptr;
  file_ptr = fopen(filename, "r");

  if (file_ptr == NULL) {
    printf("Oops, there was an error opening the file. Please make sure you typed the correct filename.\n");
    exit(0);
  }

  printf("\nThe metadata for file \"%s\" is:\n", filename);
  printf("------------------------------------------------\n");

  char line[100];
  while (fgets(line, 100, file_ptr)) {
    if (line[0] == '#') {
      printf("%s", line);
    }
  }

  fclose(file_ptr);

  printf("\nThank you for using the Happy Metadata Extractor!\n");
  return 0;
}