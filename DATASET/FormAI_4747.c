//FormAI DATASET v1.0 Category: Log analysis ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char *log_file_path;
    if (argc > 1) {
        log_file_path = argv[1];
    } else {
        log_file_path = "/var/log/syslog";
    }
    FILE *log_file = fopen(log_file_path, "r");
    if (log_file == NULL) {
        fprintf(stderr, "Failed to open log file: %s\n", log_file_path);
        exit(1);
    }
    char buffer[1024];
    int line_count = 0;
    int error_count = 0;
    int critical_error_count = 0;
    while (fgets(buffer, sizeof(buffer), log_file)) {
        line_count++;
        if (strstr(buffer, "ERROR")) {
            error_count++;
            if (strstr(buffer, "CRITICAL")) {
                critical_error_count++;
            }
        }
    }
    fclose(log_file);
    printf("Log file analysis for %s:\n", log_file_path);
    printf("%d lines analyzed.\n", line_count);
    printf("%d errors found.\n", error_count);
    if (critical_error_count > 0) {
        printf("%d critical errors found.\n", critical_error_count);
    }
    return 0;
}