//FormAI DATASET v1.0 Category: System event logger ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  FILE *fp;
  char filename[20];
  char event[100];
  time_t rawtime;
  struct tm * timeinfo;
  
  printf("Enter the name of the log file (max 20 characters): ");
  scanf("%s", filename);
  
  fp = fopen(filename, "w");
  
  if (fp == NULL) {
    printf("Error creating log file!");
    exit(1);
  }
  
  printf("Event logger started...\n");
  
  while(1) {
    printf("Enter event: ");
    scanf("%s", event);
    
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    
    fprintf(fp, "[%04d/%02d/%02d %02d:%02d:%02d] %s\n",
            timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday,
            timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec, event);
    
    printf("Event logged!\n");
  }
  
  fclose(fp);
  return 0;
}