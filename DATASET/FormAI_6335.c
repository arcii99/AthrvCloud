//FormAI DATASET v1.0 Category: Log analysis ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char *log_file = NULL;
  int line_count = 0;
  int error_count = 0;
  int warning_count = 0;
  char line[BUFSIZ];

  if (argc < 2) {
    printf("Usage: %s log_file\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  log_file = argv[1];

  FILE *file = fopen(log_file, "r");
  if (file == NULL) {
    perror("Failed to open file");
    exit(EXIT_FAILURE);
  }

  while (fgets(line, BUFSIZ, file) != NULL) {
    line_count++;

    if (strstr(line, "ERROR") != NULL) {
      error_count++;
    }

    if (strstr(line, "WARNING") != NULL) {
      warning_count++;
    }
  }

  printf("Total lines: %d\n", line_count);
  printf("Errors: %d\n", error_count);
  printf("Warnings: %d\n", warning_count);

  fclose(file);

  return 0;
}