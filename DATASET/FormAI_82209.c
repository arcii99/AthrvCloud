//FormAI DATASET v1.0 Category: System event logger ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILE_NAME "system.log"
#define MAX_EVENT_LENGTH 100

void log_event(char *event) {
  FILE *fp;
  time_t rawtime;
  struct tm *timeinfo;

  time(&rawtime);
  timeinfo = localtime(&rawtime);

  fp = fopen(FILE_NAME, "a");
  if(fp == NULL){
    printf("Error opening file\n");
    exit(1);
  }

  fprintf(fp, "[%02d/%02d/%04d %02d:%02d:%02d] %s\n", 
    timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year+1900, 
    timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec, event);
  fclose(fp);
}

int main() {
  char event[MAX_EVENT_LENGTH];

  printf("Enter an event to log (max length %d): ", MAX_EVENT_LENGTH);
  fgets(event, MAX_EVENT_LENGTH, stdin);

  log_event(event);
  printf("Event logged successfully!\n");

  return 0;
}