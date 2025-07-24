//FormAI DATASET v1.0 Category: System event logger ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void log_event(const char* message) {
  FILE* logfile;
  const char* filename = "event.log";
  time_t now;

  now = time(NULL);

  logfile = fopen(filename, "a");
  if (logfile == NULL) {
    fprintf(stderr, "Error: Cannot open log file '%s'\n", filename);
    return;
  }

  fprintf(logfile, "%s: %s\n", ctime(&now), message);
  fclose(logfile);
}

int main() {
  log_event("Starting program");

  // Some code here...

  log_event("Program has completed successfully");

  return EXIT_SUCCESS;
}