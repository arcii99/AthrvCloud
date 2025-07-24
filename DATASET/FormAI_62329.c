//FormAI DATASET v1.0 Category: System event logger ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void log_event(char *message) {
  FILE *fp;
  time_t current_time;
  struct tm *time_info;
  char time_string[9];

  time(&current_time);
  time_info = localtime(&current_time);

  strftime(time_string, sizeof(time_string), "%H:%M:%S", time_info);

  fp = fopen("event_log.txt", "a");
  fprintf(fp, "[%s] %s\n", time_string, message);
  fclose(fp);
}

int main() {
  char input[100];
  printf("Welcome to the event logger!\nWhat event would you like to log?\n");
  fgets(input, sizeof(input), stdin);

  log_event(input);

  printf("\nThe event has been logged in event_log.txt.");

  return 0;
}