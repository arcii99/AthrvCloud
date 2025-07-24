//FormAI DATASET v1.0 Category: Log analysis ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 250
#define LOG_FILE_PATH "path/to/logfile.txt"

int main(void) {
    FILE *log_file;
    char log_line[MAX_LINE_LENGTH];
    int line_count = 0, error_count = 0, warning_count = 0, info_count = 0;

    log_file = fopen(LOG_FILE_PATH, "r");
    if (log_file == NULL) {
        printf("Error opening log file.\n");
        exit(1);
    }

    printf("LOG ANALYSIS REPORT\n");
    printf("-------------------\n");

    while (fgets(log_line, MAX_LINE_LENGTH, log_file) != NULL) {
        line_count++;

        if (strstr(log_line, "ERROR") != NULL) {
            error_count++;
            printf("Line %d: %s", line_count, log_line);
        } else if (strstr(log_line, "WARNING") != NULL) {
            warning_count++;
        } else if (strstr(log_line, "INFO") != NULL) {
            info_count++;
        }
    }

    printf("-------------------\n");
    printf("Total number of lines: %d\n", line_count);
    printf("Number of ERROR lines: %d\n", error_count);
    printf("Number of WARNING lines: %d\n", warning_count);
    printf("Number of INFO lines: %d\n", info_count);

    fclose(log_file);

    return 0;
}