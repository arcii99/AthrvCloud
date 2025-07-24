//FormAI DATASET v1.0 Category: System event logger ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  FILE *logFile = fopen("systemEvents.log", "a"); // opens log file in append mode
  if (logFile == NULL) {
    printf("Error opening log file\n");
    exit(1);
  }

  time_t rawTime;
  time(&rawTime);
  struct tm *timeInfo = localtime(&rawTime); // gets current time in local time zone
  char timeString[20];
  strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", timeInfo); // formats time string

  fprintf(logFile, "[%s] SYSTEM EVENT: User logged in\n", timeString);
  fflush(logFile); // flushes any buffered data to the file

  // code block for user logout event
  time(&rawTime);
  timeInfo = localtime(&rawTime);
  strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", timeInfo);

  fprintf(logFile, "[%s] SYSTEM EVENT: User logged out\n", timeString);
  fflush(logFile);

  // code block for system shutdown event
  time(&rawTime);
  timeInfo = localtime(&rawTime);
  strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", timeInfo);

  fprintf(logFile, "[%s] SYSTEM EVENT: System shutting down\n", timeString);
  fflush(logFile);

  fclose(logFile); // closes log file
  return 0;
}