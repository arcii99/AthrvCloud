//FormAI DATASET v1.0 Category: System event logger ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LOG_SIZE 100

typedef struct {
    time_t timestamp;
    char message[100];
} LogEntry;

LogEntry eventLogs[MAX_LOG_SIZE];
int currentLogSize = 0;

void logEvent(char message[100]) {
    if (currentLogSize >= MAX_LOG_SIZE) {
        printf("Error: Event log is full\n");
        return;
    }

    LogEntry newLog = {
        .timestamp = time(NULL),
    };

    sprintf(newLog.message, "%s", message);
    eventLogs[currentLogSize++] = newLog;

    printf("Event logged successfully\n");
}

void printEventLogs() {
    if (currentLogSize == 0) {
        printf("Event log is empty\n");
        return;
    }

    printf("Event Log\n");
    printf("Timestamp\tMessage\n");
    for (int i = 0; i < currentLogSize; i++) {
        LogEntry log = eventLogs[i];
        printf("%ld\t%s\n", log.timestamp, log.message);
    }
}

int main() {
    logEvent("Program started");
    logEvent("User input received");

    printEventLogs();

    return 0;
}