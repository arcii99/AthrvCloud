//FormAI DATASET v1.0 Category: Log analysis ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LENGTH 1000
#define KEYWORD "ERROR"

int main(void) {
    FILE *fp;
    char line[LINE_LENGTH];
    int line_number = 0;
    int error_count = 0;
    int total_lines = 0;
    float error_percentage;

    fp = fopen("log_file.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open log file.\n");
        return 1;
    }

    while (fgets(line, LINE_LENGTH, fp)) {
        total_lines++;
        if (strstr(line, KEYWORD)) {
            error_count++;
            printf("Line %d: %s", line_number, line);
        }
    }

    if (total_lines == 0) {
        printf("Error: Log file is empty.\n");
        return 1;
    }

    error_percentage = ((float) error_count / total_lines) * 100;

    printf("\nTotal lines: %d\n", total_lines);
    printf("Error count: %d\n", error_count);
    printf("Error percentage: %.2f%%\n", error_percentage);

    fclose(fp);

    return 0;
}