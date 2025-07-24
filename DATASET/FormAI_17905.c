//FormAI DATASET v1.0 Category: System event logger ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define event type constants
#define EVENT_TYPE_INFO 0
#define EVENT_TYPE_WARNING 1
#define EVENT_TYPE_ERROR 2

// Define struct for events
typedef struct {
    time_t timestamp;
    int type;
    char message[100];
} Event;

// Define global event log array
Event eventLog[1000];
int numEvents = 0;

// Function to add new events to event log
void addEvent(int type, char message[]) {
    Event newEvent;
    newEvent.timestamp = time(NULL);
    newEvent.type = type;
    strcpy(newEvent.message, message);
    eventLog[numEvents] = newEvent;
    numEvents++;
}

// Function to print event log to console
void printEventLog() {
    for (int i = 0; i < numEvents; i++) {
        char type[10];
        switch(eventLog[i].type) {
            case EVENT_TYPE_INFO:
                strcpy(type, "INFO");
                break;
            case EVENT_TYPE_WARNING:
                strcpy(type, "WARNING");
                break;
            case EVENT_TYPE_ERROR:
                strcpy(type, "ERROR");
                break;
        }
        printf("%s [%ld]: %s\n", type, eventLog[i].timestamp, eventLog[i].message);
    }
}

int main() {
    // Add some test events to the log
    addEvent(EVENT_TYPE_WARNING, "Disk space running low");
    addEvent(EVENT_TYPE_ERROR, "Database connection failed");
    addEvent(EVENT_TYPE_INFO, "Application started");

    // Print event log to console
    printEventLog();
    
    return 0;
}