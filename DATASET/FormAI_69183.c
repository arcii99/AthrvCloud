//FormAI DATASET v1.0 Category: Log analysis ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

int main(int argc, char const *argv[]) {

    if (argc != 2) {
        printf("Usage: ./log_analysis <log_file>\n");
        return 1;
    }

    FILE *log_file = fopen(argv[1], "r");

    if (log_file == NULL) {
        printf("File not found.\n");
        return 1;
    }

    int total_requests = 0;
    int get_requests = 0;
    int post_requests = 0;
    int put_requests = 0;
    int delete_requests = 0;

    char line[MAX_LINE_LENGTH];
    char *token;
    char *method;

    while (fgets(line, MAX_LINE_LENGTH, log_file)) {
        token = strtok(line, " ");
        method = "";

        while (token) {
            if (strcmp(token, "GET") == 0) {
                method = "GET";
                get_requests++;
                break;
            }

            if (strcmp(token, "POST") == 0) {
                method = "POST";
                post_requests++;
                break;
            }

            if (strcmp(token, "PUT") == 0) {
                method = "PUT";
                put_requests++;
                break;
            }

            if (strcmp(token, "DELETE") == 0) {
                method = "DELETE";
                delete_requests++;
                break;
            }

            token = strtok(NULL, " ");
        }

        if (method != "") {
            total_requests++;
        }
    }

    fclose(log_file);

    printf("Total requests: %d\n", total_requests);
    printf("GET requests: %d\n", get_requests);
    printf("POST requests: %d\n", post_requests);
    printf("PUT requests: %d\n", put_requests);
    printf("DELETE requests: %d\n", delete_requests);

    return 0;
}