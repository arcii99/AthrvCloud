//FormAI DATASET v1.0 Category: Log analysis ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: %s <logfile>\n", argv[0]);
        return 1;
    }

    FILE *log_file = fopen(argv[1], "r");
    if(log_file == NULL) {
        printf("Error opening logfile %s\n", argv[1]);
        return 1;
    }

    int num_warnings = 0;
    int num_errors = 0;
    int num_criticals = 0;
    int num_lines = 0;

    char line_buffer[MAX_LINE_LENGTH];
    while(fgets(line_buffer, MAX_LINE_LENGTH, log_file)) {
        num_lines++;

        if(strstr(line_buffer, "WARNING")) {
            num_warnings++;
            printf("WARNING: %s", line_buffer);
        }

        if(strstr(line_buffer, "ERROR")) {
            num_errors++;
            printf("ERROR: %s", line_buffer);
        }

        if(strstr(line_buffer, "CRITICAL")) {
            num_criticals++;
            printf("CRITICAL: %s", line_buffer);
        }
    }

    printf("Logfile analysis complete.\n");
    printf("Total number of lines: %d\n", num_lines);
    printf("Number of warnings: %d\n", num_warnings);
    printf("Number of errors: %d\n", num_errors);
    printf("Number of criticals: %d\n", num_criticals);

    fclose(log_file);
    return 0;
}