//FormAI DATASET v1.0 Category: System event logger ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Declare the event logger function */
void event_logger(char* event_type, char* event_details, char* filename, int line_number);

int main(void) {
  /* Call the event logger function with some events */
  event_logger("INFO", "The sky is green today", __FILE__, __LINE__);
  event_logger("WARNING", "The trees are floating", __FILE__, __LINE__);
  event_logger("ERROR", "My pills are talking to me", __FILE__, __LINE__);

  return 0;
}

/* Define the event logger function */
void event_logger(char* event_type, char* event_details, char* filename, int line_number) {
  /* Get the current date and time */
  time_t current_time;
  char* c_time_string;
  current_time = time(NULL);
  c_time_string = ctime(&current_time);

  /* Print the surreal event to the console */
  printf("<<<<<<<<<<<<<<<<< Surreal Event Logger >>>>>>>>>>>>>>>>>>>\n");
  printf("Event Type: %s\n", event_type);
  printf("Event Details: %s\n", event_details);
  printf("File: %s, Line: %d\n", filename, line_number);
  printf("Timestamp: %s\n", c_time_string);
  printf("-----------------------------------------------------------\n");
}