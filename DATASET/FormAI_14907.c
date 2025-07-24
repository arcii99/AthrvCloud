//FormAI DATASET v1.0 Category: System event logger ; Style: satisfied
#include <stdio.h>
#include <time.h>

/* Define the maximum number of events */
#define MAX_EVENTS 100

/* Define the structure for a single event */
typedef struct event {
    char type[50];
    char message[200];
    time_t timestamp;
} event_t;

/* Define an array to hold all the events */
event_t events[MAX_EVENTS];

/* Define the index of the last event */
int last_event_index = -1;

/* Function to log an event */
void log_event(char* type, char* message) {
    /* Increment the index of the last event */
    last_event_index++;

    /* If the index exceeds the maximum number of events, reset to zero */
    if (last_event_index >= MAX_EVENTS) {
        last_event_index = 0;
    }

    /* Get the current timestamp */
    time_t current_time;
    time(&current_time);

    /* Fill in the details of the current event */
    strcpy(events[last_event_index].type, type);
    strcpy(events[last_event_index].message, message);
    events[last_event_index].timestamp = current_time;
}

/* Function to print all the events */
void print_events() {
    /* Print the header */
    printf("%-20s %-40s %-30s\n", "Type", "Message", "Timestamp");
    printf("--------------------------------------------------------------------------------\n");

    /* Loop through all the events and print each one */
    for (int i = 0; i <= last_event_index; i++) {
        printf("%-20s %-40s %s", events[i].type, events[i].message, ctime(&events[i].timestamp));
    }
}

/* Example usage */
int main() {
    /* Log some events */
    log_event("Error", "Disk space low");
    log_event("Warning", "Network connection lost");
    log_event("Info", "User login successful");

    /* Print all the events */
    print_events();

    return 0;
}