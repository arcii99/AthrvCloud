//FormAI DATASET v1.0 Category: System event logger ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void log_event(char *event, char *log_file) {
    FILE *fp;
    time_t current_time;
    struct tm * time_info;
    char time_string[30];

    // Get current time
    current_time = time(NULL);
    time_info = localtime(&current_time);

    // Format time string
    strftime(time_string, sizeof(time_string), "%Y-%m-%d %H:%M:%S", time_info);

    // Open log file for append
    fp = fopen(log_file, "a");

    if (fp == NULL) {
        fprintf(stderr, "Could not open log file for writing!\n");
        exit(EXIT_FAILURE);
    }

    // Write event to log file
    fprintf(fp, "[%s] %s\n", time_string, event);

    // Close log file
    fclose(fp);
}

int main() {
    char event[100];
    char log_file[100];

    printf("Enter event to log: ");
    fgets(event, sizeof(event), stdin);
    event[strcspn(event, "\n")] = 0; // remove newline character from input

    printf("Enter log file path: ");
    fgets(log_file, sizeof(log_file), stdin);
    log_file[strcspn(log_file, "\n")] = 0; // remove newline character from input

    log_event(event, log_file);

    printf("Event logged successfully!\n");

    return 0;
}