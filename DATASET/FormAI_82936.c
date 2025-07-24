//FormAI DATASET v1.0 Category: Log analysis ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char line[256];
    int total_requests = 0;
    int successful_requests = 0;
    int failed_requests = 0;
    float success_rate = 0;

    printf("Enter file name: ");
    fgets(line, sizeof(line), stdin);
    strtok(line, "\n");  // Remove newline character

    FILE *fp;
    fp = fopen(line, "r");

    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    printf("Processing log file...\n");

    while (fgets(line, sizeof(line), fp)) {
        char *tok = strtok(line, " ");
        while (tok != NULL) {
            if (strcmp(tok, "GET") == 0 || strcmp(tok, "POST") == 0) {
                total_requests++;
                tok = strtok(NULL, " ");
                if (strcmp(tok, "200") == 0 || strcmp(tok, "201") == 0) {
                    successful_requests++;
                } else {
                    failed_requests++;
                }
                break;
            }
            tok = strtok(NULL, " ");
        }
    }

    fclose(fp);

    if (total_requests == 0) {
        printf("No requests found in log file\n");
        exit(1);
    }

    success_rate = ((float)successful_requests / (float)total_requests) * 100;

    printf("\nTotal requests: %d\n", total_requests);
    printf("Successful requests: %d\n", successful_requests);
    printf("Failed requests: %d\n", failed_requests);
    printf("Success rate: %.2f%%\n", success_rate);

    return 0;
}