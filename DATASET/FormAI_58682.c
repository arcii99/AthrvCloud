//FormAI DATASET v1.0 Category: System event logger ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

FILE *log_file;

void log_event(char *event) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    fprintf(log_file, "[%d-%02d-%02d %02d:%02d:%02d] %s\n",
            tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
            tm.tm_hour, tm.tm_min, tm.tm_sec, event);
}

int main() {
    log_file = fopen("event_log.txt", "a");
    if (log_file == NULL) {
        printf("Error: Failed to open event log file.");
        exit(EXIT_FAILURE);
    }

    // Log some events
    log_event("Started program");
    int x = 10;
    int y = 5;
    log_event("Initialized variables");

    if (x > y) {
        log_event("X is greater than Y");
    } else {
        log_event("Y is greater than or equal to X");
    }

    log_event("Exiting program");
    fclose(log_file);

    return 0;
}