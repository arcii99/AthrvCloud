//FormAI DATASET v1.0 Category: System event logger ; Style: energetic
#include <stdio.h>
#include <time.h>

void logEvent(const char* event) {
  FILE* logFile = fopen("system_events.log", "a");

  if (logFile == NULL) {
    printf("Error opening log file.\n");
    return;
  }

  time_t rawTime;
  struct tm* timeInfo;

  time(&rawTime);
  timeInfo = localtime(&rawTime);

  fprintf(logFile, "[%d-%02d-%02d %02d:%02d:%02d] %s\n",
    timeInfo->tm_year + 1900, timeInfo->tm_mon + 1, timeInfo->tm_mday,
    timeInfo->tm_hour, timeInfo->tm_min, timeInfo->tm_sec,
    event);

  fclose(logFile);

  printf("Event logged: %s\n", event);
}

int main() {
  printf("Logging system events in real-time...\n");

  while (1) {
    // Here, you can put your own event detection logic
    // For example, detecting file creation, network errors, etc.
    // When an event is detected, log it using the logEvent function

    logEvent("Network error: Connection timed out");

    logEvent("File created: file.txt");

    // Wait for 5 seconds before logging the next event
    sleep(5);
  }

  return 0;
}