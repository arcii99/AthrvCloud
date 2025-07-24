//FormAI DATASET v1.0 Category: System event logger ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  time_t timestamp;
  
  printf("Welcome to the System Event Logger!\n");
  
  // Open log file for writing
  FILE* log_file = fopen("event_log.txt", "a");
  
  // Check if log file was successfully opened
  if (log_file == NULL) {
    printf("Failed to open event log file.");
    return 0;
  }
  
  // Get current timestamp and write to log file
  timestamp = time(NULL);
  fprintf(log_file, "Program started at: %s", ctime(&timestamp));
  
  // Log user input events
  char input;
  int event_counter = 1;
  
  do {
    printf("Enter event (type 'q' to quit): ");
    scanf(" %c", &input);
    
    // Get current timestamp and write to log file
    timestamp = time(NULL);
    fprintf(log_file, "Event %d - %c: %s", event_counter, input, ctime(&timestamp));
    event_counter++;
  } while (input != 'q');
  
  // Close log file when finished
  fclose(log_file);
  
  return 0;
}