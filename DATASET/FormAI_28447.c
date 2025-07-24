//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants
#define MAX_EVENTS 1000
#define MAX_EVENT_LENGTH 100
#define MAX_MESSAGE_LENGTH 200

// Define data structures
typedef struct {
    char event_name[MAX_EVENT_LENGTH];
} Event;

typedef struct {
    Event events[MAX_EVENTS];
    int num_events;
} EventLog;

// Function prototypes
void logEvent(EventLog* log, char* event_name);
void printEvents(EventLog* log);
void detectIntrusion(EventLog* log);

// Main function
int main() {
    // Initialize data structures
    EventLog log;
    log.num_events = 0;

    // Log some events
    logEvent(&log, "System reboot");
    logEvent(&log, "Login failure");
    logEvent(&log, "Access granted");

    // Print events
    printEvents(&log);

    // Detect intrusion
    detectIntrusion(&log);

    return 0;
}

// Log an event
void logEvent(EventLog* log, char* event_name) {
    // Check if log is full
    if (log->num_events >= MAX_EVENTS) {
        printf("Error: Event log is full\n");
        return;
    }

    // Copy event name to log
    strncpy(log->events[log->num_events].event_name, event_name, MAX_EVENT_LENGTH);
    log->num_events++;
}

// Print all events in the log
void printEvents(EventLog* log) {
    printf("Event Log:\n");
    for (int i = 0; i < log->num_events; i++) {
        printf("- %s\n", log->events[i].event_name);
    }
    printf("\n");
}

// Detect intrusion based on event log
void detectIntrusion(EventLog* log) {
    // Check for signs of intrusion
    int login_failure_count = 0;
    int access_granted_count = 0;
    for (int i = 0; i < log->num_events; i++) {
        if (strcmp(log->events[i].event_name, "Login failure") == 0) {
            login_failure_count++;
        }
        if (strcmp(log->events[i].event_name, "Access granted") == 0) {
            access_granted_count++;
        }
    }
    if (login_failure_count > 5 || access_granted_count > 10) {
        // Report intrusion
        char message[MAX_MESSAGE_LENGTH];
        snprintf(message, MAX_MESSAGE_LENGTH, "Possible intrusion detected (login failures: %d, access granted: %d)", login_failure_count, access_granted_count);
        printf("Intrusion detected! %s\n\n", message);
    } else {
        printf("No intrusion detected\n\n");
    }
}