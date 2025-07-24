//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_PATH_LENGTH 256 
#define MAX_METADATA_LENGTH  1024

char* metadata_from_file(char* file_path) {
  char metadata[MAX_METADATA_LENGTH];
  FILE* file = fopen(file_path, "r");
  
  if (file == NULL) {
    printf("File not found!\n");
    exit(1);
  }
  
  char line[256];
  
  while(fgets(line, MAX_METADATA_LENGTH, file)) {
    if (strstr(line, "#META:")) {
      strncat(metadata, line, MAX_METADATA_LENGTH - strlen(metadata) - 1);
    }
  }
  
  fclose(file);
  return strdup(metadata);
}

int main(int argc, char** argv) {
  if (argc != 2) {
    printf("Usage: %s file_path\n", argv[0]);
    exit(1);
  }
  
  char* file_path = argv[1];
  char* metadata = metadata_from_file(file_path);
  
  printf("Metadata extracted from %s:\n", file_path);
  printf("%s\n", metadata);
  
  free(metadata);
  return 0;
}