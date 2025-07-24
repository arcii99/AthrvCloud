//FormAI DATASET v1.0 Category: Log analysis ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    int line_count = 0;
    int error_count = 0;
    int warning_count = 0;
    int debug_count = 0;
    int other_count = 0;

    if (argc < 2) {
        printf("Usage: %s <logfile>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");

    if (fp == NULL) {
        perror("Error while opening the file.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)) {
        line_count++;

        if (strstr(line, "ERROR")) {
            error_count++;
        } else if (strstr(line, "WARNING")) {
            warning_count++;
        } else if (strstr(line, "DEBUG")) {
            debug_count++;
        } else {
            other_count++;
        }
    }

    printf("Total lines in the log file: %d\n", line_count);
    printf("Number of errors: %d\n", error_count);
    printf("Number of warnings: %d\n", warning_count);
    printf("Number of debug statements: %d\n", debug_count);
    printf("Number of other lines: %d\n", other_count);

    fclose(fp);
    return 0;
}