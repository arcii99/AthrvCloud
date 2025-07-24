//FormAI DATASET v1.0 Category: System event logger ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declarations
void log_event(char* event_message, char* filename);
void print_log_entries(char* filename);

int main() {
    // Get current time
    time_t current_time;
    char* c_time_string;
    current_time = time(NULL);
    c_time_string = ctime(&current_time);

    // Log events
    log_event("System started.", "event_log.txt");
    log_event("User logged in.", "event_log.txt");
    log_event("File saved successfully.", "event_log.txt");
    log_event("Program terminated.", "event_log.txt");

    // Print log entries
    print_log_entries("event_log.txt");

    return 0;
}

// Function to log an event
void log_event(char* event_message, char* filename) {
    // Get current time
    time_t current_time;
    char* c_time_string;
    current_time = time(NULL);
    c_time_string = ctime(&current_time);

    // Open log file in append mode
    FILE *fp;
    fp = fopen(filename, "a");
    if (fp == NULL) {
        printf("Error opening log file.");
        exit(1);
    }

    // Write log entry to file
    fprintf(fp, "%s %s\n", c_time_string, event_message);

    // Close log file
    fclose(fp);

    // Print success message
    printf("Event logged successfully.\n");
}

// Function to print log entries
void print_log_entries(char* filename) {
    // Open log file in read mode
    FILE *fp;
    char c;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening log file.");
        exit(1);
    }

    // Read and display log entries
    printf("Log entries:\n");
    while ((c = getc(fp)) != EOF) {
        printf("%c", c);
    }

    // Close log file
    fclose(fp);
}