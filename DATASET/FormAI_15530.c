//FormAI DATASET v1.0 Category: System event logger ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function prototype */
void log_event(char *);

int main() {
  /* set the seed for the random number generator */
  srand(time(NULL));

  /* create an array of event messages */
  char *event_messages[] = {
    "System started.",
    "File read error.",
    "User logged in.",
    "Memory allocation error.",
    "Program terminated unexpectedly.",
    "Network connection lost.",
    "Input validation error.",
    "Security breach detected.",
    "System shutdown.",
    "Disk space low."
  };

  /* determine the number of event messages */
  int num_events = sizeof(event_messages) / sizeof(char *);

  /* generate a random number to select an event message */
  int event_index = rand() % num_events;

  /* log the event message */
  log_event(event_messages[event_index]);

  return 0;
}

/* Function definition for log_event() */
void log_event(char *event_message) {
  /* get the current time */
  time_t current_time;
  time(&current_time);

  /* format the event message and time stamp */
  char log_message[100];
  sprintf(log_message, "[%s] %s\n", ctime(&current_time), event_message);

  /* write the log message to a file */
  FILE *log_file = fopen("system.log", "a");
  if (log_file == NULL) {
    printf("Error: Unable to open system.log for writing.\n");
    exit(1);
  }
  fprintf(log_file, "%s", log_message);
  fclose(log_file);

  printf("Event logged: %s", event_message);
}