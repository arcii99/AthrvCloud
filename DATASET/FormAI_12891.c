//FormAI DATASET v1.0 Category: System event logger ; Style: grateful
#include <stdio.h>
#include <stdbool.h>

int main() {
  // Initialize the event logger
  char* eventLogFile = "event_logs.txt";
  FILE* eventLog = fopen(eventLogFile, "a");

  /* Check if opening the file was successful */
  if (eventLog == NULL) {
    printf("Error opening event log file.\n");
    return 1;
  } else {
    printf("Event logger started successfully.\n");
  }

  /* Record events */
  bool isSystemOn = true;
  int systemLoad = 70;

  fprintf(eventLog, "[INFO] System booted up successfully.\n");
  fprintf(eventLog, "[INFO] Current system load: %d.\n", systemLoad);

  // Time passes
  systemLoad = 90;
  fprintf(eventLog, "[WARNING] System load has increased to %d percent.\n", systemLoad);

  // User performs an action
  char* action = "addUser";

  fprintf(eventLog, "[INFO] User performed action: %s.\n", action);

  // An error occurs
  int errorCode = 500;

  fprintf(eventLog, "[ERROR] An error has occurred. Error code: %d.\n", errorCode);

  // Close the event logger
  fclose(eventLog);

  return 0;
}