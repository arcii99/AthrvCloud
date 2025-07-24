//FormAI DATASET v1.0 Category: System event logger ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void log_event(char *event_type, char *message) {
    FILE *log_file;
    time_t current_time;

    // Open the log file in append mode
    log_file = fopen("event.log", "a");

    // Get the current time and format it
    time(&current_time);
    char timestamp[20];
    strftime(timestamp, 20, "%Y-%m-%d %H:%M:%S", localtime(&current_time));

    // Write the event details to the log file
    fprintf(log_file, "[%s] %s: %s\n", timestamp, event_type, message);

    // Close the log file
    fclose(log_file);
}

int main() {
    // Generate some sample events for testing
    log_event("INFO", "Program started");
    log_event("WARNING", "Resource usage approaching limit");
    log_event("ERROR", "Unable to open file");

    return 0;
}