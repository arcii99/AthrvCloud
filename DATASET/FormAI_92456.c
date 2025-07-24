//FormAI DATASET v1.0 Category: Log analysis ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_CHARS 200

int main(int argc, char *argv[]) {

    if (argc != 2) { // Make sure input file option is specified
        printf("Usage: %s <inputfile>\n", argv[0]);
        exit(1);
    }

    char *filename = argv[1];

    FILE *file = fopen(filename, "r");
    if (!file) { // Make sure file exists
        printf("Could not open file: %s\n", filename);
        exit(1);
    }

    char line[MAX_CHARS];
    int line_count = 0;
    int success_count = 0;
    int failure_count = 0;

    while (fgets(line, MAX_CHARS, file) && line_count < MAX_LINES) {

        // Check for successful requests (HTTP 200 status code)
        if (strstr(line, "HTTP/1.1\" 200")) {
            success_count++;
        }

        // Check for failed requests (HTTP status codes other than 200)
        if (strstr(line, "HTTP/1.1\" ") && !strstr(line, "HTTP/1.1\" 200")) {
            failure_count++;
        }

        line_count++;
    }

    fclose(file);

    // Display results
    printf("Log file: %s\n", filename);
    printf("Number of lines analyzed: %d\n", line_count);
    printf("Number of successful requests: %d\n", success_count);
    printf("Number of failed requests: %d\n", failure_count);

    return 0;
}