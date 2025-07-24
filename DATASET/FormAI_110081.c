//FormAI DATASET v1.0 Category: Log analysis ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *LOG_FILE = "server.log";

int main() {
    FILE *log_file = fopen(LOG_FILE, "r");
    char line[256];
    int total_requests = 0;
    int total_errors = 0;
    int total_successes = 0;

    if (log_file == NULL) {
        printf("ERROR: Failed to open log file\n");
        exit(-1);
    }

    while (fgets(line, sizeof(line), log_file)) {
        if (strstr(line, "GET") || strstr(line, "POST")) {
            total_requests++;
            if (strstr(line, "200")) {
                total_successes++;
            } else {
                total_errors++;
            }
        }
    }

    printf("Total requests: %d\n", total_requests);
    printf("Total successes: %d\n", total_successes);
    printf("Total errors: %d\n", total_errors);

    fclose(log_file);
    return 0;
}