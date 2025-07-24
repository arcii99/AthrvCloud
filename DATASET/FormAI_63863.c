//FormAI DATASET v1.0 Category: System event logger ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 100

typedef enum {
    SUCCESS,
    FAILURE,
    WARNING
} EventStatus;

typedef struct {
    time_t timestamp;
    char* description;
    EventStatus status;
} Event;

void log_event(Event* event) {
    FILE *fp;
    fp = fopen("system_log.txt", "a");

    if(fp == NULL) {
        printf("Error opening file\n");
        return;
    }

    char* status_str;
    switch(event->status) {
        case SUCCESS:
            status_str = "SUCCESS";
            break;
        case FAILURE:
            status_str = "FAILURE";
            break;
        case WARNING:
            status_str = "WARNING";
            break;
        default:
            status_str = "UNKNOWN";
            break;
    }

    fprintf(fp, "%ld %s %s\n", event->timestamp, event->description, status_str);
    fclose(fp);
}

int main() {
    Event system_events[MAX_EVENTS];

    // Sample events
    Event event1 = {time(NULL), "System started", SUCCESS};
    Event event2 = {time(NULL), "Database connection failed", FAILURE};
    Event event3 = {time(NULL), "CPU overheating", WARNING};

    system_events[0] = event1;
    system_events[1] = event2;
    system_events[2] = event3;

    for(int i=0; i<3; i++) {
        log_event(&system_events[i]);
    }

    printf("Events logged successfully!\n");

    return 0;
}