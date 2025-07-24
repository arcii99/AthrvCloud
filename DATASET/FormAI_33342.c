//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COLUMNS 10

int main(int argc, char *argv[]) {
  FILE *fp;
  char line[MAX_LINE_LENGTH];
  char *token;
  char *columns[MAX_COLUMNS];
  int num_columns = 0;

  if (argc != 2) {
    printf("Usage: %s <filename.csv>\n", argv[0]);
    return 1;
  }

  fp = fopen(argv[1], "r");
  if (fp == NULL) {
    printf("Error opening file: %s\n", argv[1]);
    return 1;
  }

  // Read the header line and split it into columns
  fgets(line, MAX_LINE_LENGTH, fp);
  token = strtok(line, ",");
  while (token != NULL) {
    columns[num_columns++] = token;
    token = strtok(NULL, ",");
  }

  // Process the rest of the file
  while (fgets(line, MAX_LINE_LENGTH, fp)) {
    int i;
    token = strtok(line, ",");
    for (i = 0; i < num_columns && token != NULL; i++) {
      printf("%s: %s\n", columns[i], token);
      token = strtok(NULL, ",");
    }
    printf("\n");
  }

  fclose(fp);
  return 0;
}