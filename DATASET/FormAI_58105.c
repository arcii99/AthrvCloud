//FormAI DATASET v1.0 Category: System event logger ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void log_event(char* message) {
  FILE *fp;
  time_t rawtime;
  struct tm * timeinfo;
  char buffer[80];

  // get current time
  time (&rawtime);
  timeinfo = localtime(&rawtime);

  // format time string
  strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);

  // open log file
  fp = fopen("event.log", "a");
  if (fp == NULL) {
    printf("Error opening log file.");
    return;
  }

  // write log message
  fprintf(fp, "[%s] %s\n", buffer, message);

  // close log file
  fclose(fp);
}

int main() {
  // log some events
  log_event("System started.");
  log_event("User logged in.");
  log_event("File saved successfully.");

  return 0;
}