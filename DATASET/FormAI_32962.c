//FormAI DATASET v1.0 Category: File Encyptor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256
#define ENCRYPTION_KEY 13 // the encryption key

int main()
{
  char inputFileName[MAX_FILENAME_LENGTH];
  char outputFileName[MAX_FILENAME_LENGTH];
  char buffer;
  FILE* inputFileHandle;
  FILE* outputFileHandle;

  printf("Please enter the name of the file to be encrypted: ");
  fgets(inputFileName, MAX_FILENAME_LENGTH, stdin);
  inputFileName[strcspn(inputFileName, "\n")] = 0; // remove newline character from input

  inputFileHandle = fopen(inputFileName, "rb");
  if (inputFileHandle == NULL)
  {
    printf("Error: Unable to open input file \"%s\".\n", inputFileName);
    return 1; // non-zero return code indicates error
  }

  // construct output file name by adding ".enc" extension
  strcpy(outputFileName, inputFileName);
  strcat(outputFileName, ".enc");

  outputFileHandle = fopen(outputFileName, "wb");
  if (outputFileHandle == NULL)
  {
    printf("Error: Unable to open output file \"%s\".\n", outputFileName);
    fclose(inputFileHandle);
    return 1; // non-zero return code indicates error
  }

  // read input file one byte at a time and write encrypted byte to output file
  while (fread(&buffer, 1, 1, inputFileHandle) == 1)
  {
    buffer = (buffer + ENCRYPTION_KEY) % 256;
    fwrite(&buffer, 1, 1, outputFileHandle);
  }

  fclose(inputFileHandle);
  fclose(outputFileHandle);

  printf("Encryption of file \"%s\" finished. Encrypted data stored in file \"%s\".\n", inputFileName, outputFileName);

  return 0; // zero return code indicates success
}