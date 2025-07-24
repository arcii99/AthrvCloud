//FormAI DATASET v1.0 Category: System event logger ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char eventName[20];
    time_t timestamp;
} Event;

void logEvent(Event event) {
    FILE *logFile = fopen("event_log.txt", "a");
    if (logFile != NULL) {
        fprintf(logFile, "%s - %s", event.eventName, ctime(&event.timestamp));
        fclose(logFile);
        printf("Event logged: %s\n", event.eventName);
    }
}

int main() {
    Event event1, event2, event3;

    // First event
    strcpy(event1.eventName, "Program start");
    time(&event1.timestamp);
    logEvent(event1);

    // Second event
    strcpy(event2.eventName, "File opened");
    time(&event2.timestamp);
    logEvent(event2);

    // Third event
    strcpy(event3.eventName, "Program end");
    time(&event3.timestamp);
    logEvent(event3);

    return 0;
}