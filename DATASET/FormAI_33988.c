//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 128
#define MAX_METADATA_LEN 1024

// Function to extract metadata from a file
char* extract_metadata(char* filename) {
  char* metadata = (char*)malloc(sizeof(char) * MAX_METADATA_LEN);
  memset(metadata, '\0', MAX_METADATA_LEN);

  // Open the file in read mode
  FILE* file = fopen(filename, "r");
  if (file == NULL) {
    printf("Could not open the file: %s\n", filename);
    exit(1);
  }

  // Read the metadata from the file
  char line[MAX_METADATA_LEN];
  while (fgets(line, MAX_METADATA_LEN, file) != NULL) {
    if (strstr(line, "METADATA:") != NULL) {
      strcat(metadata, line);
    }
  }

  // Close the file
  fclose(file);

  return metadata;
}

int main() {
  char filename[MAX_FILENAME_LEN];
  printf("Enter the name of the file to extract metadata from: ");
  scanf("%s", filename);

  // Extract metadata from the file
  char* metadata = extract_metadata(filename);

  printf("Metadata extracted from %s:\n", filename);
  printf("%s", metadata);

  // Free the dynamically allocated memory
  free(metadata);

  return 0;
}