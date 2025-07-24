//FormAI DATASET v1.0 Category: File handling ; Style: synchronous
#include <stdio.h>

int main() {
  // Declare file pointer and buffer
  FILE *fp;
  char buffer[255];

  // Open file for reading
  fp = fopen("text.txt", "r");

  // Check if file opened successfully
  if (fp == NULL) {
    printf("Error opening file!\n");
    return 1;
  }

  // Read file line by line and print it
  while (fgets(buffer, 255, fp) != NULL) {
    printf("%s", buffer);
  }

  // Close file
  fclose(fp);

  // Open file for writing
  fp = fopen("text.txt", "w");

  // Check if file opened successfully
  if(fp == NULL) {
    printf("Error opening file for writing!\n");
    return 1;
  }

  // Write string to file
  fprintf(fp, "This is a test string.\n");

  // Close file
  fclose(fp);

  return 0;
}