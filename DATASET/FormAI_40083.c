//FormAI DATASET v1.0 Category: Log analysis ; Style: lively
#include <stdio.h>

int main() {
    printf("Welcome to our Log analysis program!\n");

    // read file
    FILE *fp = fopen("logs.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    printf("\nThe following lines contain the keyword 'Error':\n");
    // loop through each line in the file
    char line[100];
    int line_num = 1;
    while (fgets(line, sizeof(line), fp)) {
        // check if line contains the keyword 'Error'
        if (strstr(line, "Error") != NULL) {
            printf("Line %d: %s", line_num, line);
        }
        line_num++;
    }

    // close the file
    fclose(fp);

    printf("\n\nAnalyzing log file...\n");

    // read file again
    fp = fopen("logs.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // loop through each line in the file
    int num_requests = 0;
    double sum_response_times = 0;
    while (fgets(line, sizeof(line), fp)) {
        // check if line contains a request
        if (strstr(line, "Request") != NULL) {
            // get response time from line
            double response_time;
            sscanf(line, "Request took %lf seconds", &response_time);
            num_requests++;
            sum_response_times += response_time;
        }
    }

    // close the file
    fclose(fp);

    if (num_requests > 0) {
        double avg_response_time = sum_response_times / num_requests;
        printf("\n\nNumber of requests: %d\nAverage response time: %lf seconds\n", num_requests, avg_response_time);
    } else {
        printf("\n\nNo requests found in log file.\n");
    }

    return 0;
}