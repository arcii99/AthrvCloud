//FormAI DATASET v1.0 Category: Data recovery tool ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512

int main(int argc, char *argv[]) {
  // Check if user provided arguments
  if (argc < 3) {
    printf("Usage: data_recovery_tool <source> <destination>\n");
    return 1;
  }

  // Get source and destination filenames
  char *source = argv[1];
  char *destination = argv[2];

  // Open source file for reading
  FILE *source_file = fopen(source, "rb");
  if (!source_file) {
    printf("Error: cannot open file '%s' for reading\n", source);
    return 1;
  }

  // Open destination file for writing
  FILE *destination_file = fopen(destination, "wb");
  if (!destination_file) {
    printf("Error: cannot open file '%s' for writing\n", destination);
    fclose(source_file);
    return 1;
  }

  // Initialize buffer for reading data
  unsigned char buffer[BLOCK_SIZE];

  // Read data from source file in BLOCK_SIZE chunks and write to destination file
  int bytes_read;
  do {
    bytes_read = fread(buffer, sizeof(unsigned char), BLOCK_SIZE, source_file);
    if (bytes_read < BLOCK_SIZE) {
      memset(buffer + bytes_read, 0, BLOCK_SIZE - bytes_read);
    }
    fwrite(buffer, sizeof(unsigned char), BLOCK_SIZE, destination_file);
  } while (bytes_read == BLOCK_SIZE);

  // Close files
  fclose(source_file);
  fclose(destination_file);

  printf("Data recovery successful!\n");

  return 0;
}