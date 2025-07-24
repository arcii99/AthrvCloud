//FormAI DATASET v1.0 Category: Log analysis ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

int main(int argc, char *argv[]) {
    // Ensure log file is passed as argument
    if (argc < 2) {
        printf("Please provide the name of the log file as an argument.\n");
        return 1;
    }

    // Open the log file
    char *filename = argv[1];
    FILE *log_file = fopen(filename, "r");
    if (log_file == NULL) {
        printf("Unable to open the log file.\n");
        return 1;
    }

    // Declare variables to hold log analysis data
    int error_count = 0;
    int warning_count = 0;
    char *most_common_error = NULL;
    int most_common_error_count = 0;

    // Process each line of the log file
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, log_file) != NULL) {
        // Determine log type (error, warning, or other)
        char *log_type = NULL;
        char *error_start = strstr(line, "ERROR:");
        char *warning_start = strstr(line, "WARNING:");
        if (error_start != NULL) {
            log_type = "error";
        } else if (warning_start != NULL) {
            log_type = "warning";
        } else {
            // Skip non-error/non-warning lines
            continue;
        }

        // Increment appropriate count
        if (strcmp(log_type, "error") == 0) {
            error_count++;

            // Extract error message and update most_common_error if applicable
            char *error_message_start = error_start + strlen("ERROR:");
            char *error_message_end = strstr(error_message_start, "\n");
            int error_message_length = error_message_end - error_message_start;
            char error_message[error_message_length + 1];
            strncpy(error_message, error_message_start, error_message_length);
            error_message[error_message_length] = '\0';

            // Check if new most common error
            if (most_common_error == NULL || strcmp(most_common_error, error_message) != 0) {
                int error_message_count = 1;
                char *next_line_start = ftell(log_file);
                while (fgets(line, MAX_LINE_LENGTH, log_file) != NULL) {
                    if (strstr(line, error_message_start) != NULL) {
                        error_message_count++;
                    } else {
                        break;
                    }
                }
                if (error_message_count > most_common_error_count) {
                    most_common_error = realloc(most_common_error, strlen(error_message) + 1);
                    strcpy(most_common_error, error_message);
                    most_common_error_count = error_message_count;
                }
                fseek(log_file, next_line_start, SEEK_SET);
            }
        } else {
            warning_count++;
        }
    }

    // Print log analysis data
    printf("Log analysis for file %s:\n", filename);
    printf("Number of errors: %d\n", error_count);
    printf("Number of warnings: %d\n", warning_count);
    if (most_common_error != NULL) {
        printf("Most common error: %s (Occurred %d times)\n", most_common_error, most_common_error_count);
    }

    // Clean up allocated memory
    if (most_common_error != NULL) {
        free(most_common_error);
    }
    fclose(log_file);

    return 0;
}