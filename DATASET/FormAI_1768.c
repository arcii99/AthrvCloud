//FormAI DATASET v1.0 Category: System event logger ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants
#define MAX_EVENTS 1000
#define MAX_MESSAGE_LENGTH 200

// Define structures
typedef struct {
    int id;
    char timestamp[25];
    char message[MAX_MESSAGE_LENGTH];
} Event;

// Global variables
Event events[MAX_EVENTS];
int numEvents = 0;

// Function prototypes
void logEvent(char* message);
void printEvents();

int main()
{
    printf("System Event Logger\n");

    // Log some events
    logEvent("System started");
    logEvent("File opened");
    logEvent("File closed");
    logEvent("System stopped");

    // Print all events
    printf("\nAll events:\n");
    printEvents();

    return 0;
}

void logEvent(char* message) {
    // Get current timestamp
    time_t now;
    now = time(NULL);

    // Create new event
    Event newEvent;
    newEvent.id = numEvents + 1;
    strftime(newEvent.timestamp, 25, "%Y-%m-%d %H:%M:%S", localtime(&now));
    snprintf(newEvent.message, MAX_MESSAGE_LENGTH, "%s", message);

    // Add event to array
    events[numEvents] = newEvent;
    numEvents++;

    printf("Event #%d logged: %s\n", newEvent.id, newEvent.message);
}

void printEvents() {
    // Print header
    printf("%-5s | %-20s | %-60s\n", "ID", "TIMESTAMP", "MESSAGE");
    printf("------------------------------------------------------------\n");

    // Print events
    for (int i = 0; i < numEvents; i++) {
        printf("%-5d | %-20s | %-60s\n", events[i].id, events[i].timestamp, events[i].message);
    }
}