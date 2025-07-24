//FormAI DATASET v1.0 Category: Log analysis ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char **argv) {
    FILE *log_file = fopen("logfile.txt", "r");
    if (log_file == NULL) {
        printf("Error: could not open logfile.txt\n");
        return 1;
    }

    int num_requests = 0;
    int num_successes = 0;
    int num_failures = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, log_file)) {
        // extract the HTTP status code from the log line
        char *status_code_str = strstr(line, "HTTP/1.1\" ");
        if (status_code_str == NULL) {
            // skip this line if it doesn't contain a status code
            continue;
        }
        status_code_str += strlen("HTTP/1.1\" ");

        int status_code = atoi(status_code_str);
        if (status_code >= 200 && status_code <= 299) {
            num_successes++;
        }
        else {
            num_failures++;
        }

        num_requests++;
    }

    fclose(log_file);

    printf("Total Requests: %d\n", num_requests);
    printf("Successful Requests: %d\n", num_successes);
    printf("Failed Requests: %d\n", num_failures);

    return 0;
}