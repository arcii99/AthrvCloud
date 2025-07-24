//FormAI DATASET v1.0 Category: System event logger ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of events that can be logged
#define MAX_EVENTS 1000

// Define the maximum length of an event description
#define MAX_DESC_LENGTH 50

// Define the structure of an event log entry
typedef struct {
    time_t timestamp;
    char description[MAX_DESC_LENGTH];
} EventLogEntry;

// Define the global event log
EventLogEntry eventLog[MAX_EVENTS];

// Define the global index of the next available event log entry
int nextAvailableEventLogEntry = 0;

// Define a function for adding an event to the log
void logEvent(char* description) {
    time_t currentTime = time(NULL);
    if (nextAvailableEventLogEntry < MAX_EVENTS) {
        eventLog[nextAvailableEventLogEntry].timestamp = currentTime;
        if (strlen(description) < MAX_DESC_LENGTH) {
            strcpy(eventLog[nextAvailableEventLogEntry].description, description);
        } else {
            strncpy(eventLog[nextAvailableEventLogEntry].description, description, MAX_DESC_LENGTH - 1);
            eventLog[nextAvailableEventLogEntry].description[MAX_DESC_LENGTH - 1] = '\0'; // Terminate the string with a null character
        }
        nextAvailableEventLogEntry++;
        printf("Event logged successfully!\n");
        printf("Timestamp: %s\nDescription: %s\n", asctime(localtime(&currentTime)), description);
    } else {
        printf("Event log is full. Cannot log new events.\n");
    }
}

int main() {
    // Log some sample events
    logEvent("Test event 1.");
    logEvent("Test event 2.");
    logEvent("Test event 3.");

    return 0;
}