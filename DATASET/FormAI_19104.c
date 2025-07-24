//FormAI DATASET v1.0 Category: Data recovery tool ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_BUFFER_SIZE 1024

int main() {
  char file_name[MAX_FILE_NAME_LENGTH];
  char buffer[MAX_BUFFER_SIZE];
  FILE *file_pointer;
  int total_read_size = 0;

  printf("Enter the file name to recover: ");
  fgets(file_name, MAX_FILE_NAME_LENGTH, stdin);
  strtok(file_name, "\n"); // remove the newline character from input

  file_pointer = fopen(file_name, "r");

  if (!file_pointer) {
    printf("Could not open file. Exiting...\n");
    exit(1);
  }

  printf("\nFile contents:\n");

  while (!feof(file_pointer)) {
    int read_size = fread(buffer, 1, MAX_BUFFER_SIZE, file_pointer);
    total_read_size += read_size;

    printf("%s", buffer);
  }

  printf("\n\nTotal bytes read: %d\n", total_read_size);

  fclose(file_pointer);

  return 0;
}