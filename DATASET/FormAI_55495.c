//FormAI DATASET v1.0 Category: File Encyptor ; Style: lively
#include <stdio.h>
#include <stdlib.h>

int main() {
  char input_file[50], output_file[50];
  int key;

  printf("Welcome to the C File Encryptor program!\n");
  printf("Please enter the name of the input file: ");
  scanf("%s", input_file);
  printf("Please enter the name of the output file: ");
  scanf("%s", output_file);
  printf("Please enter the encryption key: ");
  scanf("%d", &key);

  FILE *in_file = fopen(input_file, "rb");
  FILE *out_file = fopen(output_file, "wb");

  if (in_file == NULL) {
    printf("Error: Could not open input file.\n");
    exit(1);
  }
  if (out_file == NULL) {
    printf("Error: Could not open output file.\n");
    exit(1);
  }

  fseek(in_file, 0L, SEEK_END);
  int file_size = ftell(in_file);
  rewind(in_file);

  char *buffer = (char*) malloc(file_size * sizeof(char));
  fread(buffer, file_size, 1, in_file);

  for (int i = 0; i < file_size; i++) {
    buffer[i] = buffer[i] ^ key; // XOR encryption
  }

  fwrite(buffer, file_size, 1, out_file);

  printf("Encryption complete! The encrypted file '%s' has been created.\n", output_file);

  fclose(in_file);
  fclose(out_file);
  free(buffer);

  return 0;
}