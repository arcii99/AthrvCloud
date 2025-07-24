//FormAI DATASET v1.0 Category: Log analysis ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s [log_file]\n", argv[0]);
        return 1;
    }

    FILE* log_file = fopen(argv[1], "r");
    if (!log_file) {
        printf("Failed to open log file: %s\n", argv[1]);
        return 1;
    }

    char file_line[MAX_LINE_LENGTH];
    int line_number = 0;
    int total_requests = 0;
    int total_errors = 0;

    while (fgets(file_line, MAX_LINE_LENGTH, log_file)) {
        line_number++;
        char* request_start = strstr(file_line, "GET /");
        if (!request_start) {
            request_start = strstr(file_line, "POST /");
        }
        if (request_start) {
            total_requests++;
            char* response_code_start = strstr(request_start, "\" ") + 2;
            char response_code_str[4];
            strncpy(response_code_str, response_code_start, 3);
            response_code_str[3] = '\0';
            int response_code = atoi(response_code_str);
            if (response_code >= 400) {
                total_errors++;
                printf("Error on line %d: %s", line_number, file_line);
            }
        }
    }

    fclose(log_file);

    printf("Total Requests: %d\n", total_requests);
    printf("Total Errors: %d\n", total_errors);

    return 0;
}