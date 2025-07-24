//FormAI DATASET v1.0 Category: File Encyptor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY 3

int main() {
  char filename[100];
  printf("Enter filename to encrypt: ");
  scanf("%s", filename);

  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error opening file %s\n", filename);
    exit(1);
  }

  char outputFilename[100];
  sprintf(outputFilename, "%s.encrypted", filename);
  FILE *encryptedFile = fopen(outputFilename, "w");

  int ch;
  while ((ch = fgetc(file)) != EOF) {
    ch += KEY;
    fputc(ch, encryptedFile);
  }

  fclose(encryptedFile);
  fclose(file);

  printf("File %s encrypted successfully!\n", filename);
  printf("Encrypted file saved as %s\n", outputFilename);

  return 0;
}