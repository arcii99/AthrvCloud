//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for metadata
typedef struct metadata {
  char title[100];
  char artist[100];
  char album[100];
  int year;
} Metadata;

// Function to extract metadata from file
Metadata extract_metadata(char* file_path) {
  FILE* file = fopen(file_path, "r");
  Metadata metadata;
  char* line = NULL;
  size_t len = 0;
  ssize_t read;

  if (file == NULL) {
    printf("Error opening file!\n");
    exit(1);
  }

  // Extract each line of metadata from the file
  while ((read = getline(&line, &len, file)) != -1) {
    char* token = strtok(line, ":");
    if (strcmp(token, "Title") == 0) {
      token = strtok(NULL, ":");
      strcpy(metadata.title, token);
    }
    else if (strcmp(token, "Artist") == 0) {
      token = strtok(NULL, ":");
      strcpy(metadata.artist, token);
    }
    else if (strcmp(token, "Album") == 0) {
      token = strtok(NULL, ":");
      strcpy(metadata.album, token);
    }
    else if (strcmp(token, "Year") == 0) {
      token = strtok(NULL, ":");
      metadata.year = atoi(token);
    }
  }

  fclose(file);
  if (line)
    free(line);

  return metadata;
}

int main() {
  Metadata metadata = extract_metadata("./example.mp3");

  printf("Title: %s\n", metadata.title);
  printf("Artist: %s\n", metadata.artist);
  printf("Album: %s\n", metadata.album);
  printf("Year: %d\n", metadata.year);

  return 0;
}