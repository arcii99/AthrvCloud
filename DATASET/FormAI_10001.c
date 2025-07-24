//FormAI DATASET v1.0 Category: System event logger ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void log_event(char* event) {
    time_t current_time;
    char* time_string;

    current_time = time(NULL);
    time_string = ctime(&current_time);

    // Remove trailing newline character from time string
    time_string[strlen(time_string) - 1] = '\0';

    // Open log file in append mode
    FILE* log_file = fopen("event.log", "a");

    // Print the current time and event to the log file
    fprintf(log_file, "%s - %s\n", time_string, event);

    // Close the log file
    fclose(log_file);
}

int main() {
    // Log some example events
    log_event("System started");
    log_event("User logged in");
    log_event("System shutdown initiated");

    return 0;
}