//FormAI DATASET v1.0 Category: System event logger ; Style: portable
#include <stdio.h>
#include <time.h>

void logEvent(const char* message) {
  FILE *logFile = fopen("system_log.txt", "a");
  if (logFile != NULL) {
    time_t currentTime = time(NULL);
    struct tm *localTime = localtime(&currentTime);
    fprintf(logFile, "[%02d/%02d/%04d %02d:%02d:%02d] %s\n", localTime->tm_mday, localTime->tm_mon + 1, localTime->tm_year + 1900, localTime->tm_hour, localTime->tm_min, localTime->tm_sec, message); 
    fclose(logFile);
  }
}

int main() {
  char userCommand[100];
  while (1) {
    printf("\nEnter a command to log or type \"exit\" to quit: ");
    fgets(userCommand, 100, stdin);
    if (strncmp(userCommand, "exit", 4) == 0) {
      printf("Exiting...\n");
      break;
    }
    logEvent(userCommand);
    printf("Log event added to system_log.txt\n");
  }
  return 0;
}