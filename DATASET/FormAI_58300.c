//FormAI DATASET v1.0 Category: Log analysis ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

int main(int argc, char* argv[]) {
    // Check command line arguments
    if (argc != 2) {
        printf("Usage: log_analysis <path to log file>\n");
        return 1;
    }
    
    // Open log file
    FILE* log_file = fopen(argv[1], "r");
    if (!log_file) {
        printf("Error: could not open log file\n");
        return 1;
    }
    
    // Initialize counters
    int debug_count = 0;
    int info_count = 0;
    int warning_count = 0;
    int error_count = 0;
    int critical_count = 0;
    
    // Read log file line by line
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, log_file)) {
        // Parse log level from line
        char* level_str = strtok(line, " ");
        if (!level_str) {
            continue; // Ignore empty lines
        }
        int level = -1;
        if (strcmp(level_str, "DEBUG") == 0) {
            level = 0;
        } else if (strcmp(level_str, "INFO") == 0) {
            level = 1;
        } else if (strcmp(level_str, "WARNING") == 0) {
            level = 2;
        } else if (strcmp(level_str, "ERROR") == 0) {
            level = 3;
        } else if (strcmp(level_str, "CRITICAL") == 0) {
            level = 4;
        } else {
            continue; // Ignore unknown log levels
        }
        
        // Update counter for log level
        switch (level) {
            case 0:
                debug_count++;
                break;
            case 1:
                info_count++;
                break;
            case 2:
                warning_count++;
                break;
            case 3:
                error_count++;
                break;
            case 4:
                critical_count++;
                break;
        }
        
        // Display updated counters
        printf("\rDEBUG: %d, INFO: %d, WARNING: %d, ERROR: %d, CRITICAL: %d",
               debug_count, info_count, warning_count, error_count, critical_count);
        fflush(stdout);
    }
    
    // Close log file
    fclose(log_file);
    
    // Display final counters
    printf("\nFinal count: DEBUG: %d, INFO: %d, WARNING: %d, ERROR: %d, CRITICAL: %d\n",
           debug_count, info_count, warning_count, error_count, critical_count);
    
    return 0;
}