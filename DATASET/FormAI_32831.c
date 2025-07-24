//FormAI DATASET v1.0 Category: Log analysis ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Open log file for reading
    FILE *logFile = fopen("example.log", "r");

    // Make sure file was opened successfully
    if (logFile == NULL) {
        printf("Error: Could not open log file.\n");
        return 1;
    }

    // Create variables to store relevant information
    int totalRequests = 0;
    int successfulRequests = 0;
    int failedRequests = 0;
    char line[256];

    // Loop through each line of the file
    while (fgets(line, sizeof(line), logFile)) {
        // Check if line is a request
        if (strstr(line, "Request")) {
            totalRequests++;

            // Check if request was successful
            if (strstr(line, "200 OK")) {
                successfulRequests++;
            } else {
                failedRequests++;
            }
        }
    }

    // Print out results
    printf("Total Requests: %d\n", totalRequests);
    printf("Successful Requests: %d\n", successfulRequests);
    printf("Failed Requests: %d\n", failedRequests);

    // Close log file
    fclose(logFile);

    return 0;
}