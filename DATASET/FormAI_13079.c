//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
* This program is a metadata extractor for C source code files.
* It extracts comments and function signatures from the source file.
* The output is written to the console.
*/

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return 1;
  }

  FILE *file = fopen(argv[1], "r");

  if (file == NULL) {
    printf("Error opening file %s\n", argv[1]);
    return 1;
  }

  char line[256];
  char comment[512] = "";
  char signature[256] = "";
  int comment_flag = 0;
  int signature_flag = 0;
  int round_brackets_count = 0;

  while (fgets(line, sizeof(line), file) != NULL) {
    // Extract comments
    if (strstr(line, "/*")) {
      comment_flag = 1;
    }

    if (comment_flag == 1) {
      strncat(comment, line, sizeof(line));
      if (strstr(line, "*/")) {
        comment_flag = 0;
        printf("%s\n", comment);
        memset(comment, '\0', sizeof(comment));
      }
    }

    // Extract function signatures
    if (strstr(line, "(")) {
      signature_flag = 1;
      if (round_brackets_count == 0) {
        strcpy(signature, "");
      }
      round_brackets_count++;
    }

    if (signature_flag == 1) {
      strncat(signature, line, sizeof(line));
      if (strstr(line, ")")) {
        round_brackets_count--;
        if (round_brackets_count == 0) {
          signature_flag = 0;
          printf("%s\n", signature);
        }
      }
    }
  }

  fclose(file);
  return 0;
}