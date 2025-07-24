//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_CHARS_PER_LINE 100

int main() {
    char lines[MAX_LINES][MAX_CHARS_PER_LINE];
    int num_lines = 0;

    // Read input from stdin
    char line[MAX_CHARS_PER_LINE];
    while (fgets(line, MAX_CHARS_PER_LINE, stdin)) {
        strcpy(lines[num_lines], line);
        num_lines++;
    }

    // Multivariable intrusion detection system
    int alert_level = 0;
    char* prev_line = NULL;
    char* prev_prev_line = NULL;
    for (int i = 0; i < num_lines; i++) {
        char* cur_line = lines[i];
        int num_keywords = 0;

        // Check for keywords
        if (strstr(cur_line, "hack") != NULL) {
            num_keywords++;
        }
        if (strstr(cur_line, "attack") != NULL) {
            num_keywords++;
        }
        if (strstr(cur_line, "security breach") != NULL) {
            num_keywords++;
        }

        // Check for patterns
        if (num_keywords >= 2) {
            alert_level = 3;
        } else if (num_keywords == 1 && prev_line != NULL &&
                   strstr(prev_line, "system") != NULL) {
            alert_level = 2;
        } else if (num_keywords == 1 && prev_line != NULL &&
                   prev_prev_line != NULL &&
                   strstr(prev_line, "system") != NULL &&
                   strstr(prev_prev_line, "security") != NULL) {
            alert_level = 2;
        } else if (num_keywords == 1 && prev_prev_line != NULL &&
                   strstr(prev_prev_line, "security") != NULL) {
            alert_level = 1;
        }

        // Print alerts
        if (alert_level == 3) {
            printf("ALERT: Multiple security keywords detected on line %d\n", i+1);
        } else if (alert_level == 2) {
            printf("ALERT: Potential security breach detected on line %d\n", i+1);
        } else if (alert_level == 1) {
            printf("ALERT: Suspicious activity detected on line %d\n", i+1);
        }

        // Update previous lines
        prev_prev_line = prev_line;
        prev_line = cur_line;
    }

    return 0;
}