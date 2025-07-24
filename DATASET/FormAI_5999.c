//FormAI DATASET v1.0 Category: Log analysis ; Style: visionary
#include <stdio.h>

int main() {
    FILE *fp = fopen("example.log", "r");
    char line[256];

    int num_requests = 0;
    int num_success = 0;
    int num_errors = 0;

    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fp)) {
        char status[4];
        sscanf(line, "%*s %*s %*s %*s %s", status);

        num_requests++;

        if (strcmp(status, "200") == 0) {
            num_success++;
        } else {
            num_errors++;
        }
    }

    printf("Number of requests: %d\n", num_requests);
    printf("Number of successful requests: %d\n", num_success);
    printf("Number of errored requests: %d\n", num_errors);

    fclose(fp);

    return 0;
}