//FormAI DATASET v1.0 Category: System event logger ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define EVENT_LOG_FILE "event.log"  // define the event log file name 

// declare a struct to represent an event
typedef struct event {
    time_t timestamp;  // the time the event occurred
    char* message;     // the message describing the event
} event_t;

int main() {
    // open the event log file to append events
    FILE* log_file = fopen(EVENT_LOG_FILE, "a");
    if (!log_file) {
        printf("Failed to open event log file!\n");
        return 1;
    }

    // create an example event
    event_t new_event;
    new_event.timestamp = time(NULL);
    new_event.message = "System update complete";

    // write the event to the log file
    fprintf(log_file, "[%ld] %s\n", new_event.timestamp, new_event.message);

    // close the log file
    fclose(log_file);

    return 0;
}