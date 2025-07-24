//FormAI DATASET v1.0 Category: System event logger ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define EVENT_LOG_FILE_PATH "/var/log/system_event.log"

void log_event(char *event_name, char *description) {

    time_t current_time = time(NULL);
    char *timestamp = ctime(&current_time);

    // Open the log file for appending
    FILE *logfile = fopen(EVENT_LOG_FILE_PATH, "a");

    if(logfile == NULL) {
        fprintf(stderr, "Error opening log file: %s\n", EVENT_LOG_FILE_PATH);
        exit(EXIT_FAILURE);
    }

    fprintf(logfile, "[%s] %s: %s\n", timestamp, event_name, description);
    fclose(logfile);
}

int main(){

    // Simulate some system events
    log_event("Status", "System has started.");
    sleep(2);
    log_event("Error", "Unable to connect to database.");
    sleep(1);
    log_event("Warning", "Disk space is low.");
    sleep(3);
    log_event("Status", "All systems are functioning normally.");

    return 0;
}