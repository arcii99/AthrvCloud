//FormAI DATASET v1.0 Category: System event logger ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 1000

typedef struct {
    time_t timestamp;
    char* message;
} Event;

Event events[MAX_EVENTS];
int num_events = 0;

void log_event(char* message) {
    if (num_events >= MAX_EVENTS) {
        printf("Maximum number of events reached\n");
        return;
    }
    Event new_event;
    new_event.timestamp = time(NULL);
    new_event.message = message;
    events[num_events++] = new_event;
}

void print_events() {
    for (int i = 0; i < num_events; i++) {
        printf("%ld - %s\n", events[i].timestamp, events[i].message);
    }
}

int main() {
    log_event("System started");
    log_event("File created successfully");
    log_event("Access denied for user 'guest'");
    print_events();
    return 0;
}