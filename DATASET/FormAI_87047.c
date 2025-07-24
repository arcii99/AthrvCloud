//FormAI DATASET v1.0 Category: System event logger ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to hold event information
typedef struct {
    time_t timestamp;
    char* message;
} Event;

// Adds an event to the log file
void addEvent(Event event) {
    // Open log file in append mode
    FILE* logFile = fopen("events.log", "a");
    if (logFile == NULL) {
        printf("Error opening log file.\n");
        exit(EXIT_FAILURE);
    }

    // Write event details to log file
    fprintf(logFile, "%s: %s\n", ctime(&(event.timestamp)), event.message);

    // Close log file
    fclose(logFile);
}

int main() {
    // Set up event 1
    Event event1;
    event1.timestamp = time(NULL);
    event1.message = "System is starting up.";

    // Set up event 2
    Event event2;
    event2.timestamp = time(NULL);
    event2.message = "System has detected an error.";

    // Set up event 3
    Event event3;
    event3.timestamp = time(NULL);
    event3.message = "User has logged out.";

    // Add events to log file
    addEvent(event1);
    addEvent(event2);
    addEvent(event3);

    return 0;
}