//FormAI DATASET v1.0 Category: Log analysis ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_LINES 1000
#define MAX_LOG_LINE_SIZE 1000

int main() {
    char log_lines[MAX_LOG_LINES][MAX_LOG_LINE_SIZE];
    int num_log_lines = 0;

    // Read in log file
    FILE *fp;
    fp = fopen("logfile.txt", "r");
    if (fp == NULL) {
        printf("Failed to open log file!\n");
        return 1;
    }

    while(fgets(log_lines[num_log_lines], MAX_LOG_LINE_SIZE, fp) != NULL) {
        num_log_lines++;
        if (num_log_lines >= MAX_LOG_LINES) {
            printf("Reached max number of log lines!\n");
            break;
        }
    }

    fclose(fp);

    // Analyze log file
    int num_errors = 0;
    int num_warnings = 0;

    for (int i=0; i<num_log_lines; i++) {
        if (strstr(log_lines[i], "ERROR") != NULL) {
            num_errors++;
        } else if (strstr(log_lines[i], "WARN") != NULL) {
            num_warnings++;
        }
    }

    // Output analysis results
    printf("\n=============== Log Analysis Results ===============\n");
    printf("Total Number of Log Lines: %d\n", num_log_lines);
    printf("Number of Errors: %d\n", num_errors);
    printf("Number of Warnings: %d\n", num_warnings);
    printf("\n====================================================\n");

    return 0;
}