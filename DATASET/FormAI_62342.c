//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

/* Function to extract metadata from files */
void extract_metadata(char* filename) {
  printf("Extracting metadata from %s...\n", filename);

  /* Open file */
  FILE* fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Error: Unable to open file %s\n", filename);
    return;
  }

  /* Read metadata */
  char* metadata = (char*) malloc(sizeof(char) * 100);
  fgets(metadata, 100, fp);

  /* Display metadata */
  printf("Metadata:\n%s\n", metadata);

  /* Close file and free memory */
  fclose(fp);
  free(metadata);

  printf("Metadata extraction complete.\n");
}

int main() {
  printf("Welcome to the Metadata Extractor. Please enter a filename:\n");

  /* Get filename from user */
  char* filename = (char*) malloc(sizeof(char) * 256);
  scanf("%s", filename);

  /* Extract metadata */
  extract_metadata(filename);

  /* Free memory */
  free(filename);

  printf("Exiting Metadata Extractor...\n");
  return 0;
}