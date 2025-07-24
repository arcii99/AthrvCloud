//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  // Ensure command line arg is provided
  if (argc < 2) {
    printf("Usage: %s <file_name>\n", argv[0]);
    exit(0);
  }

  // Open file
  char *filename = argv[1];
  FILE *fp = fopen(filename, "rb");
  if (fp == NULL) {
    printf("Error opening file: %s\n", filename);
    exit(0);
  }

  // Calculate checksum
  unsigned int checksum = 0;
  unsigned char byte;
  while (fread(&byte, sizeof(byte), 1, fp)) {
    checksum = (checksum << 1) + byte;
  }
  fclose(fp);

  // Print result
  printf("Checksum for %s using Math-based algorithm is: %u\n", filename, checksum);

  return 0;
}