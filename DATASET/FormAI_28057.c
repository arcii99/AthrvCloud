//FormAI DATASET v1.0 Category: Log analysis ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    FILE *logfile;
    char line_buf[512], *match;
    int i, line_count = 0, error_count = 0, warning_count = 0;

    if (argc != 2) {
        printf("Usage: %s <log file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    logfile = fopen(argv[1], "r");
    if (!logfile) {
        perror("Error opening logfile");
        exit(EXIT_FAILURE);
    }

    while (fgets(line_buf, sizeof(line_buf), logfile)) {
        if ((match = strstr(line_buf, "ERROR"))) {
            printf("Error found on line %d: %s", line_count + 1, line_buf);
            error_count++;
        }
        if ((match = strstr(line_buf, "WARNING"))) {
            printf("Warning found on line %d: %s", line_count + 1, line_buf);
            warning_count++;
        }
        line_count++;
    }

    printf("Total errors: %d\n", error_count);
    printf("Total warnings: %d\n", warning_count);

    fclose(logfile);
    return 0;
}