//FormAI DATASET v1.0 Category: System event logger ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void log_event(char* event_type, char* message) {
    // Get current time
    time_t current_time;
    time(&current_time);
    char timestamp[30];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", localtime(&current_time));

    // Open log file for writing
    FILE *log_file = fopen("system_events.log", "a");
    if (log_file == NULL) {
        printf("Failed to open log file!\n");
        exit(1);
    }

    // Write log message to file
    fprintf(log_file, "[%s] %s: %s\n", timestamp, event_type, message);
    fclose(log_file);
}

int main() {
    char* event_types[] = {"INFO", "WARNING", "ERROR"};
    char* messages[] = {"System started.", "Disk space low.", "Segmentation fault."};
    int i;

    // Log some random events
    for (i = 0; i < 10; i++) {
        int event_type_index = rand() % 3;
        int message_index = rand() % 3;
        log_event(event_types[event_type_index], messages[message_index]);
    }

    return 0;
}