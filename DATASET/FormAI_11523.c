//FormAI DATASET v1.0 Category: Log analysis ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    FILE *file;
    char line[100];
    int num_lines = 0, num_errors = 0, num_warnings = 0;
    float error_percent, warning_percent;

    file = fopen("log_file.txt", "r");

    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    // Count number of lines, errors, and warnings
    while (fgets(line, sizeof(line), file)) {
        num_lines++;
        if (strstr(line, "ERROR")) {
            num_errors++;
        } else if (strstr(line, "WARNING")) {
            num_warnings++;
        }
    }

    // Calculate percentage of errors and warnings
    error_percent = ((float)num_errors / num_lines) * 100;
    warning_percent = ((float)num_warnings / num_lines) * 100;

    printf("LOG ANALYSIS REPORT:\n");
    printf("--------------------\n\n");
    printf("TOTAL LINES: %d\n", num_lines);
    printf("ERRORS: %d (%.2f%%)\n", num_errors, error_percent);
    printf("WARNINGS: %d (%.2f%%)\n\n", num_warnings, warning_percent);

    // Print out top 5 most common error messages
    char *error_messages[num_errors];
    int error_counts[num_errors];
    int unique_errors = 0;

    rewind(file);

    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "ERROR")) {
            // Extract the error message text
            char *error_text = line + 6;
            error_text[strlen(error_text)-1] = '\0';

            // Check if this error message has already been identified
            int i;
            for (i = 0; i < unique_errors; i++) {
                if (strcmp(error_messages[i], error_text) == 0) {
                    // Increment error count
                    error_counts[i]++;
                    break;
                }
            }

            // If error message is unique, add it to the list
            if (i == unique_errors) {
                error_messages[unique_errors] = strdup(error_text);
                error_counts[unique_errors] = 1;
                unique_errors++;
            }
        }
    }

    printf("TOP 5 MOST COMMON ERRORS:\n");
    printf("-------------------------\n\n");

    // Print out the top 5 most common errors
    int j, k;
    for (j = 0; j < 5; j++) {
        int max_count = 0, max_index = 0;
        for (k = 0; k < unique_errors; k++) {
            if (error_counts[k] > max_count) {
                max_count = error_counts[k];
                max_index = k;
            }
        }

        if (max_count > 0) {
            printf("%d. %s (%d occurrences)\n", j+1, error_messages[max_index], max_count);
            error_counts[max_index] = 0; // Set to zero so it is not counted again
        } else {
            break;
        }
    }

    fclose(file);

    return 0;

}