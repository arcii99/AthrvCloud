//FormAI DATASET v1.0 Category: Log analysis ; Style: curious
#include <stdio.h>

int main() {
    printf("Welcome to the curious C Log analysis program!\n");
    printf("This program will analyze a log file and provide curious statistics!\n");

    FILE *log_file = fopen("example_log.txt", "r"); // Open log file
    if (log_file == NULL) { // Check if file exists
        printf("Could not open log file. Please make sure example_log.txt exists.\n");
        return 1;
    }

    int total_lines = 0;
    int error_count = 0;
    int warning_count = 0;
    int info_count = 0;
    int debug_count = 0;

    char buffer[256];
    while (fgets(buffer, 256, log_file)) { // Read each line of log file
        total_lines++;

        // Check the log level of the current line
        char *log_level = strtok(buffer, " ");
        if (log_level == NULL) continue; // No log level found, skip line
        if (strcmp(log_level, "ERROR") == 0) {
            error_count++;
        } else if (strcmp(log_level, "WARNING") == 0) {
            warning_count++;
        } else if (strcmp(log_level, "INFO") == 0) {
            info_count++;
        } else if (strcmp(log_level, "DEBUG") == 0) {
            debug_count++;
        }
    }

    fclose(log_file); // Close log file

    printf("\nCurious statistics:\n");
    printf("Total lines in log file: %d\n", total_lines);
    printf("Lines with ERROR level: %d (%.2f%%)\n", error_count, ((double)error_count/total_lines)*100);
    printf("Lines with WARNING level: %d (%.2f%%)\n", warning_count, ((double)warning_count/total_lines)*100);
    printf("Lines with INFO level: %d (%.2f%%)\n", info_count, ((double)info_count/total_lines)*100);
    printf("Lines with DEBUG level: %d (%.2f%%)\n", debug_count, ((double)debug_count/total_lines)*100);

    printf("\nThank you for using the curious C Log analysis program!\n");

    return 0;
}