//FormAI DATASET v1.0 Category: Log analysis ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        return 1;
    } 

    char *log_file = argv[1];
    FILE *fp = fopen(log_file, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", log_file);
        return 1;
    }

    // Initialize variables
    int num_lines = 0;
    int num_get_requests = 0;
    int num_post_requests = 0;
    char line[MAX_LINE_LENGTH];

    // Read each line of the log file
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        num_lines++;

        // Count number of GET requests
        if (strstr(line, "GET") != NULL) {
            num_get_requests++;
        }

        // Count number of POST requests
        if (strstr(line, "POST") != NULL) {
            num_post_requests++;
        }

        // Print the current line
        printf("%s", line);
    }

    // Print summary statistics
    printf("\n\nSummary:\n");
    printf("Number of lines: %d\n", num_lines);
    printf("Number of GET requests: %d\n", num_get_requests);
    printf("Number of POST requests: %d\n", num_post_requests);

    // Close the log file
    fclose(fp);

    return 0;
}