//FormAI DATASET v1.0 Category: System event logger ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define LOG_FILE "event.log" // Define the log file name

int main(){
  FILE *fp;
  char eventName[50];
  int eventPriority;

  // Get current time for logging the events
  time_t currTime;
  time(&currTime); 

  // Open the log file in append mode
  fp = fopen(LOG_FILE, "a");

  if(fp == NULL){
    printf("Unable to open log file '%s' for writing\n", LOG_FILE);
    exit(1);
  }

  // Prompt the user for event details
  printf("Enter the event name: ");
  fgets(eventName, 50, stdin);

  printf("Enter the event priority (1-5): ");
  scanf("%d", &eventPriority);

  // Log the event details to the file
  fprintf(fp, "[%s] - Event Name: %s, Event Priority: %d\n", ctime(&currTime), eventName, eventPriority);

  // Close the log file
  fclose(fp);

  return 0;
}