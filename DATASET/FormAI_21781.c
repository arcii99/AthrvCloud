//FormAI DATASET v1.0 Category: System event logger ; Style: relaxed
#include <stdio.h>
#include <time.h>

int main() {
  // Initialize log file
  FILE *logfile;
  logfile = fopen("event.log", "a");

  // Get current time
  time_t now = time(NULL);

  // Write event to log file
  fprintf(logfile, "New event occurred on: %s", ctime(&now));

  // Close log file
  fclose(logfile);

  // Inform user of event logging
  printf("Event has been logged to event.log.\n");

  return 0;
}