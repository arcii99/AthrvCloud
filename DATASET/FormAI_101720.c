//FormAI DATASET v1.0 Category: Log analysis ; Style: lively
// Welcome to our lively C Log analysis example program!
// Today, we will be analyzing a log file and outputting some useful statistics.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Let's open up our log file for reading
    FILE *log_file = fopen("example.log", "r");
    if (log_file == NULL) {
        printf("Error opening log file!\n");
        return 1;
    }

    // Now, let's read through the log file and count the number of times each error occurs
    int error_count[10] = {0}; // There are 10 possible errors
    int total_count = 0;
    char line[100];
    while (fgets(line, sizeof(line), log_file)) {
        int error_code = atoi(line);
        if (error_code >= 0 && error_code < 10) {
            error_count[error_code]++;
            total_count++;
        }
    }

    // Let's print out our error counts and total count
    printf("Total number of errors: %d\n", total_count);
    printf("Error counts:\n");
    for (int i = 0; i < 10; i++) {
        printf("Error %d: %d\n", i, error_count[i]);
    }

    // Finally, let's calculate and print out the percentage of errors for each error code
    printf("Percentage breakdown:\n");
    for (int i = 0; i < 10; i++) {
        float percentage = (float) error_count[i] / (float) total_count * 100;
        printf("Error %d: %.2f%%\n", i, percentage);
    }

    // Don't forget to close the file when we're done!
    fclose(log_file);

    // We hope you enjoyed our lively C Log analysis example program. Thanks for running it!
    return 0;
}