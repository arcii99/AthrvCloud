//FormAI DATASET v1.0 Category: Log analysis ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_LINES 1000
#define MAX_LOG_LINE_LENGTH 200

// Function to parse log lines and extract relevant information
void parse_log_line(char* line, char* timestamp, char* level, char* message) {
    // Extract timestamp
    char* token = strtok(line, " ");
    strcpy(timestamp, token);

    // Extract log level
    token = strtok(NULL, " ");
    strcpy(level, token);

    // Extract message
    token = strtok(NULL, "");
    strcpy(message, token);
}

int main() {
    // Open log file for reading
    FILE* file = fopen("example.log", "r");
    if (file == NULL) {
        printf("Error opening log file");
        return 1;
    }

    // Read log lines into array
    char log_lines[MAX_LOG_LINES][MAX_LOG_LINE_LENGTH];
    int num_lines = 0;
    while (fgets(log_lines[num_lines], MAX_LOG_LINE_LENGTH, file)) {
        num_lines++;
        if (num_lines == MAX_LOG_LINES) {
            break;
        }
    }

    // Close log file
    fclose(file);

    // Process log lines
    printf("Processing log file...\n");
    for (int i = 0; i < num_lines; i++) {
        char timestamp[MAX_LOG_LINE_LENGTH], level[MAX_LOG_LINE_LENGTH], message[MAX_LOG_LINE_LENGTH];
        parse_log_line(log_lines[i], timestamp, level, message);

        // Perform analysis on log entry
        // Example: print timestamp and message for error log entries
        if (strcmp(level, "ERROR") == 0) {
            printf("%s -- %s\n", timestamp, message);
        }
    }

    return 0;
}