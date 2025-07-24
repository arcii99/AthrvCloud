//FormAI DATASET v1.0 Category: File handling ; Style: relaxed
#include <stdio.h>

int main() {
  FILE *file;
  char text[100];

  // Open the file for writing
  file = fopen("example.txt", "w");

  // Check if the file was opened successfully
  if (file == NULL) {
    printf("Error opening file\n");
    return 1;
  }

  // Write some text to the file
  fprintf(file, "This is an example text that we will write to a file using C file handling.\n");

  // Close the file
  fclose(file);

  // Open the file for reading
  file = fopen("example.txt", "r");

  // Check if the file was opened successfully
  if (file == NULL) {
    printf("Error opening file\n");
    return 1;
  }

  // Read the text from the file
  printf("The contents of the file are:\n");
  while (fgets(text, 100, file) != NULL) {
    printf("%s", text);
  }

  // Close the file
  fclose(file);

  return 0;
}