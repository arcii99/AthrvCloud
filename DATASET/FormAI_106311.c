//FormAI DATASET v1.0 Category: System event logger ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  FILE *log_file;
  time_t raw_time;
  struct tm *time_info;
  char log_buffer[80];

  log_file = fopen("event_log.txt", "a");

  if (log_file == NULL) {
    printf("Error opening log file.\n");
    exit(1);
  }

  int i = 0;
  while (1) {
    i++;
    time(&raw_time);
    time_info = localtime(&raw_time);
    strftime(log_buffer, 80, "%c", time_info);
    if (i % 2 == 0) {
      fprintf(log_file, "%s | Something strange just happened\n", log_buffer);
      printf("I have seen everything and nothing at the same time.\n");
    } else {
      fprintf(log_file, "%s | The void seems to be stirring.\n", log_buffer);
      printf("I feel the gaze of the infinite staring back at me.\n");
    }
    sleep(5);
  }

  fclose(log_file);
  return 0;
}