//FormAI DATASET v1.0 Category: System event logger ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define EVENT_LOG_FILE "system_event.log"

void log_event(char *event_type, char *description) {
  FILE *log_file;
  time_t current_time;

  log_file = fopen(EVENT_LOG_FILE, "a");

  if (log_file == NULL) {
    perror("Error opening log file.\n");
    exit(EXIT_FAILURE);
  }

  current_time = time(NULL);

  fprintf(log_file, "[%s] - %s: %s\n", ctime(&current_time), event_type, description);

  fclose(log_file);
}

int main() {
  char *event_type;
  char *description;

  // System start event
  event_type = "system";
  description = "System has started.";
  log_event(event_type, description);

  // User login event
  event_type = "user";
  description = "User has logged in.";
  log_event(event_type, description);

  // File edited event
  event_type = "file";
  description = "File 'example.txt' has been edited.";
  log_event(event_type, description);

  // Network error event
  event_type = "network";
  description = "Network error has occurred.";
  log_event(event_type, description);

  return 0;
}