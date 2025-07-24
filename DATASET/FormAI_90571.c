//FormAI DATASET v1.0 Category: System event logger ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EVENTS 1000
#define MAX_EVENT_NAME_LEN 30
#define MAX_EVENT_INFO_LEN 100

typedef struct EventStruct {
    char name[MAX_EVENT_NAME_LEN];
    char info[MAX_EVENT_INFO_LEN];
    time_t timestamp;
} Event;

int num_events = 0;
Event events[MAX_EVENTS];

void log_event(char* name, char* info) {
    if(num_events >= MAX_EVENTS) {
        printf("Event buffer full, cannot log event!");
        return;
    }
    
    Event new_event;
    strncpy(new_event.name, name, MAX_EVENT_NAME_LEN);
    strncpy(new_event.info, info, MAX_EVENT_INFO_LEN);
    new_event.timestamp = time(NULL);
    
    events[num_events] = new_event;
    num_events++;
}

void print_events() {
    printf("Event Log:\n");
    for(int i = 0; i < num_events; i++) {
        printf("Event %d: %s - %s at %s", i+1, events[i].name, events[i].info, ctime(&events[i].timestamp));
    }
}

int main() {
    printf("Welcome to the Happy Event Logger!\n");
    printf("------------------------\n");
    
    log_event("System Start", "The system has started successfully.");
    log_event("User Login", "User 'happyuser' has logged in.");
    
    printf("Events logged!\n");
    printf("------------------------\n");
    
    print_events();
    
    return 0;
}