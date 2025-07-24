//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

/* Struct to represent metadata */
typedef struct metadata {
  char key[MAX_LINE_LENGTH];
  char value[MAX_LINE_LENGTH];
} Metadata;

/* Struct to hold all the metadata */
typedef struct metadata_collection {
  Metadata* metadata_array[MAX_LINE_LENGTH];
  int count;
} MetadataCollection;

/* Function to read metadata from a file */
void read_metadata_from_file(char* filename, MetadataCollection* collection);

/* Function to search for a specific key in metadata */
Metadata* find_metadata_by_key(char* key, MetadataCollection* collection);

/* Main function */
int main(int argc, char** argv) {
  if (argc < 2) {
    printf("Usage: %s <input file>\n", argv[0]);
    return -1;
  }

  char* filename = argv[1];

  MetadataCollection collection;
  collection.count = 0;

  read_metadata_from_file(filename, &collection);

  // Find metadata by key
  char search_key[MAX_LINE_LENGTH];
  printf("Enter metadata key to search: ");
  fgets(search_key, MAX_LINE_LENGTH, stdin);

  Metadata* result = find_metadata_by_key(search_key, &collection);

  if (result != NULL) {
    printf("Metadata value: %s\n", result->value);
  } else {
    printf("Metadata not found.\n");
  }

  return 0;
}

void read_metadata_from_file(char* filename, MetadataCollection* collection) {
  FILE* file = fopen(filename, "r");

  if (file == NULL) {
    printf("Error: could not open file %s.\n", filename);
    exit(-1);
  }

  char line[MAX_LINE_LENGTH];

  while (fgets(line, MAX_LINE_LENGTH, file)) {
    // Parse metadata key and value from line
    char* key = strtok(line, ":");
    char* value = strtok(NULL, "\n");

    if (key != NULL && value != NULL) {
      // Create a new metadata struct
      Metadata* metadata = (Metadata*) malloc(sizeof(Metadata));
      strcpy(metadata->key, key);
      strcpy(metadata->value, value);

      // Add metadata to collection
      collection->metadata_array[collection->count] = metadata;
      collection->count++;
    }
  }

  fclose(file);
}

Metadata* find_metadata_by_key(char* key, MetadataCollection* collection) {
  for (int i = 0; i < collection->count; i++) {
    Metadata* metadata = collection->metadata_array[i];

    if (strcmp(metadata->key, key) == 0) {
      return metadata;
    }
  }

  return NULL;
}