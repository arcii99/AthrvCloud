//FormAI DATASET v1.0 Category: File handling ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

int main() {
  char filename[MAX_LENGTH];
  FILE *fp;
  char data[MAX_LENGTH];

  printf("Enter file name: ");
  scanf("%s", filename);

  // Create a new file
  fp = fopen(filename, "w");
  if (fp == NULL) {
    printf("Error opening file for writing");
    return 1;
  }

  printf("\nEnter data (press Ctrl+Z to stop):\n");

  // Read data from user input and write to file
  while (fgets(data, MAX_LENGTH, stdin) != NULL) {
    fprintf(fp, "%s", data);
  }

  fclose(fp);

  // Open file again for reading
  fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Error opening file for reading");
    return 1;
  }

  printf("\nThe content of the file is:\n");

  // Read content of file and print to console
  while (fgets(data, MAX_LENGTH, fp) != NULL) {
    printf("%s", data);
  }

  fclose(fp);
  return 0;
}