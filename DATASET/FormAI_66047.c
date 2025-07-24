//FormAI DATASET v1.0 Category: System event logger ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENT_SIZE 50

typedef enum {
    INFO,
    WARNING,
    ERROR
} LogLevel;

typedef struct {
    LogLevel level;
    char timestamp[30];
    char event[MAX_EVENT_SIZE];
} LogEvent;

void log_event(LogLevel level, char *event) {
    LogEvent log_event;
    log_event.level = level;

    time_t current_time = time(NULL);
    struct tm *local_time = localtime(&current_time);
    strftime(log_event.timestamp, 30, "%Y-%m-%d %H:%M:%S", local_time);

    if (strlen(event) > MAX_EVENT_SIZE - 1) {
        event[MAX_EVENT_SIZE - 1] = '\0';
    }
    strcpy(log_event.event, event);

    // Open file in append mode and write log event
    FILE *file = fopen("log.txt", "a");
    fprintf(file, "[%s] %s: %s\n", log_event.timestamp, log_event.level == INFO ? "INFO" : log_event.level == WARNING ? "WARNING" : "ERROR", log_event.event);
    fclose(file);
}

int main() {
    log_event(INFO, "Application started");

    int x = 5;
    if (x > 10) {
        log_event(ERROR, "x is greater than 10");
    } else {
        log_event(INFO, "x is less than or equal to 10");
    }

    log_event(WARNING, "Memory usage is high");

    log_event(INFO, "Application ended");

    return 0;
}