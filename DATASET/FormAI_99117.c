//FormAI DATASET v1.0 Category: Log analysis ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX_LOG_ENTRIES 10000 // Maximum number of log entries to read
#define MAX_LOG_LINE_LENGTH 200 // Maximum length of log line

// Struct to hold a log entry
typedef struct {
    long timestamp; // Unix timestamp of log entry
    char *message; // Log message
} log_entry;

// Helper function to parse log line into a log entry
log_entry parse_log_line(char *line) {
    char *timestamp_str = strtok(line, " "); // Get timestamp string
    long timestamp = atol(timestamp_str); // Convert string to long integer
    char *message = strtok(NULL, ""); // Get log message
    log_entry entry = {timestamp, message}; // Create log entry struct
    return entry;
}

int main(int argc, char **argv) {
    if (argc != 2) { // Check for correct number of arguments
        printf("Usage: log_analysis <log_file>\n");
        exit(1);
    }

    char *log_file = argv[1];
    FILE *file = fopen(log_file, "r");
    char line[MAX_LOG_LINE_LENGTH]; // Buffer for reading log lines
    int num_entries = 0; // Counter for number of log entries read
    log_entry entries[MAX_LOG_ENTRIES];

    if (file) { // File opened successfully
        while (fgets(line, MAX_LOG_LINE_LENGTH, file) != NULL && num_entries < MAX_LOG_ENTRIES) {
            entries[num_entries] = parse_log_line(line); // Parse log line and store in array
            num_entries++;
        }
        fclose(file); // Close file
    }

    // Print out log entries
    for (int i = 0; i < num_entries; i++) {
        printf("%ld: %s", entries[i].timestamp, entries[i].message);
    }

    return 0;
}