//FormAI DATASET v1.0 Category: System event logger ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EVENTS 100

struct SystemEvent {
    int id;
    char *event_message;
    time_t timestamp;
};

struct EventLog {
    int event_count;
    struct SystemEvent events[MAX_EVENTS];
};

void log_event(char *message, struct EventLog *log) {
    if (log->event_count < MAX_EVENTS) {
        struct SystemEvent new_event;
        new_event.id = log->event_count + 1;
        new_event.event_message = message;
        new_event.timestamp = time(NULL);
        log->events[log->event_count] = new_event;
        log->event_count++;
        printf("Event logged: %s\n", message);
    } else {
        printf("Event log full, cannot log event: %s\n", message);
    }
}

void print_logs(struct EventLog log) {
    printf("Event logs:\n");
    for (int i = 0; i < log.event_count; i++) {
        printf("Event %d: %s (%s)", log.events[i].id, log.events[i].event_message, ctime(&log.events[i].timestamp));
    }
}

int main() {
    struct EventLog log;
    log.event_count = 0;
    char input[100];
    char *message;
    int running = 1;

    while (running) {
        printf("Enter an event message to log (or 'exit' to quit):\n");
        fgets(input, 100, stdin);
        input[strcspn(input, "\n")] = 0; // remove newline character
        
        if (!strcmp(input, "exit")) {
            running = 0;
        } else {
            message = strdup(input); // allocate memory for input string
            log_event(message, &log);
            free(message); // free memory after adding to log
        }
    }

    print_logs(log);
    return 0;
}