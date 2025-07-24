//FormAI DATASET v1.0 Category: Log analysis ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *input_file;
    char *log_filename;
    char buffer[256];
    int line_count = 0;

    // Check if the user provided a log filename
    if (argc < 2) {
        printf("Please provide a log filename\n");
        exit(EXIT_FAILURE);
    }

    // Open the log file for reading
    log_filename = argv[1];
    input_file = fopen(log_filename, "r");
    if (input_file == NULL) {
        printf("Error opening log file\n");
        exit(EXIT_FAILURE);
    }

    // Read each line of the log file
    while (fgets(buffer, sizeof(buffer), input_file) != NULL) {
        line_count++;

        // Check if the line contains a specific keyword
        char *result = strstr(buffer, "error");
        if (result != NULL) {
            printf("Error found on line %d: %s", line_count, buffer);
        }
    }

    // Close the input file
    fclose(input_file);

    return 0;
}