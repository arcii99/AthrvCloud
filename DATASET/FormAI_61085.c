//FormAI DATASET v1.0 Category: System event logger ; Style: single-threaded
#include <stdio.h>
#include <time.h>

#define MAX_EVENTS 1000

typedef enum {
    INFO,
    WARNING,
    ERROR
} EventLevel;

typedef struct {
    EventLevel level;
    time_t timestamp;
    char message[200];
} SystemEvent;

SystemEvent eventLog[MAX_EVENTS];
int eventCount = 0;

/**
 * Logs a system event
 * @param level The level of the event (INFO, WARNING, or ERROR)
 * @param message The message to log
 */
void logEvent(EventLevel level, char *message) {
    if (eventCount == MAX_EVENTS) {
        printf("Event log is full. Unable to log event: %s\n", message);
        return;
    }

    SystemEvent event;
    event.level = level;
    event.timestamp = time(NULL);
    strcpy(event.message, message);

    eventLog[eventCount++] = event;
}

/**
 * Prints all system events to the console
 */
void printEventLog() {
    printf("=== Event Log ===\n");

    for (int i = 0; i < eventCount; i++) {
        char levelString[8];

        switch (eventLog[i].level) {
            case INFO:
                strcpy(levelString, "INFO");
                break;
            case WARNING:
                strcpy(levelString, "WARNING");
                break;
            case ERROR:
                strcpy(levelString, "ERROR");
                break;
        }

        char timeString[20];
        strftime(timeString, sizeof timeString, "%Y-%m-%d %H:%M:%S", localtime(&eventLog[i].timestamp));

        printf("%s %s - %s\n", timeString, levelString, eventLog[i].message);
    }
}

int main() {
    // Log some events
    logEvent(INFO, "System started");
    logEvent(INFO, "User logged in");
    logEvent(ERROR, "File not found");
    logEvent(WARNING, "System running out of memory");
    logEvent(INFO, "System shutdown");

    // Print the event log
    printEventLog();

    return 0;
}