//FormAI DATASET v1.0 Category: File handling ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fptr;
  char filename[100];
  char ch;

  printf("Enter the filename to open for reading: ");
  scanf("%s", filename);

  // Opening the file in read mode
  fptr = fopen(filename, "r");

  // Checking if the file exists or not
  if (fptr == NULL) {
    printf("Unable to open the file!");
    exit(EXIT_FAILURE);
  }

  printf("The contents of %s file are:\n", filename);

  // Reading the contents of the file character by character
  while ((ch = fgetc(fptr)) != EOF) {
      printf("%c", ch);
  }

  fclose(fptr);
  return 0;
}