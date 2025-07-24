//FormAI DATASET v1.0 Category: File Encyptor ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: ./encryptor [input_file] [output_file]\n");
    exit(1);
  }

  char *key = "shocking_key_y'all";
  size_t key_len = strlen(key);

  FILE *input = fopen(argv[1], "r");
  FILE *output = fopen(argv[2], "w");

  if (!input || !output) {
    printf("Could not open file. Are you sure you provided valid file names?\n");
    exit(1);
  }

  fseek(input, 0L, SEEK_END); // Get input file size
  size_t file_size = ftell(input);
  fseek(input, 0L, SEEK_SET);

  char *file_contents = (char *) malloc(file_size);
  fread(file_contents, sizeof(char), file_size, input);

  for (int i = 0; i < file_size; i++) {
    file_contents[i] ^= key[i % key_len];
  }

  fwrite(file_contents, sizeof(char), file_size, output);

  fclose(input);
  fclose(output);
  free(file_contents);

  printf("Encryption complete. Your file has been successfully encrypted with a shocking key!\n");

  return 0;
}