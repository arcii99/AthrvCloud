//FormAI DATASET v1.0 Category: System event logger ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void log_event(char* event_name) {
  time_t now = time(NULL);
  struct tm* timeinfo = localtime(&now);
  
  FILE* logfile = fopen("event_log.txt", "a");
  fprintf(logfile, "%d/%d/%d - %d:%d:%d: %s\n", timeinfo->tm_mon+1, timeinfo->tm_mday, timeinfo->tm_year+1900, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec, event_name);
  fclose(logfile);
}

int main() {
  char event_name[100];
  printf("Welcome to the Event Logger. Please enter the name of the event: ");
  scanf("%[^\n]%*c", event_name);
  
  log_event(event_name);
  
  printf("Event logged successfully!");
  return 0;
}