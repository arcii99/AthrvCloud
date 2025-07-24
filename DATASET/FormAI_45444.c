//FormAI DATASET v1.0 Category: File handling ; Style: all-encompassing
#include <stdio.h>

int main() {
  FILE *fp;
  char buffer[100];
  
  // Create a new file called "example.txt" for writing
  fp = fopen("example.txt", "w");
  
  // Check if file was successfully opened
  if (fp == NULL) {
    printf("Error: Unable to open file.\n");
    return 1;
  }
  
  // Write some text to the file
  fprintf(fp, "This is an example file.\n");
  fprintf(fp, "It is used to demonstrate file handling in C.\n");
  
  // Close the file
  fclose(fp);
  
  // Open the file "example.txt" for reading
  fp = fopen("example.txt", "r");
  
  // Check if file was successfully opened
  if (fp == NULL) {
    printf("Error: Unable to open file.\n");
    return 1;
  }
  
  // Read the contents of the file into a buffer
  while (fgets(buffer, 100, fp) != NULL) {
    printf("%s", buffer);
  }
  
  // Close the file
  fclose(fp);
  
  return 0;
}