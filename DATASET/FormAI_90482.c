//FormAI DATASET v1.0 Category: System event logger ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void logEvent(char* event) {
    time_t current_time;
    char* c_time_string;

    current_time = time(NULL);
    c_time_string = ctime(&current_time);

    // Remove newline character from c_time_string
    char* newline_pos = strchr(c_time_string, '\n');
    if (newline_pos != NULL) {
        *newline_pos = '\0';
    }

    // Write event and timestamp to log file
    FILE* logfile = fopen("event.log", "a");
    if (logfile == NULL) {
        printf("Error: could not open log file.\n");
        return;
    }

    fprintf(logfile, "%s: %s\n", c_time_string, event);
    fclose(logfile);

    printf("Event logged: %s\n", event);
}

int main() {
    // Log some events
    logEvent("Program started");
    logEvent("Event 1 occurred");
    logEvent("Event 2 occurred");
    logEvent("Program ended");

    return 0;
}