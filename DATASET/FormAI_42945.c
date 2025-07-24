//FormAI DATASET v1.0 Category: System event logger ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void log_event(char* event) {

  time_t current_time = time(NULL);
  char* time_string = ctime(&current_time);

  FILE* log_file = fopen("event.log", "a");

  if(log_file == NULL) {
    printf("Error: could not open log file.\n");
    exit(1);
  }

  fprintf(log_file, "%s | %s\n", time_string, event);

  fclose(log_file);

}

int main() {

  char* event1 = "System started";
  char* event2 = "User logged in";
  char* event3 = "User logged out";
  char* event4 = "System error";

  log_event(event1);
  log_event(event4);
  log_event(event2);
  log_event(event3);

  return 0;

}