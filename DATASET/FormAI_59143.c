//FormAI DATASET v1.0 Category: System event logger ; Style: statistical
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_EVENTS 1000

struct event {
    time_t timestamp;
    char message[100];
};

struct log {
    int event_count;
    struct event events[MAX_EVENTS];
};

struct log system_log;

void log_event(char *message) {
    if (system_log.event_count == MAX_EVENTS) {
        printf("System log is full.\n");
        return;
    }

    time_t t = time(NULL);
    struct event e = {t, message};
    system_log.events[system_log.event_count++] = e;
}

void print_log_statistics() {
    printf("Number of events logged: %d\n", system_log.event_count);

    time_t t = time(NULL);
    int last_hour_count = 0, last_day_count = 0;

    for (int i = 0; i < system_log.event_count; i++) {
        double seconds_diff = difftime(t, system_log.events[i].timestamp);
        if (seconds_diff < 3600) {
            last_hour_count++;
        }
        if (seconds_diff < 86400) {
            last_day_count++;
        }
    }

    printf("Number of events logged in the last hour: %d\n", last_hour_count);
    printf("Number of events logged in the last day: %d\n", last_day_count);

    printf("Random event from the log:\n");
    int random_index = rand() % system_log.event_count;
    printf("%s\n", system_log.events[random_index].message);
}

int main() {
    log_event("System started.");
    log_event("User logged in.");
    log_event("User created new file.");
    log_event("User deleted old file.");
    log_event("System shut down.");

    print_log_statistics();

    return 0;
}