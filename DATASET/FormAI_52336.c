//FormAI DATASET v1.0 Category: System event logger ; Style: relaxed
#include <stdio.h>
#include <time.h>

int main() {
    // Get the current time
    time_t now = time(0);
    char* timestamp = ctime(&now); // Convert the time to a string
    timestamp[strlen(timestamp)-1] = '\0'; // Remove the newline at the end
    
    // Open the log file
    FILE* log_file = fopen("system_events.log", "a");
    if (log_file == NULL) {
        printf("Error: Could not open log file.\n");
        return 1;
    }
    
    // Log a system event with a timestamp
    fprintf(log_file, "[%s] System event: %s.\n", timestamp, "System start-up");
    
    // Close the log file
    fclose(log_file);

    return 0;
}