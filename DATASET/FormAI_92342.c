//FormAI DATASET v1.0 Category: Log analysis ; Style: realistic
#include <stdio.h>
#include <string.h>

#define LOGFILE "example.log" // Log file location

int main() {
    FILE *log_file;
    char log_line[200], sub_str[100];
    int error_count = 0, warning_count = 0, info_count = 0;

    log_file = fopen(LOGFILE, "r"); // Open log file for reading
    if (log_file == NULL) {
        printf("Error! Could not open log file.");
        return 1;
    }

    // Read log file line by line
    while (fgets(log_line, sizeof(log_line), log_file)) {
        if (strstr(log_line, "Error:")) { // Check for error level
            error_count++;
            sscanf(log_line, "%s %s", sub_str, sub_str); // Extract error message
            printf("Error: %s\n", sub_str);
        } else if (strstr(log_line, "Warning:")) { // Check for warning level
            warning_count++;
            sscanf(log_line, "%s %s", sub_str, sub_str); // Extract warning message
            printf("Warning: %s\n", sub_str);
        } else if (strstr(log_line, "Info:")) { // Check for info level
            info_count++;
            sscanf(log_line, "%s %s", sub_str, sub_str); // Extract info message
            printf("Info: %s\n", sub_str);
        }
    }

    printf("\nLog Analysis Results:\n");
    printf("Total Errors: %d\n", error_count);
    printf("Total Warnings: %d\n", warning_count);
    printf("Total Info: %d\n", info_count);

    fclose(log_file); // Close log file
    return 0;
}