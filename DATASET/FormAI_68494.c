//FormAI DATASET v1.0 Category: System event logger ; Style: mathematical
#include <stdio.h>
#include <time.h>

#define EVENT_STARTED 1
#define EVENT_INITIALIZED 2
#define EVENT_COMPLETED 3

typedef struct {
    int event_type;
    char *event_description;
    time_t event_time;
} system_event;

void log_system_event(system_event event) {
    FILE *fptr;
    fptr = fopen("system_events.log", "a+");
    if (fptr == NULL) {
        printf("Error: Could not open system_events.log file.");
        return;
    }
    fprintf(fptr, "Event Type: %d\nEvent Description: %s\nEvent Time: %s\n\n",
            event.event_type,
            event.event_description,
            ctime(&event.event_time));
    fclose(fptr);
}

int main() {
    system_event event1 = {
            EVENT_STARTED,
            "System started",
            time(NULL)
    };
    log_system_event(event1);
    
    // more events can be added here...
    
    system_event event2 = {
            EVENT_COMPLETED,
            "System completed",
            time(NULL)
    };
    log_system_event(event2);
    
    return 0;
}