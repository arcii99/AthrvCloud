//FormAI DATASET v1.0 Category: File handling ; Style: automated
#include <stdio.h>

int main() {
  // Pointer to file
  FILE *fp;

  // Open file in write mode
  fp = fopen("file.txt", "w");

  // Check for error in opening file
  if (fp == NULL) {
    printf("Error opening file.");
    return 0;
  }

  // Write data to file
  fprintf(fp, "Hello World!");

  // Close file
  fclose(fp);

  // Open file in read mode
  fp = fopen("file.txt", "r");

  // Check for error in opening file
  if (fp == NULL) {
    printf("Error opening file.");
    return 0;
  }

  // Read data from file
  char data[100];
  fscanf(fp, "%s", data);

  // Print data to console
  printf("%s", data);

  // Close file
  fclose(fp);

  return 0;
}