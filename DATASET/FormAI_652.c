//FormAI DATASET v1.0 Category: System event logger ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  FILE* log_file;
  char event_data[100];
  time_t epoch_time;

  log_file = fopen("system_events.log", "a");
  
  if(log_file == NULL) {
    printf("Error opening log file.");
    exit(1);
  }

  printf("Enter event type (info/warning/error): ");
  scanf("%s", event_data);

  printf("Enter event description: ");
  scanf(" %[^\n]s", event_data); // Allow spaces in event description

  epoch_time = time(NULL);
  fprintf(log_file, "[%ld]: %s - %s\n", epoch_time, event_data);

  fclose(log_file);

  printf("Event logged successfully.");

  return 0;
}