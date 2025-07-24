//FormAI DATASET v1.0 Category: System event logger ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LOG_FILE "events.log"

void log_event(char *event_type, char *event_data) {
  time_t current_time;
  struct tm *tm_info;
  
  time(&current_time);
  tm_info = localtime(&current_time);
  
  FILE *log_file = fopen(LOG_FILE, "a");
  
  fprintf(log_file, "[%04d-%02d-%02d %02d:%02d:%02d] %s: %s\n",
          1900 + tm_info->tm_year, tm_info->tm_mon + 1, tm_info->tm_mday,
          tm_info->tm_hour, tm_info->tm_min, tm_info->tm_sec,
          event_type, event_data);
  
  fclose(log_file);
}

int main() {
  log_event("INFO", "System started.");
  log_event("ERROR", "Unable to open file.");
  log_event("WARNING", "Low disk space.");
  
  return 0;
}