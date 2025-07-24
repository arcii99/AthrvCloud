//FormAI DATASET v1.0 Category: Log analysis ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_LOG_LINES 1000
#define MAX_LINE_LENGTH 100

int main()
{
    FILE *logfile;
    char *filename = "example.log";
    char line[MAX_LINE_LENGTH];
    int line_count = 0;
    int i, j;

    int error_count = 0;
    int warning_count = 0;
    int info_count = 0;

    char *error = "ERROR";
    char *warning = "WARNING";
    char *info = "INFO";

    char *severity = "";

    int error_codes[MAX_LOG_LINES];
    int error_lines[MAX_LOG_LINES];
    int error_code_count = 0;

    logfile = fopen(filename, "r");

    if (logfile == NULL) {
        fprintf(stderr, "Error: Unable to open file '%s'\n", filename);
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, logfile) != NULL) {
        line_count++;

        if (line[0] == '\n')
            continue;

        if (strstr(line, error)) {
            severity = error;
            error_count++;
            error_codes[error_code_count] = atoi(line + strlen(error) + 1);
            error_lines[error_code_count] = line_count;
            error_code_count++;
        }
        else if (strstr(line, warning))
            severity = warning;
        else
            severity = info;

        printf("Line: %d - Severity: %s - Message: %s", line_count, severity, line);
    }

    printf("\n");

    printf("========= SUMMARY =========\n");
    printf("Error count: %d\n", error_count);
    printf("Warning count: %d\n", warning_count);
    printf("Info count: %d\n", info_count);

    printf("\n");

    printf("========= ERROR CODES =========\n");
    for (i = 0; i < error_code_count; i++) {
        printf("Error code: %d - Line: %d\n", error_codes[i], error_lines[i]);
    }

    fclose(logfile);

    return 0;
}