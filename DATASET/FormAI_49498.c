//FormAI DATASET v1.0 Category: System event logger ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 100

typedef struct {
    char event[MAX_LENGTH];
    time_t timestamp;
} Event;

Event events[MAX_LENGTH];
int eventCount = 0;

void logEvent(char* eventString) {
    Event newEvent;
    newEvent.timestamp = time(NULL);
    snprintf(newEvent.event, MAX_LENGTH, "%s", eventString);
    events[eventCount] = newEvent;
    eventCount++;
}

void printEvents() {
    printf("\n");
    for (int i = 0; i < eventCount; i++) {
        printf("%d | %s | %s", i+1, asctime(localtime(&events[i].timestamp)), events[i].event);
    }
    printf("\n");
}

int main() {
    logEvent("System started");
    printf("System is running...\n");
    // do some work here
    logEvent("User logged in");
    // do some work here
    logEvent("User logged out");
    printf("System is shutting down...\n");
    logEvent("System shutdown");

    printEvents();

    return 0;
}