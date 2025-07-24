//FormAI DATASET v1.0 Category: System event logger ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EVENTS 1000

typedef enum {
    INFO,
    WARNING,
    ERROR
} EventLevel;

typedef struct {
    time_t timestamp;
    EventLevel level;
    char message[100];
} Event;

Event eventLog[MAX_EVENTS];
int numEvents = 0;

void logEvent(EventLevel level, char* message) {
    if(numEvents == MAX_EVENTS) {
        printf("Error: Event log is full\n");
        return;
    }

    Event newEvent;
    newEvent.timestamp = time(NULL);
    newEvent.level = level;
    strncpy(newEvent.message, message, 100);

    eventLog[numEvents] = newEvent;
    numEvents++;

    printf("Event Logged:\n");
    printf("Timestamp: %s", ctime(&newEvent.timestamp));
    printf("Level: %d\n", newEvent.level);
    printf("Message: %s\n\n", newEvent.message);
}

void printLog() {
    printf("Event Log:\n");
    for(int i=0; i<numEvents; i++) {
        printf("Timestamp: %s", ctime(&eventLog[i].timestamp));
        printf("Level: %d\n", eventLog[i].level);
        printf("Message: %s\n\n", eventLog[i].message);
    }
}

int main() {
    logEvent(INFO, "System started");
    logEvent(INFO, "User logged in");
    logEvent(WARNING, "Low disk space");
    logEvent(ERROR, "File not found");

    printLog();

    return 0;
}