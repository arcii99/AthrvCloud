//FormAI DATASET v1.0 Category: Log analysis ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOG_FILENAME "example.log"

int main()
{
    FILE *log;
    log = fopen(LOG_FILENAME, "r");

    if (log == NULL) {
        printf("Unable to open log file %s\n", LOG_FILENAME);
        exit(EXIT_FAILURE);
    }

    char buffer[1024];
    int line_count = 0;
    int error_count = 0;
    int warning_count = 0;
    int info_count = 0;

    while(fgets(buffer, sizeof(buffer), log)) {
        line_count++;
        char *type = strtok(buffer, ":");
        char *message = strtok(NULL, "\n");

        if (strcmp(type, "[ERROR]") == 0) {
            error_count++;
            printf("Error #%d on line %d: %s\n", error_count, line_count, message);
        } else if (strcmp(type, "[WARNING]") == 0) {
            warning_count++;
            printf("Warning #%d on line %d: %s\n", warning_count, line_count, message);
        } else if (strcmp(type, "[INFO]") == 0) {
            info_count++;
            printf("Info #%d on line %d: %s\n", info_count, line_count, message);
        } else {
            printf("Unknown log type on line %d: %s\n", line_count, message);
        }
    }

    printf("Parsed %d lines:\n", line_count);
    printf("  - %d errors\n", error_count);
    printf("  - %d warnings\n", warning_count);
    printf("  - %d info messages\n", info_count);

    fclose(log);
    return 0;
}