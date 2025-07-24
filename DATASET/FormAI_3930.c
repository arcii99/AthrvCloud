//FormAI DATASET v1.0 Category: System event logger ; Style: safe
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function to log events
void log_event(char* event){
  FILE *fileptr;
  time_t current_time;
  char* time_string;
  // Open the log file in append mode
  fileptr = fopen("event_log.txt", "a");
  if(fileptr == NULL){
    printf("Error: Unable to open file.");
  }
  else{
    // Get current time
    current_time = time(NULL);
    time_string = ctime(&current_time);
    // Write event and time to file
    fprintf(fileptr, "%s\t%s\n", event, time_string);
    printf("Event logged successfully.\n");
    // Close the file
    fclose(fileptr);
  }
}

// Test function to generate random events
void test_event_logger(){
  char* events[5] = {"Event A", "Event B", "Event C", "Event D", "Event E"};
  int i;
  // Log each event
  for(i = 0; i < 5; i++){
    log_event(events[i]);
  }
}

int main(){
  // Test the event logger
  test_event_logger();
  return 0;
}