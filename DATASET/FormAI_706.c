//FormAI DATASET v1.0 Category: System event logger ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants
#define MAX_EVENTS 1000
#define MAX_EVENT_DESC_LENGTH 100

// Define a struct to represent each event
typedef struct Event {
  time_t timestamp;
  char description[MAX_EVENT_DESC_LENGTH];
} Event;

// Define a function to log events
void logEvent(Event events[], int *numEvents, char *desc) {
  // Create a new event and add it to the events array
  Event newEvent;
  newEvent.timestamp = time(NULL);
  snprintf(newEvent.description, MAX_EVENT_DESC_LENGTH, "%s", desc);
  events[*numEvents] = newEvent;

  // Increment the counter for the number of events
  (*numEvents)++;
}

int main() {
  // Initialize variables
  Event events[MAX_EVENTS];
  int numEvents = 0;

  // Log some events
  logEvent(events, &numEvents, "Application started.");
  logEvent(events, &numEvents, "User clicked button.");
  logEvent(events, &numEvents, "Error occurred.");

  // Print out the events
  printf("Event log:\n");
  for (int i = 0; i < numEvents; i++) {
    printf("%s\n", ctime(&events[i].timestamp));
    printf("%s\n", events[i].description);
    printf("\n");
  }

  return 0;
}