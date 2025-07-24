//FormAI DATASET v1.0 Category: System event logger ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Defining the structure that represents a log event */
typedef struct {
   time_t timestamp;
   char* event;
} LogEvent;

/* Initializing the array that will hold our log events */
LogEvent eventLog[100];

/* Method that logs an event */
void logEvent(char* event) {
   /* Finding the next available index */
   int index = 0;
   while (eventLog[index].timestamp != 0 ) {
      index++;
   }
   /* Creating a new log event with the current system time */
   LogEvent newEvent;
   newEvent.timestamp = time(NULL);
   newEvent.event = event;
   /* Adding the event to the array */
   eventLog[index] = newEvent;
}

/* Printing the entire event log */
void printLog() {
   /* Looping through the event array */
   int index = 0;
   while (eventLog[index].timestamp != 0 ) {
      printf("%s at %s", eventLog[index].event, ctime(&eventLog[index].timestamp));
      index++;
   }
}

int main() {
   /* Logging some sample events */
   logEvent("User logged in");
   logEvent("File Updated");
   logEvent("Error 404 occurred");
   /* Printing the entire event log */
   printLog();
}