//FormAI DATASET v1.0 Category: System event logger ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EVENTS 100
#define MAX_EVENT_NAME 50

typedef struct {
    char event_name[MAX_EVENT_NAME]; // name of the event
    time_t event_time; // time when the event occurred
} system_event;

system_event event_log[MAX_EVENTS]; // array to store system events
int event_count = 0; // total number of events stored in the log

void log_event(char* event_name) {
    if (event_count >= MAX_EVENTS) {
        printf("Error: Event log is full\n");
        return;
    }
    strcpy(event_log[event_count].event_name, event_name);
    event_log[event_count].event_time = time(NULL);
    event_count++;
    printf("Event logged: %s\n", event_name);
}

void print_events() {
    printf("Event Log:\n");
    for (int i=0; i<event_count; i++) {
        char* event_time_str = ctime(&event_log[i].event_time);
        event_time_str[strlen(event_time_str)-1] = '\0'; // remove the newline character from the end
        printf("%s - %s\n", event_time_str, event_log[i].event_name);
    }
}

int main() {
    log_event("System started");
    log_event("User logged in");
    log_event("File opened");
    log_event("File saved");
    print_events();
    return 0;
}