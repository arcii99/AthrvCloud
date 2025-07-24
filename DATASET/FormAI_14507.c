//FormAI DATASET v1.0 Category: Log analysis ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

int main(int argc, char **argv) {

    // check if input file was provided
    if (argc < 2) {
        printf("Please provide input file as argument.");
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    char line[MAX_LINE_LENGTH];

    // check if file could be opened
    if (fp == NULL) {
        printf("Could not open file.");
        return 1;
    }

    int num_lines = 0;
    int num_info = 0;
    int num_warnings = 0;
    int num_errors = 0;
    int num_critical = 0;

    while (fgets(line, MAX_LINE_LENGTH, fp)) {
        num_lines++;

        // check for type of log message
        if (strstr(line, "INFO")) {
            num_info++;
        } else if (strstr(line, "WARNING")) {
            num_warnings++;
        } else if (strstr(line, "ERROR")) {
            num_errors++;
        } else if (strstr(line, "CRITICAL")) {
            num_critical++;
        }
    }

    // output log analysis results
    printf("Total number of log entries: %d\n", num_lines);
    printf("Number of INFO log entries: %d\n", num_info);
    printf("Number of WARNING log entries: %d\n", num_warnings);
    printf("Number of ERROR log entries: %d\n", num_errors);
    printf("Number of CRITICAL log entries: %d\n", num_critical);

    fclose(fp);
    return 0;
}