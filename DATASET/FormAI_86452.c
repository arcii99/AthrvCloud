//FormAI DATASET v1.0 Category: Log analysis ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *time;
    char *log;
} Log;

int main() {
  // simulate logs
  char *logs[] = {
      "2022-01-01 12:30:00 INFO: User logged in successfully.",
      "2022-01-01 12:31:00 ERROR: Could not connect to database.",
      "2022-01-01 12:32:00 WARNING: System running low on disk space.",
      "2022-01-01 12:33:00 INFO: Received request to logout user.",
      "2022-01-01 12:34:00 DEBUG: Request took 3ms to process.",
      "2022-01-01 12:35:00 WARNING: CPU temperature reaching maximum threshold.",
      "2022-01-01 12:36:00 ERROR: Unable to complete backup.",
      "2022-01-01 12:37:00 INFO: All user sessions have been terminated.",
      "2022-01-01 12:38:00 DEBUG: Cleaning up temporary files...",
      "2022-01-01 12:39:00 WARNING: A security vulnerability has been detected!"
  };

  const int LOG_COUNT = sizeof(logs) / sizeof(logs[0]);

  // create array of Log objects
  Log *logArray = (Log *)malloc(LOG_COUNT * sizeof(Log));

  // loop through logs and separate time and log message using strtok
  for (int i = 0; i < LOG_COUNT; i++) {
      char *time = strtok(logs[i], " ");
      char *level = strtok(NULL, " ");
      char *log = strtok(NULL, "");

      // allocate memory for new log object
      Log newLog;
      newLog.time = (char *)malloc(strlen(time) + 1);
      newLog.log = (char *)malloc(strlen(log) + 1);

      // copy time and log message to newLog
      strcpy(newLog.time, time);
      strcpy(newLog.log, log);

      // add newLog to logArray
      logArray[i] = newLog;
  }

  // print all logs with ERROR level
  printf("##############################\n");
  printf("# Logs with ERROR level only #\n");
  printf("##############################\n");
  for (int i = 0; i < LOG_COUNT; i++) {
      if (strstr(logArray[i].log, "ERROR")) {
          printf("%s %s\n", logArray[i].time, logArray[i].log);
      }
  }

  // free memory allocated for logArray
  for (int i = 0; i < LOG_COUNT; i++) {
      free(logArray[i].time);
      free(logArray[i].log);
  }
  free(logArray);

  return 0;
}