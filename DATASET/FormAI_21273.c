//FormAI DATASET v1.0 Category: Error handling ; Style: content
/* This is a unique C program that demonstrates error handling in file I/O operations. The program attempts to open a file and read its contents. If the file does not exist, it will create a new one and write some data to it.*/

#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fp;
  char data[100];

  // Attempt to open the file
  fp = fopen("example.txt", "r");

  // If the file does not exist, create a new one and write data to it
  if (fp == NULL) {
    printf("File does not exist. Creating new file...\n");
    fp = fopen("example.txt", "w");
    fprintf(fp, "This is the data written to the file.\n");
    fclose(fp);
    
    // Reopen the file in read mode
    fp = fopen("example.txt", "r");
  }

  // Read the contents of the file
  printf("Reading from file:\n");
  while (fgets(data, 100, fp) != NULL) {
    printf("%s", data);
  }

  // Close the file
  fclose(fp);

  return 0;
}