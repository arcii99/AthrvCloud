//FormAI DATASET v1.0 Category: System event logger ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void logEvent(const char* event) {
  FILE *file = fopen("system_log.txt", "a");
  if(file == NULL) {
    printf("Error opening file!\n");
    exit(1);
  }

  time_t rawtime;
  struct tm *timeinfo;
  time(&rawtime);
  timeinfo = localtime(&rawtime);
  
  char timestamp[80];
  strftime(timestamp, 80, "%Y-%m-%d %H:%M:%S", timeinfo);

  char* message = (char*) malloc(strlen(event) + 25);
  sprintf(message, "%s - %s\n", timestamp, event);
    
  fputs(message, file);
  fclose(file);
  free(message);
}

int main(void) {
  printf("Welcome to the System Event Logger.\n");
  printf("Enter the event you would like to log:\n");

  char event[256];
  scanf("%[^\n]%*c", event);
  logEvent(event);

  printf("Event logged to system_log.txt\n");

  return 0;
}