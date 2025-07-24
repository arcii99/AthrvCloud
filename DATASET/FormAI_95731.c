//FormAI DATASET v1.0 Category: File Encyptor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  FILE *in_file, *out_file;
  char in_file_name[100], out_file_name[100];
  int ch;
  
  printf("Enter the name of the file to encrypt: ");
  scanf("%s", in_file_name);
  
  printf("Enter the name of the encrypted file: ");
  scanf("%s", out_file_name);
  
  in_file = fopen(in_file_name, "r");
  
  if (in_file == NULL) {
    fprintf(stderr, "Can't open input file %s\n", in_file_name);
    exit(1);
  }
  
  out_file = fopen(out_file_name, "w");
  
  if (out_file == NULL) {
    fprintf(stderr, "Can't open output file %s\n", out_file_name);
    exit(1);
  }
  
  while ((ch = getc(in_file)) != EOF) {
    putc(ch ^ 0xFF, out_file);
  }
  
  printf("Encryption successful!\n");
  
  fclose(in_file);
  fclose(out_file);
  
  return 0;
}