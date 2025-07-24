//FormAI DATASET v1.0 Category: Log analysis ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[])
{
    // Check arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s logfile\n", argv[0]);
        return 1;
    }

    // Open log file
    FILE *log_file = fopen(argv[1], "r");
    if (!log_file) {
        perror("Failed to open logfile");
        return 1;
    }

    // Initialize counters
    int total_lines = 0;
    int error_lines = 0;
    int warning_lines = 0;

    // Read log file line by line
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, log_file)) {
        total_lines++;

        // Check if line contains "error" or "warning"
        if (strstr(line, "error")) {
            error_lines++;
        } else if (strstr(line, "warning")) {
            warning_lines++;
        }
    }

    // Calculate percentages
    double error_percent = (double)error_lines / total_lines * 100.0;
    double warning_percent = (double)warning_lines / total_lines * 100.0;
    double other_percent = 100.0 - error_percent - warning_percent;

    // Print results
    printf("Log analysis results:\n");
    printf("Total lines: %d\n", total_lines);
    printf("Error lines: %d (%.2f%%)\n", error_lines, error_percent);
    printf("Warning lines: %d (%.2f%%)\n", warning_lines, warning_percent);
    printf("Other lines: %d (%.2f%%)\n", total_lines - error_lines - warning_lines, other_percent);

    // Close log file
    fclose(log_file);

    return 0;
}