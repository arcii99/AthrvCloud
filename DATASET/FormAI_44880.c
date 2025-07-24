//FormAI DATASET v1.0 Category: System event logger ; Style: retro
#include <stdio.h>
#include <time.h>

#define LOG_FILE "events.log"

void log_event(char *event_type, char *description) {
    FILE *log_file = fopen(LOG_FILE, "a"); // open log file in append mode
    if (log_file == NULL) {
        printf("Error opening log file.");
        return;
    }
    time_t now;
    time(&now);
    char *current_time = ctime(&now);
    current_time[strlen(current_time) - 1] = '\0'; // remove newline character from ctime output
    fprintf(log_file, "%s: %s - %s\n", current_time, event_type, description);
    fclose(log_file);
}

int main() {
    printf("Welcome to the Retro Event Logger!\n");

    // let's log some events
    log_event("INFO", "Program started");
    log_event("WARNING", "Low disk space");
    log_event("ERROR", "File not found");
    log_event("INFO", "Program terminated");

    return 0;
}