//FormAI DATASET v1.0 Category: System event logger ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void log_event(FILE *file, const char *event) {
    time_t current_time;
    char *time_string;

    // Get the current time
    current_time = time(NULL);
    time_string = ctime(&current_time);
    time_string[strlen(time_string) - 1] = '\0'; // Remove newline character

    // Write the event to the log file
    fprintf(file, "[%s] %s\n", time_string, event);
    fflush(file); // Flush the output stream to ensure the log is written to disk immediately
}

int main() {
    FILE *file;
    char filename[] = "events.log";

    // Open the log file for writing
    file = fopen(filename, "a");
    if (file == NULL) {
        fprintf(stderr, "Failed to open log file '%s'\n", filename);
        exit(EXIT_FAILURE);
    }

    // Log some events
    log_event(file, "System started");
    log_event(file, "Database connection established");
    log_event(file, "User login successful");

    // Close the log file
    fclose(file);

    return 0;
}