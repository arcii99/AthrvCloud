//FormAI DATASET v1.0 Category: Log analysis ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

struct LogEntry {
  char timestamp[20];
  char message[MAX_LINE_LENGTH];
};

void printLogEntry(struct LogEntry entry) {
  printf("%s - %s\n", entry.timestamp, entry.message);
}

int main() {
  FILE* logFile = fopen("myLogFile.txt", "r");

  if (logFile == NULL) {
    printf("Failed to open log file.");
    return -1;
  }

  int numEntries = 0;
  char line[MAX_LINE_LENGTH];

  while (fgets(line, sizeof(line), logFile)) {
    numEntries++;
  }

  fclose(logFile);
  logFile = fopen("myLogFile.txt", "r");

  if (logFile == NULL) {
    printf("Failed to open log file.");
    return -1;
  }

  struct LogEntry* entries = (struct LogEntry*) malloc(numEntries * sizeof(struct LogEntry));

  int i = 0;

  while (fgets(line, sizeof(line), logFile)) {
    char* timestamp = strtok(line, ":");
    char* message = strtok(NULL, "");

    if (strlen(timestamp) > 0 && strlen(message) > 0) {
      strcpy(entries[i].timestamp, timestamp);
      strcpy(entries[i].message, message);
      i++;
    }
  }

  fclose(logFile);

  printf("Successfully read %d log entries!\n", numEntries);

  for (i = 0; i < numEntries; i++) {
    printLogEntry(entries[i]);
  }

  return 0;
}