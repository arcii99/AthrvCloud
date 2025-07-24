//FormAI DATASET v1.0 Category: Log analysis ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 10000 // set the limit of log lines
#define MAX_LEN 1000    // set the limit of log length

int main(int argc, char *argv[]) {
    FILE *log_file;
    char log_line[MAX_LEN];
    char *log_lines[MAX_LINES];
    int line_count = 0;

    if (argc != 2) {
        printf("Usage: %s <log file>\n", argv[0]);
        return 1;
    }

    log_file = fopen(argv[1], "r");
    if (log_file == NULL) {
        printf("Error: could not open file %s\n", argv[1]);
        return 1;
    }

    // read all log lines into an array
    while (fgets(log_line, MAX_LEN, log_file) != NULL) {
        log_lines[line_count++] = strdup(log_line);
        if (line_count >= MAX_LINES) {
            printf("Warning: reached maximum number of lines\n");
            break;
        }
    }

    fclose(log_file);

    // count the number of occurrences of each log level
    int debug_count = 0, info_count = 0, warn_count = 0, error_count = 0;
    for (int i = 0; i < line_count; i++) {
        if (strstr(log_lines[i], "[DEBUG]")) {
            debug_count++;
        } else if (strstr(log_lines[i], "[INFO]")) {
            info_count++;
        } else if (strstr(log_lines[i], "[WARN]")) {
            warn_count++;
        } else if (strstr(log_lines[i], "[ERROR]")) {
            error_count++;
        }
    }

    // print the results
    printf("Debug: %d\n", debug_count);
    printf("Info: %d\n", info_count);
    printf("Warn: %d\n", warn_count);
    printf("Error: %d\n", error_count);

    // free memory
    for (int i = 0; i < line_count; i++) {
        free(log_lines[i]);
    }

    return 0;
}