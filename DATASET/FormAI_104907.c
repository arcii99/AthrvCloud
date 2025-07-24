//FormAI DATASET v1.0 Category: File handling ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fp;
  char ch;

  // open file
  fp = fopen("example.txt", "w");

  // check for errors while opening the file
  if (fp == NULL) {
    printf("Error opening file!\n");
    exit(1);
  }

  // write to file
  printf("Enter the text to be written to the file: ");
  while ((ch = getchar()) != EOF) {
    fputc(ch, fp);
  }

  // close file
  fclose(fp);

  // open file in read mode
  fp = fopen("example.txt", "r");

  // check for errors while opening the file
  if (fp == NULL) {
    printf("Error opening file!\n");
    exit(1);
  }

  // read and print contents of the file
  printf("\nContents of the file:\n");
  while ((ch = fgetc(fp)) != EOF) {
    printf("%c", ch);
  }

  // close file
  fclose(fp);

  return 0;
}