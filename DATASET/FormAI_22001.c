//FormAI DATASET v1.0 Category: File handling ; Style: energetic
#include <stdio.h>

int main() {
  printf("Welcome to the File Handling Program!\n");

  // Creating a file with write mode and writing some content
  FILE *fptr;
  fptr = fopen("sample.txt", "w");
  fprintf(fptr, "This is some random text that we are writing to our file.\n");
  fclose(fptr);

  // Opening the same file to read the content
  fptr = fopen("sample.txt", "r");
  if (fptr == NULL) {
    printf("Error opening file\n");
    return 1;
  }

  // Reading and printing the content
  printf("Content in the file:\n");
  char c = fgetc(fptr);
  while (c != EOF) {
    printf("%c", c);
    c = fgetc(fptr);
  }

  // Closing the file
  fclose(fptr);

  printf("\nDone with the File Handling Program!\n");
  return 0;
}