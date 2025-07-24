//FormAI DATASET v1.0 Category: Error handling ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main() {
  FILE *fp;

  // Attempt to open a non-existent file
  fp = fopen("nonexistentfile.txt", "r");

  // Check for errors
  if (fp == NULL) {
    // Print error message
    printf("Error opening file: %s\n", strerror(errno));
    
    // Try creating the file instead
    fp = fopen("nonexistentfile.txt", "w");
    
    // Check again for errors
    if (fp == NULL) {
      // Print a different error message
      printf("Error creating file: %s\n", strerror(errno));
      
      // Exit the program with a non-zero return value
      exit(EXIT_FAILURE);
    }
  }

  // File operations here...

  // Close the file
  fclose(fp);

  return 0;
}