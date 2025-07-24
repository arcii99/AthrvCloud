//FormAI DATASET v1.0 Category: Log analysis ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

int main() {
    // initialize variables
    char log[1000];
    int total_requests = 0;
    int successful_requests = 0;
    int failed_requests = 0;

    // read log file
    FILE *file = fopen("example_log.txt", "r");
    while (fgets(log, sizeof(log), file)) {
        // check if request was successful
        if (strstr(log, "200 OK") != NULL) {
            successful_requests++;
        } else {
            failed_requests++;
        }
        total_requests++;   
    }
    fclose(file);

    // print summary
    printf("Total requests: %d\n", total_requests);
    printf("Successful requests: %d\n", successful_requests);
    printf("Failed requests: %d\n", failed_requests);
    float success_rate = ((float) successful_requests / total_requests) * 100;
    printf("Success rate: %.2f%%\n", success_rate);
    return 0;
}