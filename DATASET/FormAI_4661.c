//FormAI DATASET v1.0 Category: Log analysis ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {

    // Check command line arguments
    if (argc != 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        return 1;
    }

    // Open log file
    FILE *log_file = fopen(argv[1], "r");
    if (log_file == NULL) {
        printf("Error: Could not open file '%s'\n", argv[1]);
        return 1;
    }

    // Count lines in log file
    int line_count = 0;
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, log_file)) {
        line_count++;
    }

    // Create array to hold log entries
    struct LogEntry {
        char date[11];
        char time[9];
        char level[6];
        char message[MAX_LINE_LENGTH];
    } log_entries[line_count];

    // Reset file position indicator
    fseek(log_file, 0, SEEK_SET);

    // Read log entries from file into array
    int i = 0;
    while (fgets(line, MAX_LINE_LENGTH, log_file)) {
        sscanf(line, "%10s %8s %5s - %1024[^\n]", log_entries[i].date, log_entries[i].time, log_entries[i].level, log_entries[i].message);
        i++;
    }

    // Close log file
    fclose(log_file);

    // Count log entries by level
    int debug_count = 0, info_count = 0, warn_count = 0, error_count = 0;
    for (int i = 0; i < line_count; i++) {
        if (strcmp(log_entries[i].level, "DEBUG") == 0) {
            debug_count++;
        } else if (strcmp(log_entries[i].level, "INFO") == 0) {
            info_count++;
        } else if (strcmp(log_entries[i].level, "WARN") == 0) {
            warn_count++;
        } else if (strcmp(log_entries[i].level, "ERROR") == 0) {
            error_count++;
        }
    }

    // Print log entry statistics
    printf("Log file: %s\n", argv[1]);
    printf("Number of lines: %d\n", line_count);
    printf("DEBUG: %d\n", debug_count);
    printf("INFO: %d\n", info_count);
    printf("WARN: %d\n", warn_count);
    printf("ERROR: %d\n", error_count);

    return 0;
}