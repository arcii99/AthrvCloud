//FormAI DATASET v1.0 Category: Log analysis ; Style: artistic
#include <stdio.h>
#include <string.h>

#define MAX_LOGS 1000
#define MAX_LINE_LENGTH 100

int main() {
  FILE *log_file;
  char log_line[MAX_LINE_LENGTH];
  int log_count = 0;

  int info_count = 0;
  int warning_count = 0;
  int error_count = 0;

  log_file = fopen("example.log", "r");

  if (log_file == NULL) {
    printf("Error reading log file.");
  } else {
    while (fgets(log_line, MAX_LINE_LENGTH, log_file) != NULL) {
      log_count++;

      if (strstr(log_line, "INFO") != NULL) {
        info_count++;
        printf("Information #%d: %s", info_count, log_line);
      } else if (strstr(log_line, "WARNING") != NULL) {
        warning_count++;
        printf("Warning #%d: %s", warning_count, log_line);
      } else if (strstr(log_line, "ERROR") != NULL) {
        error_count++;
        printf("Error #%d: %s", error_count, log_line);
      }
    }

    printf("\nTotal number of logs: %d\n", log_count);
    printf("Number of information logs: %d\n", info_count);
    printf("Number of warning logs: %d\n", warning_count);
    printf("Number of error logs: %d\n", error_count);
  }

  fclose(log_file);
  return 0;
}