//FormAI DATASET v1.0 Category: File handling ; Style: random
#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *file_pointer;
  char file_name[50], ch, data[100];

  printf("Enter the file name: ");
  scanf("%s", file_name);

  // Open a file in write mode
  file_pointer = fopen(file_name, "w");

  if (file_pointer == NULL) {
    printf("Error opening file!");
    exit(1);
  }

  printf("\nEnter data to write into the file:\n");
  while (fgets(data, sizeof(data), stdin) != NULL) {
    fputs(data, file_pointer);
  }

  // Close the file
  fclose(file_pointer);

  printf("\nFile created and saved successfully!\n");

  // Open the same file in read-only mode
  file_pointer = fopen(file_name, "r");

  if (file_pointer == NULL) {
    printf("Error opening the file!\n");
    exit(1);
  }

  printf("\nReading data from the file:\n");

  while ((ch = fgetc(file_pointer)) != EOF) {
    printf("%c", ch);
  }

  // Close the file
  fclose(file_pointer);

  printf("\nFile read successfully!\n");

  return 0;
}