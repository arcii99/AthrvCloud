//FormAI DATASET v1.0 Category: Syntax parsing ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: ./parser [FILENAME]\n");
    return 1;
  }

  FILE *file = fopen(argv[1], "r");
  if (file == NULL) {
    printf("Error: Failed to open file %s\n", argv[1]);
    return 1;
  }

  char line[256];
  int line_num = 1;

  while (fgets(line, sizeof(line), file)) {
    // remove newline character from line
    char *pos = strchr(line, '\n');
    if (pos != NULL) {
      *pos = '\0';
    }

    char *token = strtok(line, " ");
    while (token != NULL) {
      printf("Line %d: %s\n", line_num, token);
      token = strtok(NULL, " ");
    }

    line_num++;
  }

  fclose(file);
  return 0;
}