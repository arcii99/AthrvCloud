//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to extract metadata from a C source file
void extract_metadata(char* filename) {
  // Open the file in read mode
  FILE* fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Error: Could not open file %s!\n", filename);
    return;
  }

  // Read the contents of the file
  char buffer[1000];
  char* metadata = malloc(500);
  int line_count = 0;
  int metadata_count = 0;
  while (fgets(buffer, 1000, fp) != NULL) {
    // Search for metadata
    if (strstr(buffer, "KEYWORDS:") != NULL) {
      // Copy the metadata into our metadata string
      char* ptr = strstr(buffer, "KEYWORDS:");
      ptr += strlen("KEYWORDS:");
      while (*ptr == ' ') ptr++;
      strcpy(metadata, ptr);
      metadata_count++;
    }

    // Count the lines in our C program
    line_count++;
  }

  // Close the file
  fclose(fp);

  // Print out the metadata we found
  if (metadata_count == 0) {
    printf("Error: Could not find any metadata in file %s!\n", filename);
  } else {
    printf("Metadata found in file %s:\n", filename);
    printf("%s", metadata);
  }

  // Print out the line count of our C program
  printf("Total lines in C program: %d\n", line_count);
}

int main() {
  // Call the extract_metadata function with our C program filename
  extract_metadata("hello.c");

  return 0;
}