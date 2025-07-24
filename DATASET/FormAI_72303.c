//FormAI DATASET v1.0 Category: System event logger ; Style: systematic
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void log_event(const char* event) {
    // Get current time
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    // Open file for appending
    FILE *file = fopen("events.log", "a");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Print event to file with timestamp
    fprintf(file, "%.2d/%.2d/%d %.2d:%.2d:%.2d - %s\n", tm->tm_mday, tm->tm_mon + 1, 
            tm->tm_year + 1900, tm->tm_hour, tm->tm_min, tm->tm_sec, event);

    // Close file
    fclose(file);
}

int main() {
    // Log some sample events
    log_event("Program started");
    log_event("User logged in");
    log_event("File saved successfully");

    return 0;
}