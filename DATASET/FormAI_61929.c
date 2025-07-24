//FormAI DATASET v1.0 Category: System event logger ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum {
    INFO,
    WARNING,
    ERROR
} LogType;

void log_event(char* message, LogType type) {
    time_t t = time(NULL);
    struct tm* time_info = localtime(&t);
    char* log_type;

    switch (type) {
        case INFO:
            log_type = "INFO";
            break;
        case WARNING:
            log_type = "WARNING";
            break;
        case ERROR:
            log_type = "ERROR";
            break;
        default:
            log_type = "";
            break;
    }

    printf("[%04d-%02d-%02d %02d:%02d:%02d] %s: %s\n", time_info->tm_year + 1900, time_info->tm_mon + 1,
           time_info->tm_mday, time_info->tm_hour, time_info->tm_min, time_info->tm_sec, log_type, message);
}

int main() {
    log_event("This is an example system event log message", INFO);
    log_event("This is a warning message", WARNING);
    log_event("This is an error message", ERROR);

    return EXIT_SUCCESS;
}