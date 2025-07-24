//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char metadata[] = "filename: example.txt \nauthor: John Doe\ncreated: 2022-01-01\n";

  // Parse metadata
  char* filename_pos = strstr(metadata, "filename: ");
  char* author_pos = strstr(metadata, "author: ");
  char* created_pos = strstr(metadata, "created: ");

  // Extract values
  char filename[100];
  char author[100];
  char created[100];

  if (filename_pos) {
    sscanf(filename_pos, "filename: %[^\n]", filename);
  } else {
    printf("Error: Could not find filename in metadata.\n");
    return 1;
  }

  if (author_pos) {
    sscanf(author_pos, "author: %[^\n]", author);
  } else {
    printf("Error: Could not find author in metadata.\n");
    return 1;
  }

  if (created_pos) {
    sscanf(created_pos, "created: %[^\n]", created);
  } else {
    printf("Error: Could not find created date in metadata.\n");
    return 1;
  }

  // Print extracted values
  printf("Filename: %s\n", filename);
  printf("Author: %s\n", author);
  printf("Created date: %s\n", created);

  return 0;
}