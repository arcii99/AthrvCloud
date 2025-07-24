//FormAI DATASET v1.0 Category: File handling ; Style: active
#include <stdio.h>

int main() {
  // creating an instance of the file structure
  FILE *file_pointer;

  // opening a file for writing
  file_pointer = fopen("example.txt", "w");

  // checking if the file was successfully opened
  if (file_pointer == NULL) {
    printf("Error: File could not be opened.");
    return 0;
  }

  // writing data to the file
  fprintf(file_pointer, "This is an example of file handling in C!\n");
  fprintf(file_pointer, "We can write anything we want to the file!\n");
  fprintf(file_pointer, "We can even include variables like %s!\n", "strings");

  // closing the file
  fclose(file_pointer);

  // opening the file for reading
  file_pointer = fopen("example.txt", "r");

  // checking if the file was successfully opened
  if (file_pointer == NULL) {
    printf("Error: File could not be opened.");
    return 0;
  }

  // reading data from the file and printing it to the console
  char file_character = getc(file_pointer);
  while (file_character != EOF) {
    printf("%c", file_character);
    file_character = getc(file_pointer);
  }

  // closing the file
  fclose(file_pointer);

  return 0;
}