//FormAI DATASET v1.0 Category: Log analysis ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *logfile;
  char line[256];
  int success = 0, error = 0;
  
  // Open the log file
  logfile = fopen("example.log", "r");
  if (logfile == NULL) {
    printf("Error: Failed to open log file\n");
    return 1;
  }

  // Read the file line by line
  while (fgets(line, sizeof(line), logfile)) {
    if (strstr(line, "Success")) {
      success++;
    } else if (strstr(line, "Error")) {
      error++;
    }
  }

  // Close the log file
  fclose(logfile);

  // Print the results
  printf("Log analysis complete. \nSuccesses: %d \nErrors: %d\n", success, error);

  return 0;
}