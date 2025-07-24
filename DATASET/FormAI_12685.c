//FormAI DATASET v1.0 Category: System event logger ; Style: inquisitive
#include <stdio.h>
#include <time.h>

void log_event(char *event) {
  time_t current_time;
  char* c_time_string;

  current_time = time(NULL);
  c_time_string = ctime(&current_time);

  // Open the log file for appending
  FILE *log_file = fopen("system_events.log", "a");

  if (log_file != NULL) {
    // Write the event and timestamp to the log file
    fprintf(log_file, "[%s]: %s\n", c_time_string, event);

    // Close the log file
    fclose(log_file);
  } else {
    printf("Error: Failed to open log file\n");
  }
}

int main() {
  printf("=== System Event Logger ===\n");

  // Log some events
  log_event("System started up");
  log_event("User logged in");
  log_event("File saved");

  printf("Done logging events\n");

  return 0;
}