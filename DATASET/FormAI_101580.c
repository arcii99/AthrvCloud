//FormAI DATASET v1.0 Category: Log analysis ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This program reads through a C log file and extracts specific information from it. 

int main(int argc, char* argv[]) {

  FILE* filePointer;
  char* line = NULL;
  size_t length = 0;
  ssize_t read;

  // Check for file existence and open it.
  filePointer = fopen("logfile.txt", "r");

  if (filePointer == NULL) {
    printf("Log file not found!\n");
    exit(EXIT_FAILURE);
  }

  int errorCount = 0;
  int successCount = 0;
  int warningCount = 0;

  // Loop through each line in the file.
  while ((read = getline(&line, &length, filePointer)) != -1) {
    if (strstr(line, "ERROR") != NULL) {
      errorCount++;
    } else if (strstr(line, "SUCCESS") != NULL) {
      successCount++;
    } else if (strstr(line, "WARNING") != NULL) {
      warningCount++;
    }
  }

  printf("There were %d errors, %d successes, and %d warnings in the log file.\n", errorCount, successCount, warningCount);

  // Close the file.
  fclose(filePointer);

  if (line) {
    free(line);
  }

  return 0;
}