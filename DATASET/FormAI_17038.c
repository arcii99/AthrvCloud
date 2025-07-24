//FormAI DATASET v1.0 Category: File handling ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

int main() {
  char filename[100];

  // Get filename from user
  printf("Enter the filename: ");
  scanf("%s", filename);

  // Open file in write mode
  FILE* fp = fopen(filename, "w");

  if (fp == NULL) {
    printf("Error: Unable to open file!\n");
    return 1;
  }

  // Get data from user and write it to file
  printf("Enter data to write to file: ");
  char data[1000];
  fgets(data, 1000, stdin);
  fputs(data, fp);

  // Close file
  fclose(fp);

  // Open file in read mode and print its contents
  fp = fopen(filename, "r");
  
  if (fp == NULL) {
    printf("Error: Unable to open file!\n");
    return 1;
  }

  printf("Contents of %s:\n", filename);
  char ch;
  while ((ch = fgetc(fp)) != EOF) {
    printf("%c", ch);
  }

  // Close file
  fclose(fp);
  
  return 0;
}