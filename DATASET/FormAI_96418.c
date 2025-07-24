//FormAI DATASET v1.0 Category: File handling ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fp;
  char filename[] = "example.txt";
  int count = 0, words = 0, lines = 0;
  char ch;

  // Opening file in read mode
  fp = fopen(filename, "r");

  // Checking if file exists
  if (fp == NULL) {
    printf("Error opening file \"%s\"!\n", filename);
    exit(1);
  }

  // Looping through each character in the file
  while ((ch = fgetc(fp)) != EOF) {
    count++;

    // If current character is space or newline, it is a new word
    if (ch == ' ' || ch == '\n') {
      words++;
    }

    // If current character is newline, it is a new line
    if (ch == '\n') {
      lines++;
    }
  }

  // Closing file
  fclose(fp);

  // Printing statistics
  printf("File \"%s\" contains:\n", filename);
  printf("%d characters, %d words, and %d lines.\n", count, words, lines);

  return 0;
}