//FormAI DATASET v1.0 Category: System event logger ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void log_event(char* event) {
  time_t rawtime;
  struct tm * timeinfo;
  time(&rawtime);
  timeinfo = localtime(&rawtime);
  char* timestamp = asctime(timeinfo);
  strtok(timestamp, "\n");
  FILE* log_file = fopen("event_log.txt", "a");
  if (log_file == NULL) {
      printf("*** Error: Could not open log file ***\n");
      exit(1);
  }
  fprintf(log_file, "[%s]: %s\n", timestamp, event);
  fclose(log_file);
}

int main() {
  printf("== C System Event Logger ==\n\n");

  printf("Type 'exit' to exit the program\n\n");

  char input[100];
  while (1) {
    printf("Enter an event to log: ");
    fgets(input, 100, stdin);
    strtok(input, "\n");
    if (strcmp(input, "exit") == 0) {
      printf("Goodbye!\n");
      break;
    }
    log_event(input);
    printf("Event logged successfully!\n");
  }
  return 0;
}