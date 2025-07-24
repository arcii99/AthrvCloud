//FormAI DATASET v1.0 Category: Data recovery tool ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 256
#define MAX_BUFFER_SIZE 4096

int main() {
  char filename[MAX_FILENAME_LEN];
  printf("Enter the file name to recover: ");
  scanf("%s", filename);

  FILE *input = fopen(filename, "rb");
  if (input == NULL) {
    printf("Error: file does not exist.\n");
    return EXIT_FAILURE;
  }

  char output_filename[MAX_FILENAME_LEN];
  strcpy(output_filename, filename);
  strcat(output_filename, ".recovered");
  FILE *output = fopen(output_filename, "wb");

  unsigned char buffer[MAX_BUFFER_SIZE];
  size_t bytes_read;

  while ((bytes_read = fread(buffer, 1, sizeof(buffer), input)) > 0) {
    fwrite(buffer, 1, bytes_read, output);
  }

  fclose(input);
  fclose(output);

  printf("File %s has been recovered as %s.\n", filename, output_filename);

  return EXIT_SUCCESS;
}