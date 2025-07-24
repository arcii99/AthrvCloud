//FormAI DATASET v1.0 Category: File handling ; Style: random
#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *filePointer;

  char fileContent[1000];

  filePointer = fopen("example.txt", "r");

  if (filePointer == NULL) {
    printf("Error opening the file.\n");
	exit(EXIT_FAILURE);
  }

  printf("Printing the file contents:\n");

  while (fgets(fileContent, 1000, filePointer)) {
    printf("%s", fileContent);
  }

  fclose(filePointer);

  filePointer = fopen("example.txt", "a");

  if (filePointer == NULL) {
    printf("Error opening the file.\n");
    exit(EXIT_FAILURE);
  }

  printf("Enter the text to be added to the file: ");
  fgets(fileContent, 1000, stdin);

  fputs(fileContent, filePointer);

  fclose(filePointer);

  return 0;
}