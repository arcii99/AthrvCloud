//FormAI DATASET v1.0 Category: Log analysis ; Style: peaceful
#include <stdio.h>
#include <string.h>

int main() {
    char log[] = "2022-01-01 10:30:25 ERROR: Could not connect to database\n2022-01-01 10:31:15 WARNING: User attempted to login with incorrect credentials\n2022-01-01 10:31:30 INFO: Server is up and running\n2022-01-01 10:32:45 DEBUG: Query returned 0 results\n";
    char *p = strtok(log, "\n");
    int error_count = 0;
    int warning_count = 0;
    int info_count = 0;
    int debug_count = 0;
    int total_count = 0;

    while (p != NULL) {
        char *q = strstr(p, ": ");
        char *r = q + 2;

        if (strncmp(p, "ERROR", strlen("ERROR")) == 0) {
            printf("[ERROR] %s\n", r);
            error_count++;
            total_count++;
        } else if (strncmp(p, "WARNING", strlen("WARNING")) == 0) {
            printf("[WARNING] %s\n", r);
            warning_count++;
            total_count++;
        } else if (strncmp(p, "INFO", strlen("INFO")) == 0) {
            printf("[INFO] %s\n", r);
            info_count++;
            total_count++;
        } else if (strncmp(p, "DEBUG", strlen("DEBUG")) == 0) {
            printf("[DEBUG] %s\n", r);
            debug_count++;
            total_count++;
        }

        p = strtok(NULL, "\n");
    }

    printf("\nLog Analysis Report\n");
    printf("Total Messages: %d\n", total_count);
    printf("Errors: %d\n", error_count);
    printf("Warnings: %d\n", warning_count);
    printf("Informational Messages: %d\n", info_count);
    printf("Debug Messages: %d\n", debug_count);

    return 0;
}