//FormAI DATASET v1.0 Category: Log analysis ; Style: genious
#include <stdio.h>
#include <string.h>

int main() {
  FILE *file;
  char line[100], date[20], time[20], log[60];

  // Open log file
  file = fopen("log.txt", "r");

  // Check if file exists
  if (file == NULL) {
    printf("Error: Could not open file.\n");
    return 1;
  }

  // Read through each line
  while (fgets(line, 100, file)) {
    // Extract date, time, and log message using string manipulation
    sscanf(line, "[%s %s] %s", date, time, log);

    // Print line with color-coded log level
    if (strstr(log, "ERROR")) {
      printf("\033[1;31m[%s %s] %s\033[0m\n", date, time, log);
    } else if (strstr(log, "WARNING")) {
      printf("\033[1;33m[%s %s] %s\033[0m\n", date, time, log);
    } else {
      printf("[%s %s] %s\n", date, time, log);
    }
  }

  // Close file
  fclose(file);

  return 0;
}