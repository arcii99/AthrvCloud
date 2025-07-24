//FormAI DATASET v1.0 Category: System event logger ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Opening message
  printf("Hello, my dear. I have a surprise for you today. It's a C System Event Logger!\n");
  
  // Ask for the event name
  char event_name[50];
  printf("What's the name of the event, my love?\n> ");
  scanf("%s", event_name);
  
  // Open the log file
  FILE *log_file;
  log_file = fopen("event.log", "a");
  
  // Write the event details to the log file
  if (log_file != NULL) {
    fprintf(log_file, "Event name: %s\n", event_name);
    
    // Get the current time
    time_t current_time;
    time(&current_time);
    char *time_str = ctime(&current_time);
    
    // Write the time to the log file
    fprintf(log_file, "Event time: %s\n", time_str);
    
    // Close the log file
    fclose(log_file);
    
    // Display confirmation
    printf("The event has been logged, my love. You can check it in the event.log file.\n");
  } else {
    printf("I'm sorry, my love. There was an error opening the log file.\n");
  }
  
  return 0;
}