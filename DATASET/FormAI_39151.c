//FormAI DATASET v1.0 Category: System event logger ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Data structure to represent an event */
typedef struct {
    time_t timestamp;
    char* message;
} Event;

/* Function to recursively print all events from the given time */
void print_events(Event** events, int n, time_t start_time) {
    if (n == 0) {
        return;
    }
    Event* event = events[n-1];
    if (event->timestamp >= start_time) {
        print_events(events, n-1, start_time);
        printf("%ld: %s\n", event->timestamp, event->message);
    }
}

int main() {
    /* Create an array of events */
    Event* events[5];
    for (int i = 0; i < 5; i++) {
        events[i] = malloc(sizeof(Event));
        events[i]->timestamp = time(NULL) + i * 60;  // Events are 1 minute apart
        events[i]->message = malloc(20*sizeof(char));
        sprintf(events[i]->message, "Event %d", i+1);
    }

    /* Print all events */
    printf("All events:\n");
    print_events(events, 5, 0);

    /* Print events from the last minute */
    printf("\nEvents in the last minute:\n");
    print_events(events, 5, time(NULL)-60);

    /* Free memory */
    for (int i = 0; i < 5; i++) {
        free(events[i]->message);
        free(events[i]);
    }
    return 0;
}