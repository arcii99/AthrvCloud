//FormAI DATASET v1.0 Category: Error handling ; Style: lively
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Welcome to the C Error Handling Program!\n");
  printf("We will simulate an error in reading a file...\n");

  FILE *file;
  file = fopen("non_existing_file.txt", "r");

  if (file == NULL) {
    printf("Error in opening the file. Let's print the error message!\n");

    perror("Error message: ");
    exit(1);
  }

  printf("File opened successfully!\n");
  printf("Let's read the contents of the file...\n");

  char buffer[100];
  int read = fread(buffer, sizeof(char), 100, file);

  if (read == 0) {
    printf("Error in reading from file. Let's print the error message!\n");

    perror("Error message: ");
    exit(1);
  }

  fclose(file);

  printf("File read successfully!\n");
  printf("Contents of the file:\n%s", buffer);

  return 0;
}