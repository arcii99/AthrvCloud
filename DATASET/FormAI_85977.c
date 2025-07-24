//FormAI DATASET v1.0 Category: System event logger ; Style: accurate
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

void log_event(char *event, char *source, char *timestamp) {
  FILE *fp = fopen("system_event_log.txt","a");
  if (fp == NULL) {
      printf("Failed to open the system event log file.\n");
      exit(1);
  }
  fprintf(fp, "%s | %s | %s\n", event, source, timestamp);
  fclose(fp);
}

int main(void) {
  time_t t = time(NULL);
  struct tm *timeptr = localtime(&t);
  char timestamp[128];
  strftime(timestamp, 128, "%Y-%m-%d %H:%M:%S", timeptr);

  char event1[128] = "System went offline";
  char source1[128] = "Main Server";
  log_event(event1, source1, timestamp);

  char event2[128] = "Database backup complete";
  char source2[128] = "Database Server";
  log_event(event2, source2, timestamp);

  char event3[128] = "User login failed";
  char source3[128] = "Login Server";
  log_event(event3, source3, timestamp);

  return 0;
}