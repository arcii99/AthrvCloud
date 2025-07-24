//FormAI DATASET v1.0 Category: System event logger ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define MAX_EVENTS 100

// Struct for system events
typedef struct SystemEvent {
    time_t timestamp;
    char message[100];
} SystemEvent;

// Global array to store system events
SystemEvent events[MAX_EVENTS];
int eventCount = 0;

// Logs a system event
void logEvent(const char* message) {
    if (eventCount == MAX_EVENTS) {
        printf("Error: Maximum number of events reached\n");
        return;
    }
    SystemEvent newEvent;
    newEvent.timestamp = time(NULL);
    strncpy(newEvent.message, message, 100);
    events[eventCount] = newEvent;
    eventCount++;
}

// Displays all system events
void displayEvents() {
    printf("System events:\n");
    for (int i = 0; i < eventCount; i++) {
        struct tm* timeinfo;
        timeinfo = localtime(&events[i].timestamp);
        printf("%s: %s\n", asctime(timeinfo), events[i].message);
    }
}

int main() {
    logEvent("System started");
    sleep(2); // simulate program running
    logEvent("User logged in");
    sleep(3); // simulate program running
    logEvent("User logged out");
    displayEvents();
    return 0;
}