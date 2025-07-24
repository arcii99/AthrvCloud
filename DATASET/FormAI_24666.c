//FormAI DATASET v1.0 Category: Log analysis ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 256

int main(int argc, char *argv[]) {
    // check that file name is provided
    if (argc < 2) {
        printf("Please provide the name of the log file.\n");
        return 1; // indicate failure
    }

    char *filename = argv[1];
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: failed to open %s\n", filename);
        return 1; // indicate failure
    }

    // create variables to keep track of log data
    char line[MAX_LINE_LEN];
    int total_requests = 0;
    int error_requests = 0;
    int total_bytes = 0;

    while (fgets(line, MAX_LINE_LEN, file) != NULL) {
        // check if line contains request information
        if (strstr(line, "GET") != NULL || strstr(line, "POST") != NULL) {
            total_requests++;

            // check if line contains error code
            if (strstr(line, " 4") != NULL || strstr(line, " 5") != NULL) {
                error_requests++;
            }

            // extract number of bytes from line
            char *byte_str = strstr(line, "bytes=");
            if (byte_str != NULL) {
                total_bytes += atoi(byte_str + strlen("bytes="));
            }
        }
    }

    printf("Total requests: %d\n", total_requests);
    printf("Error requests: %d\n", error_requests);
    printf("Total bytes transferred: %d\n", total_bytes);

    fclose(file);
    return 0;
}