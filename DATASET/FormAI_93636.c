//FormAI DATASET v1.0 Category: System event logger ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void log_event(char* event_type, char* message);

int main() {
    // Example usage of log_event function
    log_event("WARNING", "Temperature sensor reading too high.");

    return 0;
}

void log_event(char* event_type, char* message) {
    // Get current time
    time_t current_time;
    time(&current_time);

    // Open log file
    FILE* log_file = fopen("systemlog.txt", "a");
    if (log_file == NULL) {
        printf("Error: Could not open log file.\n");
        exit(1);
    }

    // Write log entry
    fprintf(log_file, "[%s]: %s - %s\n", event_type, message, ctime(&current_time));

    // Close log file
    fclose(log_file);
}