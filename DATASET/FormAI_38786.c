//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 1024
#define MAX_METADATA 30

int main(int argc, char *argv[]) {
  char line[MAX_CHARS];
  char metadata[MAX_METADATA][MAX_CHARS];
  int num_metadata = 0;

  if (argc < 2) {
    fprintf(stderr, "Usage: %s filename\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  FILE *fp = fopen(argv[1], "r");
  if (!fp) {
    fprintf(stderr, "Error opening file: %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  while (fgets(line, MAX_CHARS, fp)) {
    // Check if the line contains metadata
    if (line[0] == '#' && num_metadata < MAX_METADATA) {
      // Remove the '#' character and trailing whitespace
      char *ptr = line + 1;
      while (*ptr == ' ' || *ptr == '\t') {
        ptr++;
      }
      // Copy metadata to the metadata array
      strcpy(metadata[num_metadata], ptr);
      num_metadata++;
    }
  }

  fclose(fp);

  // Print the extracted metadata
  printf("Metadata found in %s:\n", argv[1]);
  for (int i = 0; i < num_metadata; i++) {
    printf("%d: %s\n", i + 1, metadata[i]);
  }

  return EXIT_SUCCESS;
}