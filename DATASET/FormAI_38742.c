//FormAI DATASET v1.0 Category: System event logger ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void log_event(char* event) {
  time_t current_time;
  char* timestamp;
  FILE *file_ptr;
  
  current_time = time(NULL);
  timestamp = ctime(&current_time);
  
  file_ptr = fopen("system_log.txt", "a");
  
  if (file_ptr == NULL) {
    printf("Failed to create log file.\n");
    exit(EXIT_FAILURE);
  }
  
  fprintf(file_ptr, "[%s] %s\n", timestamp, event);
  fclose(file_ptr);
}

int main() {
  char event[100];
  
  printf("Enter event description: ");
  fgets(event, 100, stdin);
  
  log_event(event);
  
  printf("Event successfully logged.\n");
  return 0;
}