//FormAI DATASET v1.0 Category: System event logger ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void log_event(char *event_type, char *description) {
    // Get current time
    time_t current_time;
    time(&current_time);
    
    // Open log file in append mode
    FILE *log_file;
    log_file = fopen("system_events.log", "a");
    
    // Write event to log file in format "[timestamp] event_type: description"
    fprintf(log_file, "[%s] %s: %s\n", ctime(&current_time), event_type, description);
    
    // Close log file
    fclose(log_file);   
}

int main() {
    // Simulate system events
    log_event("INFO", "System started");
    log_event("ERROR", "Disk space running low");
    log_event("WARNING", "CPU temperature too high");
    log_event("INFO", "System shut down");
    
    return 0;
}