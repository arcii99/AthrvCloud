//FormAI DATASET v1.0 Category: System event logger ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to log system events
void logEvent(char* event) {
    time_t current_time = time(NULL);
    struct tm* formatted_time = localtime(&current_time);
    char timestamp[25];
    strftime(timestamp, 25, "%Y-%m-%d %H:%M:%S", formatted_time);

    FILE* log_file = fopen("system_events.log", "a");
    if (log_file == NULL) {
        printf("Error: Could not open log file.\n");
        exit(1);
    }

    fprintf(log_file, "[%s] %s\n", timestamp, event);
    fclose(log_file);
}

int main() {
    // Example usage
    char event1[] = "System boot";
    char event2[] = "User login failure: Incorrect password";
    char event3[] = "User account locked out due to too many login attempts";

    logEvent(event1);
    logEvent(event2);
    logEvent(event3);

    return 0;
}