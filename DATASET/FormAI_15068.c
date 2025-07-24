//FormAI DATASET v1.0 Category: Error handling ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  FILE *fp;
  char *filename;

  // confirm the filename argument was provided
  if (argc <= 1) {
    printf("Error: Filename argument must be provided\n");
    return 1;
  }

  // get the filename from command-line arguments
  filename = argv[1];

  // open the file
  fp = fopen(filename, "r");

  // confirm the file was successfully opened
  if (fp == NULL) {
    printf("Error: Failed to open file \"%s\"\n", filename);
    return 1;
  }

  // read the file contents into a buffer
  char buffer[1024];
  if (fgets(buffer, 1024, fp) == NULL) {
    printf("Error: Failed to read file \"%s\"\n", filename);
    return 1;
  }

  // close the file
  fclose(fp);

  // confirm the file length is within a certain range
  int buffer_len = strlen(buffer);
  if (buffer_len < 10 || buffer_len > 100) {
    printf("Error: File \"%s\" length must be between 10 and 100 characters\n", filename);
    return 1;
  }

  // print the file contents if it passed all checks
  printf("File contents of \"%s\": %s\n", filename, buffer);

  return 0;
}