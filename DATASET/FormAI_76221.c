//FormAI DATASET v1.0 Category: File handling ; Style: funny
// Welcome to the funniest File handling C program ever!
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  // Initializing some variables with funny names.
  int fileCount = 42;
  char fileName[15] = "funny.txt";
  float fileSize = 3.14159;
  char joke[150] = "Why did the programmer quit his job? He didn't get arrays!";

  // Opening the file
  FILE *filePointer = fopen(fileName, "w");

  // Checking if file is open or not
  if (filePointer == NULL) {
    printf("Error! Could not open file.\n");
    exit(1);
  }
  
  // Writing some funny stuff to the file
  fprintf(filePointer, "Number of files: %d\n", fileCount);
  fprintf(filePointer, "Size of %s: %.2fGB\n", fileName, fileSize);
  fprintf(filePointer, "A programming joke: %s\n", joke);

  // Closing the file
  fclose(filePointer);

  // Reading from the file
  filePointer = fopen(fileName, "r");

  // Checking if file is open or not
  if (filePointer == NULL) {
    printf("Error! Could not open file.\n");
    exit(1);
  }

  // Reading and printing the contents of the file
  char buffer[255];
  while (fgets(buffer, 255, filePointer)) {
    printf("%s", buffer);
  }

  // Closing the file once again
  fclose(filePointer);

  printf("That's all folks! Hope you had a good laugh.\n");

  return 0;
}