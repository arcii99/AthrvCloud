//FormAI DATASET v1.0 Category: Log analysis ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char log[1000];
  int total_lines = 0, error_count = 0;

  FILE *fp;
  fp = fopen("example.log", "r");
  if (fp == NULL) {
    printf("Error opening file");
    exit(1);
  }

  while (fgets(log, 1000, fp) != NULL) {
    total_lines++;
    if (strstr(log, "error")) {
      error_count++;
    }
  }

  printf("Total lines in log file: %d\n", total_lines);
  printf("Total errors in log file: %d\n", error_count);

  fclose(fp);
  return 0;
}