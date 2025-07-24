//FormAI DATASET v1.0 Category: System event logger ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void log_event(char* event_type, char* message);

int main() {
    printf("Welcome to the Event Logger Program!\n");

    // simulate some events
    log_event("INFO", "User logged in successfully");
    log_event("WARNING", "Disk space is low");
    log_event("ERROR", "Database connection lost");
    log_event("INFO", "New user registered");

    printf("Thanks for using the Event Logger Program!\n");
    return 0;
}

void log_event(char* event_type, char* message) {
    // get current time
    time_t current_time = time(NULL);
    char* time_string = ctime(&current_time);

    // remove newline character from time string
    time_string[strlen(time_string) - 1] = '\0';

    // open log file in append mode
    FILE* log_file = fopen("event_log.txt", "a");
    if (log_file == NULL) {
        printf("Error opening log file!\n");
        return;
    }

    // write event to log file
    fprintf(log_file, "[%s] %s: %s\n", time_string, event_type, message);

    // close log file
    fclose(log_file);
}