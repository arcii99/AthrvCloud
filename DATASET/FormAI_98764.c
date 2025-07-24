//FormAI DATASET v1.0 Category: Data recovery tool ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHUNK_SIZE 512

char* find_extension(char* filename) {
  char* extension = strrchr(filename, '.');
  return extension ? extension+1 : "";
}

void recover_data(char* filepath) {
  FILE* fptr = fopen(filepath, "rb");
  
  if (!fptr) {
    printf("File not found: %s\n", filepath);
    return;
  }
  
  char* extension = find_extension(filepath);
  char new_filename[100];
  sprintf(new_filename, "recovered.%s", extension);
  FILE* output = fopen(new_filename, "wb");
  
  char* buffer = (char*) malloc(CHUNK_SIZE);
  size_t bytes_read = 0;
  while ((bytes_read = fread(buffer, 1, CHUNK_SIZE, fptr)) > 0) {
    fwrite(buffer, 1, bytes_read, output);
    memset(buffer, 0, CHUNK_SIZE);
  }
  
  printf("File recovered: %s\n", new_filename);
  fclose(output);
  free(buffer);
}

int main(int argc, char** argv) {
  if (argc < 2) {
    printf("Usage: data-recovery-tool <path/to/file>\n");
    return 1;
  }
  
  recover_data(argv[1]);
  return 0;
}