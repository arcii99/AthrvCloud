//FormAI DATASET v1.0 Category: System event logger ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

// Define constants
#define MAX_EVENTS 100
#define MAX_EVENT_MSG_SIZE 256

// Define data structures
typedef struct {
    time_t timestamp;
    char event_msg[MAX_EVENT_MSG_SIZE];
} Event;

typedef struct {
    Event events[MAX_EVENTS];
    int num_events;
} EventLog;

// Define function prototypes
void log_event(EventLog *log, const char *msg);
void *log_event_async(void *args);

int main() {
    // Initialize the event log
    EventLog log;
    log.num_events = 0;

    // Create the logging thread
    pthread_t logging_thread;
    pthread_create(&logging_thread, NULL, log_event_async, (void *) &log);

    // Generate some test events
    log_event(&log, "Test event 1");
    log_event(&log, "Test event 2");
    log_event(&log, "Test event 3");

    // Wait for the logging thread to finish
    pthread_join(logging_thread, NULL);

    // Print out all of the events that were logged
    printf("===== Event Log =====\n");
    for (int i = 0; i < log.num_events; i++) {
        printf("[%ld] %s\n", log.events[i].timestamp, log.events[i].event_msg);
    }

    return 0;
}

void log_event(EventLog *log, const char *msg) {
    time_t timestamp = time(NULL);
    if (log->num_events < MAX_EVENTS) {
        Event *event = &log->events[log->num_events++];
        event->timestamp = timestamp;
        strncpy(event->event_msg, msg, MAX_EVENT_MSG_SIZE);
    } else {
        fprintf(stderr, "Error: event log is full\n");
    }
}

void *log_event_async(void *args) {
    EventLog *log = (EventLog *) args;

    while (log->num_events < MAX_EVENTS) {
        // Sleep for a random amount of time
        int sleep_millis = rand() % 1000;
        struct timespec sleep_spec;
        sleep_spec.tv_sec = sleep_millis / 1000;
        sleep_spec.tv_nsec = (sleep_millis % 1000) * 1000000;
        nanosleep(&sleep_spec, NULL);

        // Generate a random event message
        char event_msg[MAX_EVENT_MSG_SIZE];
        sprintf(event_msg, "Async event %d", log->num_events + 1);

        // Log the event
        log_event(log, event_msg);
    }

    pthread_exit(NULL);
}