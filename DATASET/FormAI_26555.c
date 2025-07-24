//FormAI DATASET v1.0 Category: System event logger ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char* event;
    time_t timestamp;
} Event;

Event* logs[1000];
int num_logs = 0;

void log_event(char* event) {
    Event* ev = (Event*) malloc(sizeof(Event));
    ev->timestamp = time(NULL);
    ev->event = event;
    logs[num_logs++] = ev;

    printf("\nEvent Logged: %s", ev->event);
}

void print_logs() {
    printf("\nEvent Logs:\n");
    for (int i=0; i<num_logs; i++) {
        printf("%d. %s - %s", i+1, logs[i]->event, ctime(&logs[i]->timestamp));
    }
}

int main() {
    log_event("System started");

    // TODO: simulate events
    // log_event(event_name);

    log_event("System stopped");
    print_logs();
    return 0;
}