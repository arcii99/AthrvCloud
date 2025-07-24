//FormAI DATASET v1.0 Category: System event logger ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 1000

struct event {
    int id;
    char description[50];
    time_t timestamp;
};

void log_event(struct event *events, int *num_events, char *description) {
    if (*num_events >= MAX_EVENTS) {
        printf("Error: maximum number of events exceeded\n");
        return;
    }
    struct event new_event;
    new_event.id = *num_events + 1;
    strcpy(new_event.description, description);
    new_event.timestamp = time(NULL);
    events[*num_events] = new_event;
    *num_events = *num_events + 1;
    printf("Event logged: %d %s\n", new_event.id, new_event.description);
}

void print_events(struct event *events, int num_events) {
    printf("ID\tTimestamp\tDescription\n");
    for (int i = 0; i < num_events; i++) {
        printf("%d\t%d\t%s", events[i].id, events[i].timestamp, events[i].description);
    }
}

int main() {
    struct event events[MAX_EVENTS];
    int num_events = 0;
    log_event(&events, &num_events, "System started");
    log_event(&events, &num_events, "Critical error occurred");
    log_event(&events, &num_events, "System recovered from error");
    print_events(&events, num_events);
    return 0;
}