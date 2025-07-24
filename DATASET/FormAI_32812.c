//FormAI DATASET v1.0 Category: System event logger ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_EVENTS 100 // Maximum number of events that can be logged
#define MAX_LOG_LENGTH 256 // Maximum length of each log entry

typedef struct {
    int event_id;
    char timestamp[20];
    char message[MAX_LOG_LENGTH];
} Event;

Event event_log[MAX_EVENTS]; // Global storage for logged events
int num_events_logged = 0; // Keep track of number of events logged

// Function to log an event
void log_event(int event_id, char* message) {
    // Check if the log is not full
    if (num_events_logged < MAX_EVENTS) {
        Event new_event;
        new_event.event_id = event_id;

        // Get current time
        time_t current_time = time(NULL);
        strftime(new_event.timestamp, sizeof(new_event.timestamp), "%Y-%m-%d %H:%M:%S", localtime(&current_time));

        // Copy message to event
        strcpy(new_event.message, message);

        event_log[num_events_logged] = new_event;
        num_events_logged++; // Increment number of events logged
    }
}

// Function to print all logged events
void print_event_log() {
    int i;
    printf("\nEvent Log:\n\n");

    for (i = 0; i < num_events_logged; i++) {
        printf("Event ID: %d\n", event_log[i].event_id);
        printf("Timestamp: %s\n", event_log[i].timestamp);
        printf("Message: %s\n\n", event_log[i].message);
    }

    printf("%d events logged.\n", num_events_logged);
}

int main() {
    int i;

    // Simulate logging of events
    for (i = 1; i <= 10; i++) {
        char message[MAX_LOG_LENGTH];
        sprintf(message, "Event %d occurred.", i);
        log_event(i, message);
        sleep(1);
    }

    // Print all logged events
    print_event_log();

    return 0;
}