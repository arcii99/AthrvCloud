//FormAI DATASET v1.0 Category: System event logger ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void logEvent(char *eventName, char *eventType) {
  time_t rawtime;
  struct tm *timeinfo;
  time(&rawtime);
  timeinfo = localtime(&rawtime);

  // Open the log file in append mode
  FILE *fp = fopen("event.log", "a");
  if (fp == NULL) {
    printf("Error opening file\n");
    exit(1);
  }

  // Format the timestamp
  char timestamp[20];
  strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", timeinfo);

  // Write event details to the log file
  fprintf(fp, "%s [%s] %s\n", timestamp, eventType, eventName);
  
  // Close the log file
  fclose(fp);
}

int main() {
  printf("Logging system events...\n");

  // Log application started event
  logEvent("Application started", "INFO");

  // Simulate some events
  logEvent("Critical error occurred", "ERROR");
  logEvent("User login succeeded", "INFO");
  logEvent("User account created", "INFO");
  logEvent("Warning: Disk space running low", "WARN");
  logEvent("User account deleted", "INFO");

  // Log application shutdown event
  logEvent("Application shutting down", "INFO");

  return 0;
}