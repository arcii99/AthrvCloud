//FormAI DATASET v1.0 Category: Data recovery tool ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *file;         // Pointer to file
  char *buffer;       // Pointer to buffer to store data
  int length;         // Length of data to be read
  int fsize, i;       // File size and loop counter
  char c;             // Temporary character

  // Open the file for reading in binary mode
  file = fopen("datafile.bin", "rb");

  // Check if file exists and can be opened
  if (!file) {
    printf("Error: File 'datafile.bin' could not be opened.\n");
    return 1;
  }

  // Determine file size
  fseek(file, 0, SEEK_END);
  fsize = ftell(file);
  fseek(file, 0, SEEK_SET);

  // Allocate memory for buffer
  buffer = (char *)malloc(fsize);

  // Read data into buffer
  fread(buffer, sizeof(char), fsize, file);

  // Print data to console
  printf("Data read from file:\n");
  for (i = 0; i < fsize; i++) {
    c = buffer[i];
    printf("%c", c);
  }

  // Clean up
  free(buffer);
  fclose(file);

  return 0;
}