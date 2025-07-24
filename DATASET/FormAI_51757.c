//FormAI DATASET v1.0 Category: System event logger ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to log events into file
void log_event(char *event) {
  FILE *fp;
  char *filename = "system_events.log";
  char time_str[20];
  time_t current_time;

  // Get current time as string
  time(&current_time);
  strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", localtime(&current_time));

  // Open file for appending
  fp = fopen(filename, "a");

  // Check if file opened successfully
  if (fp != NULL) {
    // Write event and current time to file
    fprintf(fp, "[%s] %s\n", time_str, event);

    // Close file
    fclose(fp);
  }
}

int main() {
  char event[100];

  // Get event from user input
  printf("Enter event to log: ");
  fgets(event, 100, stdin);

  // Log event
  log_event(event);

  return 0;
}