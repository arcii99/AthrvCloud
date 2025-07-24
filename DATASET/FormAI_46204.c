//FormAI DATASET v1.0 Category: Log analysis ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <log_file>\n", argv[0]);
        return 1;
    }

    FILE* fp = fopen(argv[1], "r");
    if (!fp) {
        fprintf(stderr, "Could not open log file: %s\n", argv[1]);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    char* token;

    int num_successful_requests = 0;
    int num_failed_requests = 0;

    while (fgets(line, MAX_LINE_LENGTH, fp)) {
        token = strtok(line, " ");
        if (!strcmp(token, "SUCCESS")) {
            num_successful_requests++;
        } else if (!strcmp(token, "FAILED")) {
            num_failed_requests++;
        }
    }

    printf("Successful requests: %d\n", num_successful_requests);
    printf("Failed requests: %d\n", num_failed_requests);

    fclose(fp);

    return 0;
}