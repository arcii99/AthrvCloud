//FormAI DATASET v1.0 Category: Log analysis ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOG_PATH "example.log" // Change this to the path of your log file

int main()
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    FILE *log_file = fopen(LOG_PATH, "r");
    if (!log_file) {
        printf("Unable to open log file\n");
        exit(EXIT_FAILURE);
    }

    int info_count = 0;
    int warning_count = 0;
    int error_count = 0;

    while ((read = getline(&line, &len, log_file)) != -1) {
        if (strstr(line, "[INFO]")) {
            info_count++;
        }
        else if (strstr(line, "[WARNING]")) {
            warning_count++;
        }
        else if (strstr(line, "[ERROR]")) {
            error_count++;
            printf("Error found: %s", line); // Prints the line with the error
        }
    }

    printf("Number of info messages: %d\n", info_count);
    printf("Number of warning messages: %d\n", warning_count);
    printf("Number of error messages: %d\n", error_count);

    fclose(log_file);
    if (line) {
        free(line);
    }

    return 0;
}