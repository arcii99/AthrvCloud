//FormAI DATASET v1.0 Category: System event logger ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void logEvent(char* event) {
  FILE *fp;

  fp = fopen("event.log", "a+");
  if (fp == NULL) {
    printf("Failed to open event log file.\n");
    return;
  }

  time_t now;
  time(&now);

  fprintf(fp, "%s - %s\n", ctime(&now), event);

  fclose(fp);
}

int main() {
  logEvent("Started program.");

  // Do some work
  printf("Working...\n");

  // Simulate an error
  logEvent("Encountered an error.");

  // Handle error
  printf("Error occurred. Handling...\n");

  // Continue working
  printf("Continuing work...\n");

  // Work finished
  logEvent("Finished program.");

  return 0;
}