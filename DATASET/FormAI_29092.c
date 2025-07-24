//FormAI DATASET v1.0 Category: System event logger ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the Event struct with timestamp and event message
struct Event {
    time_t time;
    char* message;
};

// Define the Logger struct with array of events and index
struct Logger {
    struct Event events[100];
    int index;
};

// Function to create a new Event with current timestamp and message
struct Event create_event(char* message) {
    struct Event event;
    event.time = time(NULL);
    event.message = message;
    return event;
}

// Function to add an Event to the Logger
void log_event(struct Logger* logger, struct Event event) {
    if (logger->index < 100) {
        logger->events[logger->index++] = event;
    } else {
        printf("Logger is full!");
    }
}

// Function to print all Events in the Logger
void print_events(struct Logger logger) {
    for (int i = 0; i < logger.index; i++) {
        struct Event event = logger.events[i];
        printf("%ld: %s\n", event.time, event.message);
    }
}

int main() {
    // Create a new Logger and add some Events
    struct Logger logger;
    logger.index = 0;
    log_event(&logger, create_event("System started."));
    log_event(&logger, create_event("File read error."));
    log_event(&logger, create_event("User logged in."));

    // Print the Events in the Logger
    print_events(logger);

    return 0;
}