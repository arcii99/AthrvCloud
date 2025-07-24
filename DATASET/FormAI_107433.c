//FormAI DATASET v1.0 Category: System event logger ; Style: creative
#include <stdio.h>
#include <time.h>

#define MAX_EVENTS 1000

typedef enum {
    SUCCESS,
    INFO,
    WARNING,
    ERROR,
} LogLevel;

typedef struct {
    time_t timestamp;
    char* event;
    LogLevel level;
} Event;

void logEvent(Event* event) {
    printf("[%ld] ", event->timestamp);
    switch (event->level) {
        case SUCCESS:
            printf("SUCCESS: ");
            break;
        case INFO:
            printf("INFO: ");
            break;
        case WARNING:
            printf("WARNING: ");
            break;
        case ERROR:
            printf("ERROR: ");
            break;
    }
    printf("%s\n", event->event);
}

int main() {
    Event events[MAX_EVENTS];
    int numEvents = 0;

    // Create Sample Events
    Event event1 = { time(NULL), "The system has started.", SUCCESS };
    events[numEvents++] = event1;

    Event event2 = { time(NULL), "The database connection has been established.", SUCCESS };
    events[numEvents++] = event2;

    Event event3 = { time(NULL), "The user has logged in.", INFO };
    events[numEvents++] = event3;

    Event event4 = { time(NULL), "An error has occurred while saving the user's profile.", ERROR };
    events[numEvents++] = event4;

    Event event5 = { time(NULL), "Invalid input detected.", WARNING };
    events[numEvents++] = event5;

    // Print Out All Events
    for (int i = 0; i < numEvents; i++) {
        logEvent(&events[i]);
    }

    return 0;
}