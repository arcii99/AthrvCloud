//FormAI DATASET v1.0 Category: Log analysis ; Style: random
#include <stdio.h>

int main() {
  FILE *fp;
  char ch;
  int count = 0, lineCount = 1;

  // open log file for reading
  fp = fopen("app.log", "r");

  // handle error opening file
  if (fp == NULL) {
    printf("Error opening file\n");
    return 0;
  }

  // read file character by character
  while ((ch = fgetc(fp)) != EOF) {
    count++;

    // count number of lines
    if (ch == '\n') {
      lineCount++;
    }

    // look for error message
    if (ch == 'E') {
      char errorMsg[100];
      int i = 0;

      // read in error message
      while ((ch = fgetc(fp)) != '\n') {
        errorMsg[i++] = ch;
      }

      errorMsg[i] = '\0';

      // print error message and line number
      printf("Error: %s at line %d\n", errorMsg, lineCount);
    }
  }

  // print total characters and lines read
  printf("Total characters read: %d\n", count);
  printf("Total lines: %d\n", lineCount);

  // close file
  fclose(fp);

  return 0;
}