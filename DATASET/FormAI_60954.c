//FormAI DATASET v1.0 Category: System event logger ; Style: rigorous
#include <stdio.h>
#include <time.h> // For time functions

// Function to log events
void log_event(char* event, char* source) {
    // Get current time
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    
    // Open log file in append mode
    FILE* log_file = fopen("system_events.log", "a");
    
    // Write event details to log file
    fprintf(log_file, "[%d-%02d-%02d %02d:%02d:%02d] %s: %s\n", 
            tm.tm_year+1900, tm.tm_mon+1, tm.tm_mday,
            tm.tm_hour, tm.tm_min, tm.tm_sec,
            source, event);
    
    // Close log file
    fclose(log_file);
}

// Example usage
int main() {
    // Log an event
    log_event("System started", "Main");
    
    // Perform some task and log another event
    int x = 5;
    int y = 10;
    int z = x + y;
    log_event("Task completed successfully", "Main");
    
    // Log an error event
    float a = 0;
    float b = 10;
    if (a == 0) {
        log_event("Error: Division by zero", "Main");
    }
    
    return 0;
}