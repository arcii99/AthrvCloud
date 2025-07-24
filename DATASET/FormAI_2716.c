//FormAI DATASET v1.0 Category: Log analysis ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_LENGTH 1024

int main(int argc, char const *argv[]) {
  FILE *logFile;
  char logEntry[MAX_LOG_LENGTH];
  char logLevel[MAX_LOG_LENGTH];
  char logMessage[MAX_LOG_LENGTH];
  int lineCount = 0, errorCount = 0, warningCount = 0;

  logFile = fopen("example.log", "r");

  if (logFile == NULL) {
    perror("Error: could not open log file");
    exit(EXIT_FAILURE);
  }

  while (fgets(logEntry, MAX_LOG_LENGTH, logFile) != NULL) {
    lineCount++;

    int i = 0;
    while (logEntry[i] != ']') {
      logLevel[i] = logEntry[i];
      i++;
    }
    logLevel[i] = '\0';

    int messageStart = i+2;
    int j = messageStart;
    while (logEntry[j] != '\n') {
      logMessage[j-messageStart] = logEntry[j];
      j++;
    }
    logMessage[j-messageStart] = '\0';

    // Count the errors and warnings
    if (strcmp(logLevel, "ERROR") == 0) {
      errorCount++;
      printf("Error on line %d: %s\n", lineCount, logMessage);
    } else if (strcmp(logLevel, "WARNING") == 0) {
      warningCount++;
      printf("Warning on line %d: %s\n", lineCount, logMessage);
    }
  }

  printf("Finished analyzing log file.\n");
  printf("Total lines processed: %d\n", lineCount);
  printf("Total errors found: %d\n", errorCount);
  printf("Total warnings found: %d\n", warningCount);

  return 0;
}