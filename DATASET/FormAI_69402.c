//FormAI DATASET v1.0 Category: System event logger ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate timestamp in a configurable style
char* get_timestamp(char* format) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char* timestamp = (char*) malloc(sizeof(char)*20);
    strftime(timestamp, 20, format, &tm);
    return timestamp;
}

int main() {
    // Configuration options
    char* log_file = "event.log";
    char* timestamp_format = "%Y-%m-%d %H:%M:%S";
    
    // Open log file in append mode
    FILE* log = fopen(log_file, "a");
    if (log == NULL) {
        printf("Error opening log file!\n");
        exit(1);
    }
    
    // Sample events to log
    char* event1 = "System started";
    char* event2 = "User logged in";
    char* event3 = "File saved successfully";
    
    // Log events with timestamp
    fprintf(log, "[%s] %s\n", get_timestamp(timestamp_format), event1);
    fprintf(log, "[%s] %s\n", get_timestamp(timestamp_format), event2);
    fprintf(log, "[%s] %s\n", get_timestamp(timestamp_format), event3);
    
    // Close log file
    fclose(log);
    
    return 0;
}