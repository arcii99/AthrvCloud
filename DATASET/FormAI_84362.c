//FormAI DATASET v1.0 Category: System event logger ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Get current timestamp
  time_t current_time = time(NULL);

  // Convert timestamp to string format
  char* time_string = ctime(&current_time);

  // Create log file and write timestamp
  FILE* log_file = fopen("event_log.txt", "a");
  fprintf(log_file, "Event logged on: %s", time_string);

  // Gather event information from user
  char event_name[50];
  char event_description[200];
  printf("Enter event name: ");
  scanf("%s", event_name);
  printf("Enter event description: ");
  scanf(" %[^\n]s", event_description);

  // Write event information to log file
  fprintf(log_file, "Event Name: %s\nEvent Description: %s\n", event_name, event_description);

  // Close log file
  fclose(log_file);

  // Print confirmation message to user
  printf("Event logged successfully.\n");

  return 0;
}