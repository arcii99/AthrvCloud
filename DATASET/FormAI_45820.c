//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024

int main(int argc, char** argv) {
  if (argc < 2) {
    printf("Usage: %s <csv_file>\n", argv[0]);
    exit(1);
  }

  // Open the file for reading
  FILE* fp = fopen(argv[1], "r");
  if (fp == NULL) {
    printf("Error opening file %s.\n", argv[1]);
    exit(1);
  }

  // Read each line of the file
  char line[MAX_LINE_LEN], *token;
  int line_num = 1;
  while (fgets(line, MAX_LINE_LEN, fp) != NULL) {
    // Remove newline character if it exists
    line[strcspn(line, "\n")] = 0;

    // Split the line into tokens
    int token_count = 0;
    char* tokens[100];
    token = strtok(line, ",");
    while (token != NULL) {
      tokens[token_count++] = token;
      token = strtok(NULL, ",");
    }

    // Print out the tokens
    printf("Line %d: ", line_num++);
    for (int i = 0; i < token_count; i++) {
      printf("%s", tokens[i]);
      if (i < token_count - 1) {
        printf(", ");
      }
    }
    printf("\n");
  }

  // Close the file
  fclose(fp);

  return 0;
}