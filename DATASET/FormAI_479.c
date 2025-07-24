//FormAI DATASET v1.0 Category: System event logger ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Define the event types */
enum EventType {
    INFO,
    WARNING,
    ERROR
};

/* Define the Event struct */
typedef struct {
    time_t timestamp;
    enum EventType type;
    char *description;
} Event;

/* Define the logger function */
void logEvent(Event event) {
    FILE *fp = fopen("eventlog.txt", "a");
    if (fp == NULL) {
        perror("Failed to open event log file");
        exit(EXIT_FAILURE);
    }

    /* Convert timestamp to string and write to file */
    char timestampString[20];
    strftime(timestampString, 20, "%Y-%m-%d %H:%M:%S", localtime(&event.timestamp));
    fprintf(fp, "[%s] ", timestampString);

    /* Write event type and description to file */
    switch (event.type) {
        case INFO:
            fprintf(fp, "[INFO] ");
            break;
        case WARNING:
            fprintf(fp, "[WARNING] ");
            break;
        case ERROR:
            fprintf(fp, "[ERROR] ");
            break;
    }
    fprintf(fp, "%s\n", event.description);

    fclose(fp);
}

int main() {
    /* Generate some example events */
    Event event1 = {
        time(NULL),
        INFO,
        "System started"
    };
    Event event2 = {
        time(NULL),
        WARNING,
        "Low disk space"
    };
    Event event3 = {
        time(NULL),
        ERROR,
        "Unable to connect to database"
    };

    /* Log the events */
    logEvent(event1);
    logEvent(event2);
    logEvent(event3);

    return 0;
}