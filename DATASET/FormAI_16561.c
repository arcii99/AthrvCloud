//FormAI DATASET v1.0 Category: System event logger ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_EVENTS 1000

int numOfEvents = 0; // stores the number of events logged so far

typedef struct {
    time_t timestamp;
    char* event;
} Event;

Event events[MAX_EVENTS];

int logEvent(char* event) {
    if (numOfEvents >= MAX_EVENTS) {
        return -1; // Event queue is full
    }

    Event e;
    e.timestamp = time(NULL); // current timestamp
    e.event = event;

    events[numOfEvents++] = e;

    return 0; // Event successfully logged
}

void displayEvents() {
    printf("Timestamp\t\tEvent\n");
    printf("----------------------------------------\n");

    for (int i = 0; i < numOfEvents; i++) {
        printf("%ld\t%s\n", events[i].timestamp, events[i].event);
    }
}

int main() {
    char* event1 = "System Startup";
    char* event2 = "File Read Error";
    char* event3 = "User Login Successful";
    char* event4 = "Memory Allocation Error";
    
    // Log some events
    logEvent(event1);
    logEvent(event2);
    logEvent(event3);
    logEvent(event4);

    // Display all events
    displayEvents();

    return 0;
}