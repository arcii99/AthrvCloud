//FormAI DATASET v1.0 Category: System event logger ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants used in the program
#define MAX_EVENTS 50
#define MAX_BUFFER_SIZE 1024

// Define the structure for storing events
typedef struct {
    int id;
    char timestamp[20];
    char event_name[MAX_BUFFER_SIZE];
    char event_details[MAX_BUFFER_SIZE];
} Event;

// Define the structure for storing the event logs
typedef struct {
    Event events[MAX_EVENTS];
    int num_events;
} EventLog;

// Define the functions used in the program
void log_event(Event event, EventLog *event_log);
void print_all_events(EventLog event_log);
void print_event(Event event);

// Define the main function
int main() {
    // Define variables used in the program
    char buffer[MAX_BUFFER_SIZE];
    char event_name[MAX_BUFFER_SIZE];
    char event_details[MAX_BUFFER_SIZE];
    EventLog event_log;
    Event event;
    int event_id = 0;

    // Initialize the event log
    event_log.num_events = 0;

    // Loop to continuously accept user input and log events
    while (1) {
        // Prompt the user for the event name
        printf("Enter the event name: ");
        fgets(event_name, MAX_BUFFER_SIZE, stdin);

        // Remove the newline character from the event name
        event_name[strcspn(event_name, "\n")] = '\0';

        // If the event name is "exit", break out of the loop
        if (strcmp(event_name, "exit") == 0) {
            break;
        }

        // Prompt the user for the event details
        printf("Enter the event details: ");
        fgets(event_details, MAX_BUFFER_SIZE, stdin);

        // Remove the newline character from the event details
        event_details[strcspn(event_details, "\n")] = '\0';

        // Create the event and log it
        event_id++;
        sprintf(buffer, "%d", event_id);
        strcpy(event.timestamp, buffer);
        strcpy(event.event_name, event_name);
        strcpy(event.event_details, event_details);
        log_event(event, &event_log);

        // Print the event that was just logged
        print_event(event);
    }

    // Print all events that were logged
    printf("\n--- All Events ---\n");
    print_all_events(event_log);

    return 0;
}

// Function to log an event
void log_event(Event event, EventLog *event_log) {
    // Add the event to the event log
    event_log->events[event_log->num_events] = event;
    event_log->num_events++;

    // If the event log is full, clear the oldest event
    if (event_log->num_events >= MAX_EVENTS) {
        event_log->num_events = 0;
    }
}

// Function to print all events in an event log
void print_all_events(EventLog event_log) {
    // Loop over every event in the event log and print it
    for (int i = 0; i < event_log.num_events; i++) {
        print_event(event_log.events[i]);
    }
}

// Function to print a single event
void print_event(Event event) {
    printf("Event ID: %d\n", event.id);
    printf("Timestamp: %s\n", event.timestamp);
    printf("Event Name: %s\n", event.event_name);
    printf("Event Details: %s\n", event.event_details);
    printf("\n");
}