//FormAI DATASET v1.0 Category: File handling ; Style: expert-level
#include <stdio.h>

int main() {
  // Declare file pointer
  FILE *fp; 
  // Open file for writing
  fp = fopen("example.txt", "w");
  // Check if file opened successfully
  if (fp == NULL) {
    printf("Error opening file.\n");
    return 1;
  }
  // Write to file
  fprintf(fp, "This is an example file.\n");
  // Close file
  fclose(fp);

  // Open file for reading
  fp = fopen("example.txt", "r");
  // Check if file opened successfully
  if (fp == NULL) {
    printf("Error opening file.\n");
    return 1;
  }
  // Read from file and print to console
  char c;
  while ((c = fgetc(fp)) != EOF) {
    printf("%c", c);
  }
  // Close file
  fclose(fp);

  return 0;
}