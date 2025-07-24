//FormAI DATASET v1.0 Category: Log analysis ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 200

int main(int argc, char **argv) {
  char *filename;
  char line[MAX_LINE_LENGTH];
  FILE *logfile;
  int line_count = 0;
  int error_count = 0;
  int warning_count = 0;

  // Check for command line argument
  if (argc < 2) {
    printf("Error: no log file specified\n");
    return 1;
  } else {
    filename = argv[1];
  }

  // Open log file
  if ((logfile = fopen(filename, "r")) == NULL) {
    printf("Error: could not open file %s\n", filename);
    return 1;
  }

  // Read each line of log file
  while (fgets(line, MAX_LINE_LENGTH, logfile)) {
    line_count++;

    // Check for error message
    if (strstr(line, "ERROR") != NULL) {
      printf("[%d] ERROR: %s", line_count, line);
      error_count++;
    }

    // Check for warning message
    if (strstr(line, "WARNING") != NULL) {
      printf("[%d] WARNING: %s", line_count, line);
      warning_count++;
    }
  }

  // Print summary
  printf("\n%d lines analyzed\n%d errors found\n%d warnings found\n", line_count, error_count, warning_count);

  // Close log file
  fclose(logfile);

  return 0;
}