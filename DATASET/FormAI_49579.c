//FormAI DATASET v1.0 Category: System event logger ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to get current system time
void get_system_time(char *time_buffer) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(time_buffer, 30, "%Y-%m-%d %H:%M:%S", t);
}

int main() {
    FILE *logfile;
    char time_buffer[30];
    char event_string[100];

    // Open log file for writing in append mode
    logfile = fopen("system_events.log", "a");
    if (logfile == NULL) {
        printf("Error: Failed to open log file!\n");
        exit(1);
    }

    // Log system start event
    get_system_time(time_buffer);
    sprintf(event_string, "%s: System started.\n", time_buffer);
    fputs(event_string, logfile);

    // Run some system tasks...

    // Log system shutdown event
    get_system_time(time_buffer);
    sprintf(event_string, "%s: System shutting down.\n", time_buffer);
    fputs(event_string, logfile);

    // Close log file
    fclose(logfile);

    return 0;
}