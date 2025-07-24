//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_LINES 1000
#define MAX_LINE_LENGTH 200

int main() {
    char log_lines[MAX_LOG_LINES][MAX_LINE_LENGTH];
    int log_count = 0;

    // Load log file into memory
    FILE *fp = fopen("system.log", "r");
    if (fp == NULL) {
        printf("Error: Could not open log file\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        if (log_count >= MAX_LOG_LINES) {
            printf("Error: Log file too large\n");
            return 1;
        }

        // Copy line into buffer
        memcpy(log_lines[log_count], line, strlen(line));
        log_count++;
    }

    fclose(fp);

    // Analyze log file
    int warning_count = 0;
    for (int i = 0; i < log_count; i++) {
        char *line = log_lines[i];

        // Check for root login
        if (strstr(line, "root") != NULL && strstr(line, "login") != NULL) {
            printf("Warning: Root login detected in line %d\n", i+1);
            warning_count++;
        }

        // Check for failed login attempts
        if (strstr(line, "authentication failure") != NULL) {
            printf("Warning: Authentication failure detected in line %d\n", i+1);
            warning_count++;
        }

        // Check for sudo commands
        if (strstr(line, "sudo") != NULL) {
            printf("Warning: Sudo command detected in line %d\n", i+1);
            warning_count++;
        }
    }

    printf("%d warning(s) detected\n", warning_count);

    return 0;
}