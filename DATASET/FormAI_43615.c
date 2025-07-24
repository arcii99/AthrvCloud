//FormAI DATASET v1.0 Category: System event logger ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 500

struct Event {
    char *name;
    int hour;
    int minute;
};

void log_event(struct Event event, FILE *file) {
    fprintf(file, "The event for %s is set at %d:%02d.\n", event.name, event.hour, event.minute);
}

int main() {
    srand(time(NULL));

    FILE *log_file = fopen("system_events.txt", "w");

    if (!log_file) {
        fprintf(stderr, "Error: Unable to create log file.\n");
        return 1;
    }

    fprintf(log_file, "SYSTEM EVENT LOGGER\n");
    fprintf(log_file, "-------------------\n");

    struct Event events[MAX_EVENTS];

    for (int i = 0; i < MAX_EVENTS; i++) {
        events[i].hour = rand() % 24;
        events[i].minute = rand() % 60;

        switch (rand() % 5) {
            case 0:
                events[i].name = "The flying banana has landed";
                break;
            case 1:
                events[i].name = "The cats have taken over the internet";
                break;
            case 2:
                events[i].name = "The clouds are made of cotton candy";
                break;
            case 3:
                events[i].name = "The world has transformed into a giant avocado";
                break;
            case 4:
                events[i].name = "The universe is being run by sentient socks";
                break;
        }

        log_event(events[i], log_file);
    }

    fclose(log_file);

    printf("Events have been logged!\n");

    return 0;
}