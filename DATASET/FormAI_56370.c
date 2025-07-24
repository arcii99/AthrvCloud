//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: modular
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LOG_LINES 1000 // Maximum number of log lines
#define MAX_LOG_LENGTH 100 // Maximum length of each log message
#define MAX_SYSTEMS 10 // Maximum number of systems to monitor

char monitoredSystems[MAX_SYSTEMS][MAX_LOG_LENGTH] = {"System1", "System2", "System3", "System4", "System5"}; // The systems to be monitored
char log[MAX_LOG_LINES][MAX_LOG_LENGTH]; // Array to store the log messages
int currentLogLine = 0; // The current position in the log array
int systemCount = sizeof(monitoredSystems)/sizeof(monitoredSystems[0]); // The number of systems to monitor

void logMessage(char *message) {
  if(currentLogLine >= MAX_LOG_LINES) {
    // If we've reached the maximum number of log lines, start from the beginning
    currentLogLine = 0;
  }
  // Copy the message into the log array
  strncpy(log[currentLogLine], message, MAX_LOG_LENGTH);
  currentLogLine++;
}

int isSystemMonitored(char *system) {
  for(int i = 0; i < systemCount; i++) {
    if(strcmp(monitoredSystems[i], system) == 0) {
      // If the system is in our list, return true
      return 1;
    }
  }
  // If the system isn't in our list, return false
  return 0;
}

int main() {
  char message[MAX_LOG_LENGTH];
  while(1) {
    fgets(message, MAX_LOG_LENGTH, stdin); // Read input from stdin
    message[strcspn(message, "\n")] = 0; // Remove newline character
    if(isSystemMonitored(message)) {
      // If the message is from a monitored system, log it
      logMessage(message);
    }
  }
  return 0;
}