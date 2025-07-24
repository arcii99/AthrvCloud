//FormAI DATASET v1.0 Category: Log analysis ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_LINES 100000
#define MAX_LINE_LENGTH 1000

int main(int argc, char *argv[]) {
    // Check if file name argument is present
    if (argc < 2) {
        printf("Please provide a file name.\n");
        return 1;
    }

    // Open file for reading
    FILE *fp = fopen(argv[1], "r");

    // Check if file exists and can be opened
    if (fp == NULL) {
        printf("Unable to open file: %s\n", argv[1]);
        return 1;
    }

    // Initialize array to store log lines
    char lines[MAX_NUM_LINES][MAX_LINE_LENGTH];
    int num_lines = 0;

    // Read lines from file and store them in array
    while (fgets(lines[num_lines], MAX_LINE_LENGTH, fp) != NULL) {
        num_lines++;
    }

    // Close file
    fclose(fp);

    // Analyze log data
    int num_200 = 0;
    int num_404 = 0;
    int num_errors = 0;
    int num_unique_ips = 0;
    char unique_ips[MAX_NUM_LINES][16];

    for (int i = 0; i < num_lines; i++) {
        char *line = lines[i];

        // Split line into tokens
        char *ip = strtok(line, " -");
        char *date = strtok(NULL, "[]");
        char *request = strtok(NULL, "\"");
        char *status = strtok(NULL, " ");
        char *size = strtok(NULL, " ");

        // Count 200 and 404 status codes
        if (strcmp(status, "200") == 0) {
            num_200++;
        } else if (strcmp(status, "404") == 0) {
            num_404++;
        }

        // Count error responses
        if (strcmp(status, "5") == 0 || strcmp(status, "4") == 0) {
            num_errors++;
        }

        // Add unique IP addresses to array
        int is_unique = 1;
        for (int j = 0; j < num_unique_ips; j++) {
            if (strcmp(unique_ips[j], ip) == 0) {
                is_unique = 0;
                break;
            }
        }
        if (is_unique) {
            strcpy(unique_ips[num_unique_ips], ip);
            num_unique_ips++;
        }

        // Print log line
        printf("IP: %s | Date: %s | Request: %s | Status: %s | Size: %s\n",
            ip, date, request, status, size);
    }

    // Print analysis results
    printf("\n");
    printf("Total lines: %d\n", num_lines);
    printf("Status 200 lines: %d\n", num_200);
    printf("Status 404 lines: %d\n", num_404);
    printf("Error lines: %d\n", num_errors);
    printf("Unique IP addresses: %d\n", num_unique_ips);

    return 0;
}