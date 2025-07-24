//FormAI DATASET v1.0 Category: Log analysis ; Style: visionary
#include <stdio.h>
#include <string.h>

#define MAX_LOG_LINES 1000
#define MAX_LOG_LINE_LENGTH 500

int main() {
    FILE* log_file = fopen("server_logs.txt", "r");
    if (log_file == NULL) {
        printf("Error: Could not open log file.\n");
        return 1;
    }

    char log_lines[MAX_LOG_LINES][MAX_LOG_LINE_LENGTH];
    char input_buffer[MAX_LOG_LINE_LENGTH];
    int line_count = 0;

    // Read log lines into memory
    while (fgets(input_buffer, MAX_LOG_LINE_LENGTH, log_file) != NULL) {
        if (line_count >= MAX_LOG_LINES) {
            printf("Error: Log file exceeds maximum size.\n");
            break;
        }
        strncpy(log_lines[line_count], input_buffer, MAX_LOG_LINE_LENGTH);
        line_count++;
    }

    // Analyze log lines
    int get_requests = 0;
    int post_requests = 0;
    int errors = 0;

    for (int i = 0; i < line_count; i++) {
        if (strstr(log_lines[i], "GET") != NULL) {
            get_requests++;
        }
        else if (strstr(log_lines[i], "POST") != NULL) {
            post_requests++;
        }
        else if (strstr(log_lines[i], "ERROR") != NULL) {
            errors++;
        }
    }

    printf("Log analysis summary:\n");
    printf("  Total lines: %d\n", line_count);
    printf("  GET requests: %d\n", get_requests);
    printf("  POST requests: %d\n", post_requests);
    printf("  Errors: %d\n", errors);

    fclose(log_file);
    return 0;
}