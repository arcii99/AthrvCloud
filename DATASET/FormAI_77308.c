//FormAI DATASET v1.0 Category: Data recovery tool ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  FILE *input_file;
  FILE *output_file;
  char buffer[1024];
  char *input_filename;
  char *output_filename;
  int bytes_read = 0;

  /* make sure we have enough arguments */
  if(argc < 3) {
    printf("Usage: %s <input file> <output file>\n", argv[0]);
    return 1;
  }

  input_filename = argv[1];
  output_filename = argv[2];

  /* open the input file for reading */
  input_file = fopen(input_filename, "rb");
  if(input_file == NULL) {
    printf("Error: Unable to open %s for reading\n", input_filename);
    return 1;
  }

  /* open the output file for writing */
  output_file = fopen(output_filename, "wb");
  if(output_file == NULL) {
    printf("Error: Unable to open %s for writing\n", output_filename);
    fclose(input_file);
    return 1;
  }

  /* read from the input file and write to the output file */
  while(fread(buffer, sizeof(char), 1024, input_file) != 0) {
    bytes_read += 1024;
    fwrite(buffer, sizeof(char), 1024, output_file);
  }

  /* close the files */
  fclose(input_file);
  fclose(output_file);

  printf("Successfully recovered %d bytes of data\n", bytes_read);

  return 0;
}