//FormAI DATASET v1.0 Category: Log analysis ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 256
#define MAX_NUM_LINES 10000

int main(int argc, char *argv[]) {
    
    char *log_filename = argv[1];
    
    FILE *log_file = fopen(log_filename, "r");
    if (log_file == NULL) {
        fprintf(stderr, "ERROR: Could not open log file %s\n", log_filename);
        exit(1);
    }
    
    char line_buffer[MAX_LINE_LEN];
    char log_lines[MAX_NUM_LINES][MAX_LINE_LEN];
    int num_lines = 0;
    
    while (fgets(line_buffer, MAX_LINE_LEN, log_file) != NULL) {
        if (num_lines < MAX_NUM_LINES) {
            strncpy(log_lines[num_lines], line_buffer, MAX_LINE_LEN);
            num_lines++;
        }
    }
    
    fclose(log_file);
    
    int num_failures = 0;
    int num_successes = 0;
    int num_warnings = 0;
    
    for (int i = 0; i < num_lines; i++) {
        if (strstr(log_lines[i], "FAILED")) {
            num_failures++;
        } else if (strstr(log_lines[i], "WARNING")) {
            num_warnings++;
        } else {
            num_successes++;
        }
    }
    
    printf("LOG FILE ANALYSIS:\n");
    printf("Total lines: %d\n", num_lines);
    printf("Number of failures: %d\n", num_failures);
    printf("Number of warnings: %d\n", num_warnings);
    printf("Number of successes: %d\n", num_successes);
    
    return 0;
}