//FormAI DATASET v1.0 Category: System event logger ; Style: Donald Knuth
/* A unique C system event logger program */

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define MAX_EVENTS 100

struct event {
   time_t timestamp;
   char *event_type;
   char *event_text;
};

struct event_buffer {
   struct event events[MAX_EVENTS];
   int event_count;
};

/* Utility function to get the current UTC timestamp */
void get_utc_timestamp(time_t *timestamp) {
   time(timestamp);
}

/* Function to log the system event into the event buffer */
void log_event(struct event_buffer *buffer, char *event_type, char *event_text) {
   if (buffer->event_count < MAX_EVENTS) {
      struct event new_event;
      new_event.timestamp = time(NULL);
      new_event.event_type = event_type;
      new_event.event_text = event_text;
      buffer->events[buffer->event_count++] = new_event;
   }
}

/* Function to print the event buffer */
void print_event_buffer(struct event_buffer *buffer) {
   printf("| Timestamp              | Event type | Event description                  |\n");
   printf("|------------------------|------------|-----------------------------------|\n");
   
   for (int i=0; i<buffer->event_count; i++) {
      char timestamp_string[20];
      strftime(timestamp_string, 20, "%Y-%m-%d %H:%M:%S", gmtime(&buffer->events[i].timestamp));
      printf("| %s | %-10s | %-33s |\n", timestamp_string, buffer->events[i].event_type, buffer->events[i].event_text);
   }
}

/* Main function to demonstrate the event logging functionality */
int main() {
   struct event_buffer event_log;
   event_log.event_count = 0;
   
   log_event(&event_log, "ERROR", "Unable to connect to the network");
   log_event(&event_log, "INFO", "System started successfully");
   log_event(&event_log, "WARNING", "Disk space is running low");
   
   print_event_buffer(&event_log);
   
   return 0;
}