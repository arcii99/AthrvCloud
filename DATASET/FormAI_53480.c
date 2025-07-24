//FormAI DATASET v1.0 Category: Log analysis ; Style: relaxed
#include <stdio.h>
#include <string.h>

int main() {
    // Declare variables
    FILE *file;
    char line[100];
    int error_count = 0;

    // Open the log file for reading
    file = fopen("example.log", "r");

    // Make sure the file exists
    if (file == NULL) {
        printf("Log file not found!\n");
        return 1;
    }

    // Read in each line of the file
    while (fgets(line, sizeof(line), file)) {

        // Check if the line contains an error
        if (strstr(line, "error") != NULL) {
            printf("%s", line); // Print the line containing the error
            error_count++; // Increment the error count
        }
    }

    // Close the file
    fclose(file);

    // Print the total number of errors found
    if (error_count == 0) {
        printf("No errors found in log file!\n");
    } else if (error_count == 1) {
        printf("1 error found in log file!\n");
    } else {
        printf("%d errors found in log file!\n", error_count);
    }

    return 0;
}