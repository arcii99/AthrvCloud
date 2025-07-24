//FormAI DATASET v1.0 Category: Log analysis ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_SIZE 1000

int main(void) {
    FILE *log_file;
    char log_line[MAX_LOG_SIZE];
    int error_count = 0, warning_count = 0, info_count = 0;

    log_file = fopen("example.log", "r");

    if (log_file == NULL) {
        fprintf(stderr, "Error: cannot open log file\n");
        exit(EXIT_FAILURE);
    }

    while (fgets(log_line, MAX_LOG_SIZE, log_file) != NULL) {
        if (strstr(log_line, "ERROR") != NULL) {
            error_count++;
            printf("%s", log_line);
        } else if (strstr(log_line, "WARNING") != NULL) {
            warning_count++;
        } else if (strstr(log_line, "INFO") != NULL) {
            info_count++;
        }
    }

    printf("\n\nLog analysis summary:\n\n");
    printf("Total errors: %d\n", error_count);
    printf("Total warnings: %d\n", warning_count);
    printf("Total info messages: %d\n", info_count);

    fclose(log_file);

    return 0;
}