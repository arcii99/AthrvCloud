//FormAI DATASET v1.0 Category: Log analysis ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define LINE_LEN 1024

int main(int argc, char *argv[]) {
    int i, line_num = 0, error_count = 0;
    char *filename = argv[1];
    FILE *file = NULL;
    char line[LINE_LEN];

    // Open the log file
    file = fopen(filename, "r");
    if (!file) {
        printf("Could not open file %s\n", filename);
        exit(1);
    }

    // Read the file line by line
    while (fgets(line, LINE_LEN, file)) {
        line_num++;
        // Check for errors
        if (strstr(line, "error") || strstr(line, "ERROR")) {
            error_count++;
            printf("Error on line %d: %s\n", line_num, line);
        }
    }

    // Close the file
    fclose(file);

    // Print the summary
    printf("Processed %d lines.\n", line_num);
    printf("Found %d errors.\n", error_count);

    return 0;
}