//FormAI DATASET v1.0 Category: System event logger ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum {
    EVENT_TYPE_INFO,
    EVENT_TYPE_WARNING,
    EVENT_TYPE_ERROR
} EventType;

typedef struct {
    time_t timestamp;
    EventType type;
    const char* message;
} Event;

void logEvent(EventType type, const char* message);
void printEvent(Event event);

int main() {
    logEvent(EVENT_TYPE_INFO, "Application started");

    /* Simulate some events */
    logEvent(EVENT_TYPE_WARNING, "Disk space low");
    logEvent(EVENT_TYPE_ERROR, "Memory allocation failed");

    logEvent(EVENT_TYPE_INFO, "Application shutting down");

    return 0;
}

void logEvent(EventType type, const char* message) {
    /* Get current timestamp */
    time_t now = time(NULL);

    /* Construct event object */
    Event event = {
        .timestamp = now,
        .type = type,
        .message = message
    };

    /* Print event to console */
    printEvent(event);

    /* TODO: Write event to file or database */
}

void printEvent(Event event) {
    char timeBuf[26];
    ctime_r(&event.timestamp, timeBuf);
    timeBuf[24] = '\0';

    const char* typeString;
    switch (event.type) {
        case EVENT_TYPE_INFO: typeString = "INFO"; break;
        case EVENT_TYPE_WARNING: typeString = "WARNING"; break;
        case EVENT_TYPE_ERROR: typeString = "ERROR"; break;
        default: typeString = "UNKNOWN"; break;
    }

    printf("%s [%s] %s\n", timeBuf, typeString, event.message);
}