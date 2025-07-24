//FormAI DATASET v1.0 Category: System event logger ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define event types
enum EventType {
    INFO,
    WARNING,
    ERROR
};

// Define event structure
typedef struct {
    enum EventType type;
    time_t timestamp;
    char message[1024];
} Event;

// Define logger function
void logEvent(Event event) {
    // Create timestamp string
    char timestampString[64];
    strftime(timestampString, sizeof(timestampString), "%Y-%m-%d %H:%M:%S", localtime(&event.timestamp));

    // Determine event type string
    char *typeString;
    switch(event.type) {
        case INFO:
            typeString = "INFO";
            break;
        case WARNING:
            typeString = "WARNING";
            break;
        case ERROR:
            typeString = "ERROR";
            break;
    }

    // Print event information
    printf("[%s] %s: %s\n", timestampString, typeString, event.message);
}

int main() {
    // Create sample events
    Event event1 = { INFO, time(NULL), "Program started" };
    Event event2 = { WARNING, time(NULL), "File size is too large" };
    Event event3 = { ERROR, time(NULL), "Memory allocation failed" };

    // Log events
    logEvent(event1);
    logEvent(event2);
    logEvent(event3);

    // Exit program
    return 0;
}