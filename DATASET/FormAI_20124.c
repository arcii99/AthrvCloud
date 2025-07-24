//FormAI DATASET v1.0 Category: Log analysis ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

void print_error(char *message, int line_num) {
    fprintf(stderr, "Error in line %d: %s\n", line_num, message);
}

void log_analysis(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file '%s'\n", filename);
        return;
    }

    char line[MAX_LINE_LENGTH];
    int line_num = 0;
    int num_warnings = 0;
    int num_errors = 0;

    while (fgets(line, MAX_LINE_LENGTH, file)) {
        line_num++;
        if (strstr(line, "WARNING") != NULL) {
            num_warnings++;
            printf("Line %d: %s", line_num, line);
        } else if (strstr(line, "ERROR") != NULL) {
            num_errors++;
            print_error(line, line_num);
        }
    }

    printf("Log analysis complete. Found %d warnings and %d errors.\n", num_warnings, num_errors);

    fclose(file);
}

int main() {
    char *filename = "example.log";
    log_analysis(filename);
    return 0;
}