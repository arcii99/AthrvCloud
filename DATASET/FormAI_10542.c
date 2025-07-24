//FormAI DATASET v1.0 Category: System event logger ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define MAX_EVENTS 1000

struct Event {
    char name[50];
    char datetime[20];
};

struct EventLogger {
    struct Event events[MAX_EVENTS];
    int num_events;
};

void log_event(struct EventLogger *logger, char *name, char *datetime) {
    if (logger->num_events >= MAX_EVENTS) {
        printf("Error: event logger is full\n");
        return;
    }
    struct Event new_event;
    strcpy(new_event.name, name);
    strcpy(new_event.datetime, datetime);
    logger->events[logger->num_events] = new_event;
    logger->num_events++;
    printf("Event logged: %s at %s\n", name, datetime);
}

void print_events(struct EventLogger *logger) {
    printf("Event log:\n");
    for (int i = 0; i < logger->num_events; i++) {
        printf("%s at %s\n", logger->events[i].name, logger->events[i].datetime);
    }
}

int main() {
    struct EventLogger logger = {0};
    printf("Event Logger\n");
    printf("============\n\n");
    while (1) {
        printf("Enter event name: ");
        char event_name[50];
        fgets(event_name, 50, stdin);
        event_name[strcspn(event_name, "\n")] = 0;
        if (strcmp(event_name, "quit") == 0) {
            break;
        }
        printf("Enter event date and time (YYYY-MM-DD HH:MM:SS): ");
        char event_datetime[20];
        fgets(event_datetime, 20, stdin);
        event_datetime[strcspn(event_datetime, "\n")] = 0;
        log_event(&logger, event_name, event_datetime);
    }
    print_events(&logger);
    return 0;
}