//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
  This program extracts metadata from a file, assuming that 
  the metadata is located in the header of the file.

  The metadata format assumed is:
  - The file has a header that is exactly 16 bytes long
  - The header contains a 4-byte integer in little-endian format
    representing the number of metadata items that follow.
  - Each metadata item consists of two 4-byte integers in little-endian 
    format: the first represents the length of the metadata string 
    (excluding the null-terminator), and the second represents its 
    offset from the beginning of the file.
  - The metadata strings are located immediately following the metadata
    items, with no padding or other delimiter between them.

  The program takes a filename as a command-line argument, and extracts 
  the metadata from it if possible. The metadata is printed to stdout
  in the format: "<offset>: <metadata>".
*/

int main(int argc, char *argv[]) {
  // Check command-line arguments.
  if (argc != 2) {
    printf("Error: invalid arguments\n");
    printf("Usage: metadata_extractor <filename>\n");
    return 1;
  }

  // Open the file.
  FILE *file = fopen(argv[1], "rb");
  if (file == NULL) {
    printf("Error: could not open file\n");
    return 1;
  }

  // Read the header.
  char header[16];
  if (fread(header, 1, 16, file) != 16) {
    printf("Error: invalid file format\n");
    fclose(file);
    return 1;
  }

  // Extract the number of metadata items.
  int num_metadata;
  memcpy(&num_metadata, header, 4);
  num_metadata = le32toh(num_metadata);

  // Extract the metadata items.
  int *metadata_lens = (int*) malloc(num_metadata * sizeof(int));
  int *metadata_offsets = (int*) malloc(num_metadata * sizeof(int));
  for (int i = 0; i < num_metadata; i++) {
    if (fread(&(metadata_lens[i]), 4, 1, file) != 1) {
      printf("Error: invalid file format\n");
      free(metadata_lens);
      free(metadata_offsets);
      fclose(file);
      return 1;
    }
    if (fread(&(metadata_offsets[i]), 4, 1, file) != 1) {
      printf("Error: invalid file format\n");
      free(metadata_lens);
      free(metadata_offsets);
      fclose(file);
      return 1;
    }
    metadata_lens[i] = le32toh(metadata_lens[i]);
    metadata_offsets[i] = le32toh(metadata_offsets[i]);
  }

  // Extract the metadata strings.
  for (int i = 0; i < num_metadata; i++) {
    char *metadata = (char*) malloc((metadata_lens[i] + 1) * sizeof(char));
    fseek(file, metadata_offsets[i], SEEK_SET);
    if (fread(metadata, 1, metadata_lens[i], file) != metadata_lens[i]) {
      printf("Error: invalid file format\n");
      free(metadata);
      free(metadata_lens);
      free(metadata_offsets);
      fclose(file);
      return 1;
    }
    metadata[metadata_lens[i]] = '\0';
    printf("%d: %s\n", metadata_offsets[i], metadata);
    free(metadata);
  }

  // Clean up.
  free(metadata_lens);
  free(metadata_offsets);
  fclose(file);
  return 0;
}