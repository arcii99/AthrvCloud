//FormAI DATASET v1.0 Category: System event logger ; Style: relaxed
#include <stdio.h>
#include <time.h>

int main() {
    // Open a file for logging
    FILE *log_file = fopen("events.log", "a");

    // Get current time
    time_t current_time = time(NULL);
    struct tm *time_info = localtime(&current_time);
    char time_str[20];
    strftime(time_str, 20, "%Y-%m-%d %H:%M:%S", time_info);

    // Log an event
    char event_str[] = "System started";
    fprintf(log_file, "[%s] %s\n", time_str, event_str);

    // Update time and log another event
    current_time = time(NULL);
    time_info = localtime(&current_time);
    strftime(time_str, 20, "%Y-%m-%d %H:%M:%S", time_info);
    char another_event_str[] = "User logged in";
    fprintf(log_file, "[%s] %s\n", time_str, another_event_str);

    // Close the log file
    fclose(log_file);

    return 0;
}