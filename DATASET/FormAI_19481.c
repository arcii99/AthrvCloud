//FormAI DATASET v1.0 Category: Log analysis ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

int main() {
    FILE *file;
    char line[MAXLINE];

    int totalRequests = 0;
    int successfulRequests = 0;
    int failedRequests = 0;

    // Open the log file
    file = fopen("access.log", "r");

    // Check if the file exists
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    printf("Access Log Analysis Report\n");
    printf("-------------------------\n");

    // Read each line of the log file
    while (fgets(line, MAXLINE, file) != NULL) {
        totalRequests++;

        // Check if the request was successful
        if (strstr(line, "HTTP/1.1\" 200") != NULL || strstr(line, "HTTP/1.0\" 200") != NULL) {
            successfulRequests++;
        } else {
            failedRequests++;
        }
    }

    printf("Total Requests: %d\n", totalRequests);
    printf("Successful Requests: %d\n", successfulRequests);
    printf("Failed Requests: %d\n", failedRequests);

    // Calculate the success rate
    double successRate = (double)successfulRequests / totalRequests * 100;

    printf("Success Rate: %.2f%%\n", successRate);

    // Close the log file
    fclose(file);

    return 0;
}