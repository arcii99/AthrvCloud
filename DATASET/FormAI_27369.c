//FormAI DATASET v1.0 Category: Error handling ; Style: content
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[]) {
  FILE *file_ptr;

  // Check if a file was passed as an argument
  if (argc < 2) {
    printf("Error: Please provide a filename as an argument.\n");
    return 1;
  }

  // Try to open the file
  file_ptr = fopen(argv[1], "r");
  if (file_ptr == NULL) {
    // Print a helpful message based on the error code
    switch(errno) {
      case ENOENT:
        printf("Error: The file '%s' does not exist.\n", argv[1]);
        break;
      case EACCES:
        printf("Error: Access to the file '%s' was denied.\n", argv[1]);
        break;
      default:
        printf("Error: Failed to open the file '%s'.\n", argv[1]);
        break;
    }
    return 1;
  }

  // Do some other stuff with the file here...

  // Close the file when we're done
  if (fclose(file_ptr) != 0) {
    // Print an error message if the file couldn't be closed
    printf("Warning: Failed to close the file.\n");
  }

  return 0;
}