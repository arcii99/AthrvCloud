//FormAI DATASET v1.0 Category: File handling ; Style: lively
#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *filePointer;
  char fileName[] = "example.txt";
  char buffer[100];

  printf("Welcome to my file handling program!\n");

  // Create a new file
  filePointer = fopen(fileName, "w");

  // Check if file was successfully created
  if (filePointer == NULL) {
    printf("Error creating file.\n");
    exit(1);
  } else {
    printf("File created successfully!\n");
  }

  // Write some text to the file
  fprintf(filePointer, "Hello World!\n");
  fprintf(filePointer, "This is a test file.\n");

  // Close the file
  fclose(filePointer);

  // Open the file for reading
  filePointer = fopen(fileName, "r");

  // Check if file was successfully opened
  if (filePointer == NULL) {
    printf("Error opening file.\n");
    exit(1);
  } else {
    printf("\nFile opened successfully!\n\n");
  }

  // Read the contents of the file
  while (fgets(buffer, sizeof(buffer), filePointer)) {
    printf("%s", buffer);
  }

  // Close the file
  fclose(filePointer);

  printf("\nThanks for using my program!\n");

  return 0;
}