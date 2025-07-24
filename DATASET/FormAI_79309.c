//FormAI DATASET v1.0 Category: Log analysis ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // check if the file path is provided as an argument
    if (argc < 2) {
        printf("Please specify the file path to analyze.");
        return 1;
    }

    const char *filename = argv[1];
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file %s.\n", filename);
        return 1;
    }

    char line[256];
    int num_lines = 0;
    int num_get_requests = 0;
    int num_post_requests = 0;
    int num_errors = 0;

    while (fgets(line, sizeof(line), file)) {
        num_lines++;

        // check if the line contains a GET or POST request
        if (strstr(line, "GET")) {
            num_get_requests++;
        } else if (strstr(line, "POST")) {
            num_post_requests++;
        }

        // check if the line contains an error
        if (strstr(line, "ERROR")) {
            num_errors++;
        }
    }

    printf("File %s has %d lines.\n", filename, num_lines);
    printf("There are %d GET requests and %d POST requests.\n", num_get_requests, num_post_requests);
    printf("There are %d errors in the file.\n", num_errors);

    fclose(file);
    return 0;
}