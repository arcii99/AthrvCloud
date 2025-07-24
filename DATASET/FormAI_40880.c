//FormAI DATASET v1.0 Category: System event logger ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOGS 1000
#define MAX_LEN 200

struct Event {
    time_t timestamp;
    char message[MAX_LEN];
};

struct EventLog {
    struct Event events[MAX_LOGS];
    int num_events;
};

void add_event(struct EventLog *log, const char *message) {
    struct Event event;

    event.timestamp = time(NULL);
    strncpy(event.message, message, MAX_LEN-1);
    event.message[MAX_LEN-1] = '\0';

    log->events[log->num_events++] = event;

    if (log->num_events >= MAX_LOGS) {
        printf("Event log is full. Deleting oldest event.\n");
        for (int i = 1; i < MAX_LOGS; i++) {
            log->events[i-1] = log->events[i];
        }
        log->num_events--;
    }
}

void print_log(struct EventLog *log) {
    printf(" --- Event Log --- \n");
    for (int i = 0; i < log->num_events; i++) {
        struct Event event = log->events[i];
        char time_str[MAX_LEN];
        strftime(time_str, MAX_LEN, "%Y-%m-%d %H:%M:%S", localtime(&event.timestamp));

        printf("%s: %s\n", time_str, event.message);
    }
}

int main() {
    struct EventLog log = {0};
    char message[MAX_LEN];

    while (1) {
        printf("Enter event message (or \"q\" to quit): ");
        if (fgets(message, MAX_LEN, stdin) == NULL) {
            break;
        }
        if (message[0] == 'q') {
            break;
        }

        // Remove newline character
        char *newline_ptr = strchr(message, '\n');
        if (newline_ptr != NULL) {
            *newline_ptr = '\0';
        }

        add_event(&log, message);
        print_log(&log);
    }

    return 0;
}