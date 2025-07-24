//FormAI DATASET v1.0 Category: Log analysis ; Style: relaxed
#include <stdio.h>
#include <string.h>

#define MAX_LOG_LINE_SIZE 1024

int main(int argc, char *argv[]) {
    char *log_filename = argv[1];
    FILE *log_file = fopen(log_filename, "r");
    if (!log_file) {
        printf("Could not open log file %s\n", log_filename);
        return 1;
    }

    // Initialize counters
    int total_lines = 0;
    int error_count = 0;

    // Read log file line by line
    char line[MAX_LOG_LINE_SIZE];
    while (fgets(line, MAX_LOG_LINE_SIZE, log_file) != NULL) {
        total_lines++;

        // Check for error messages
        char *error_string = "ERROR";
        if (strstr(line, error_string) != NULL) {
            error_count++;
        }
    }

    // Print summary statistics
    printf("Total log lines: %d\n", total_lines);
    printf("Error count: %d\n", error_count);

    // Close log file
    fclose(log_file);

    return 0;
}