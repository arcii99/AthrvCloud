//FormAI DATASET v1.0 Category: Log analysis ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_LINES 1000
#define MAX_LOG_LENGTH 100

int main() {
    char logs[MAX_LOG_LINES][MAX_LOG_LENGTH];
    int count = 0, errors = 0, warnings = 0;

    FILE *fp = fopen("example.log", "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Read log file line by line and store in logs array
    while (fgets(logs[count], MAX_LOG_LENGTH, fp)) {
        // Count number of error and warning logs
        if (strstr(logs[count], "ERROR")) {
            errors++;
        } else if (strstr(logs[count], "WARNING")) {
            warnings++;
        }
        count++;
    }

    fclose(fp);

    // Display analysis results
    printf("Log file analysis:\n");
    printf("Total logs: %d\n", count);
    printf("Error logs: %d\n", errors);
    printf("Warning logs: %d\n", warnings);

    return 0;
}