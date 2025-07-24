//FormAI DATASET v1.0 Category: System event logger ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define LOGFILE "system_event_log.txt" // File to store log information

void log_event(const char* event_str){
  FILE *fptr;
  time_t current_time;

  // Open the file in append mode
  fptr = fopen(LOGFILE, "a");

  // Check if file was opened successfully
  if(fptr == NULL){
    printf("Error opening file!");
    exit(1);
  }

  // Get the current time
  time(&current_time);

  // Write the time and event string to the log file
  fprintf(fptr, "%s %s\n", asctime(localtime(&current_time)), event_str);

  // Close the file
  fclose(fptr);
}

int main(){
  // Declare some event strings to log
  const char* event1 = "System started up successfully.";
  const char* event2 = "User logged in.";
  const char* event3 = "File saved.";
  const char* event4 = "Error occurred!";

  // Log the events
  log_event(event1);
  log_event(event2);
  log_event(event3);
  log_event(event4);

  return 0;
}