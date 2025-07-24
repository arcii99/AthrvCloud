//FormAI DATASET v1.0 Category: System event logger ; Style: retro
#include <stdio.h>
#include <time.h>

#define MAX_EVENTS 100 // maximum number of events allowed
#define MAX_EVENT_NAME_LENGTH 50 // maximum name length of one event
#define LOG_FILE_PATH "events.log" // file path to store event logs

struct Event {
    char name[MAX_EVENT_NAME_LENGTH];
    time_t timestamp;
};

int main() {
    struct Event events[MAX_EVENTS];
    int num_events = 0;

    FILE* log_file = fopen(LOG_FILE_PATH, "a");
    fprintf(log_file, "=== Event Logger started ===\n");
    fclose(log_file);

    printf("=== Retro Event Logger ===\n");
    printf("Enter 'q' to quit.\n");

    while (1) {
        char input[MAX_EVENT_NAME_LENGTH];
        printf("Enter event name: ");
        fgets(input, MAX_EVENT_NAME_LENGTH, stdin);

        if (input[0] == 'q') break; // exit loop
        
        time_t timestamp = time(NULL);

        struct Event event;
        for (int i = 0; i < MAX_EVENT_NAME_LENGTH; i++) {
            event.name[i] = input[i];
            if (input[i] == '\n') break;
        }
        event.timestamp = timestamp;
        events[num_events] = event;
        num_events++;

        log_file = fopen(LOG_FILE_PATH, "a");
        fprintf(log_file, "[%ld] %s", timestamp, event.name);
        fclose(log_file);

        printf("Event logged!\n");
    }

    log_file = fopen(LOG_FILE_PATH, "a");
    fprintf(log_file, "=== Event Logger ended ===\n\n");
    fclose(log_file);

    return 0;
}