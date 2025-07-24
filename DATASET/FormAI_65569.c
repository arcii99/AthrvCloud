//FormAI DATASET v1.0 Category: Data recovery tool ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  printf("Hello and welcome to the C Data Recovery Tool!\n");
  printf("This program allows you to recover lost or corrupted data from C files.\n");
  printf("Let's get started!\n\n");

  // Ask user for input file name and attempt to open it for reading
  char inputFileName[50];
  FILE *inputFile;
  do {
    printf("Please enter the name of the file you wish to recover data from: ");
    scanf("%s", inputFileName);
    inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
      printf("Error opening file. Please check the file name and try again.\n");
    }
  } while (inputFile == NULL);

  // Ask user for output file name and attempt to open it for writing
  char outputFileName[50];
  FILE *outputFile;
  do {
    printf("Please enter the name of the file you wish to write recovered data to: ");
    scanf("%s", outputFileName);
    outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
      printf("Error opening file. Please check the file name and try again.\n");
    }
  } while (outputFile == NULL);

  // Read data from input file one character at a time and write to output file
  char ch;
  while ((ch = fgetc(inputFile)) != EOF) {
    fputc(ch, outputFile);
  }

  // Close input and output files
  fclose(inputFile);
  fclose(outputFile);

  printf("\nData recovery complete! Your file has been successfully recovered and saved to %s.\n", outputFileName);

  return 0;
}