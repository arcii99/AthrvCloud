//FormAI DATASET v1.0 Category: Log analysis ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: log_analysis filename\n");
        exit(1);
    }

    int num_lines = 0;
    int num_errors = 0;

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    char *error_string = "Error";

    while (fgets(line, sizeof(line), fp)) {
        num_lines++;

        if (strstr(line, error_string)) {
            num_errors++;
        }
    }

    fclose(fp);

    printf("Log analysis of file: %s\n", argv[1]);
    printf("Number of lines: %d\n", num_lines);
    printf("Number of errors: %d\n", num_errors);
    printf("Error rate: %.2f%%\n", (float)num_errors / num_lines * 100);

    return 0;
}