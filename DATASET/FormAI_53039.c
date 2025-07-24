//FormAI DATASET v1.0 Category: Log analysis ; Style: automated
#include <stdio.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_CHARACTERS 100

int main() {
    FILE *log_file;
    char line[MAX_CHARACTERS];
    int total_lines = 0;

    int GET_requests = 0;
    int POST_requests = 0;
    int PUT_requests = 0;
    int DELETE_requests = 0;

    int successful_responses = 0;
    int failed_responses = 0;

    log_file = fopen("example_log.txt", "r");
    if (log_file == NULL) {
        printf("Error: Unable to open log file.\n");
        return 1;
    }

    while (fgets(line, MAX_CHARACTERS, log_file) != NULL) {
        total_lines++;

        if (strstr(line, "GET /") != NULL) {
            GET_requests++;
        } else if (strstr(line, "POST /") != NULL) {
            POST_requests++;
        } else if (strstr(line, "PUT /") != NULL) {
            PUT_requests++;
        } else if (strstr(line, "DELETE /") != NULL) {
            DELETE_requests++;
        }

        if (strstr(line, "HTTP/1.1\" 200") != NULL) {
            successful_responses++;
        } else if (strstr(line, "HTTP/1.1\" 4") != NULL || strstr(line, "HTTP/1.1\" 5") != NULL) {
            failed_responses++;
        }
    }

    printf("Total number of lines in log file: %d\n", total_lines);
    printf("GET requests: %d\n", GET_requests);
    printf("POST requests: %d\n", POST_requests);
    printf("PUT requests: %d\n", PUT_requests);
    printf("DELETE requests: %d\n", DELETE_requests);
    printf("Successful responses: %d\n", successful_responses);
    printf("Failed responses: %d\n", failed_responses);

    fclose(log_file);

    return 0;
}