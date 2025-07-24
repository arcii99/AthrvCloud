//FormAI DATASET v1.0 Category: System event logger ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define EVENT_TYPE_INFO 0
#define EVENT_TYPE_WARNING 1
#define EVENT_TYPE_ERROR 2

struct Event {
    int type;
    char *message;
    time_t timestamp;
};

void log_event(struct Event event) {
    char *type_str;
    switch (event.type) {
        case EVENT_TYPE_INFO:
            type_str = "INFO";
            break;
        case EVENT_TYPE_WARNING:
            type_str = "WARNING";
            break;
        case EVENT_TYPE_ERROR:
            type_str = "ERROR";
            break;
    }
    printf("[%s] %s (%s)\n", type_str, event.message, ctime(&event.timestamp));
}

int main() {
    struct Event events[10];
    int i = 0;

    // Generate some example events
    srand(time(NULL));
    for (i = 0; i < 10; i++) {
        struct Event event;
        event.timestamp = time(NULL);
        event.type = rand() % 3;
        switch (event.type) {
            case EVENT_TYPE_INFO:
                event.message = "System started up successfully";
                break;
            case EVENT_TYPE_WARNING:
                event.message = "Low disk space detected";
                break;
            case EVENT_TYPE_ERROR:
                event.message = "Critical system error, shutting down";
                break;
        }
        events[i] = event;
        usleep(1000); // Delay to ensure unique timestamps
    }

    // Log all events
    for (i = 0; i < 10; i++) {
        log_event(events[i]);
    }

    return 0;
}