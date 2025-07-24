//FormAI DATASET v1.0 Category: System event logger ; Style: beginner-friendly
#include <stdio.h>
#include <time.h>

#define MAX_EVENTS 1000

// Struct to hold event information
typedef struct {
    time_t timestamp;
    char message[100];
} Event;

// Global array to hold all events
Event events[MAX_EVENTS];
int numEvents = 0;

// Function to add an event to the events array
void logEvent(char* message) {
    Event newEvent;
    newEvent.timestamp = time(NULL);
    strncpy(newEvent.message, message, 100);
    events[numEvents++] = newEvent;
}

// Function to print all events to the console
void printEvents() {
    printf("Timestamp\tMessage\n");
    printf("------------------------\n");
    for (int i = 0; i < numEvents; i++) {
        printf("%ld\t%s\n", events[i].timestamp, events[i].message);
    }
}

int main() {
    // Add some example events
    logEvent("System started");
    logEvent("User logged in");
    logEvent("File saved successfully");

    // Print all events to the console
    printEvents();

    return 0;
}