//FormAI DATASET v1.0 Category: System event logger ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void log_event(char *event_description) {
    // initialize time variables
    time_t current_time;
    struct tm *time_info;
    char time_string[9];
    char date_string[11];

    // obtain current time
    time(&current_time);
    time_info = localtime(&current_time);

    // format time
    strftime(time_string, sizeof(time_string), "%H:%M:%S", time_info);
    strftime(date_string, sizeof(date_string), "%Y-%m-%d", time_info);

    // open log file in append mode
    FILE *log_file = fopen("event_log.txt", "a");
    
    if (log_file == NULL) {
        printf("Error: Unable to open file.");
        return;
    }

    // write event description to log file
    fprintf(log_file, "[%s %s] %s\n", date_string, time_string, event_description);

    // close log file
    fclose(log_file);
}

int main() {
    // example of logging an event
    log_event("User John Doe logged in.");

    return 0;
}