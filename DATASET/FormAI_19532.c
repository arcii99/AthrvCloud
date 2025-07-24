//FormAI DATASET v1.0 Category: System event logger ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_EVENTS 10000
#define MAX_EVENT_DETAILS 100

// Structure to store the event details
typedef struct {
   time_t timestamp;
   char details[MAX_EVENT_DETAILS];
} Event;

Event eventLog[MAX_EVENTS];   // Array to store the events
int eventCount = 0;   // Count of total number of events logged

// Function to log an event and store the details in the eventLog array
void logEvent(char *eventDetails) {
   // Get current timestamp
   time_t now;
   time(&now);
   
   // Create a new event with current timestamp and provided details
   Event newEvent = {now, *eventDetails};
   
   // Add the new event to the eventLog array
   eventLog[eventCount] = newEvent;
   eventCount++;
}

// Function to display all events logged in the eventLog array
void displayEvents() {
   printf("\nEVENT LOG:\n");
   printf("----------------------------------------------------\n");
   printf("Timestamp\t\tDetails\n");
   for (int i = 0; i < eventCount; i++) {
      printf("%s\t%s\n", ctime(&eventLog[i].timestamp), eventLog[i].details);
   }
   printf("----------------------------------------------------\n");
}

int main() {
   char eventDetails[MAX_EVENT_DETAILS];
   
   // Log some events
   logEvent("System initialization");
   logEvent("File system mounted");
   logEvent("Database connection established");
   logEvent("User login successful");
   
   // Display all logged events
   displayEvents();
   
   return 0;
}