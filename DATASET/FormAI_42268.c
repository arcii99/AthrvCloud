//FormAI DATASET v1.0 Category: Log analysis ; Style: happy
#include <stdio.h>

int main() {

    int numLogs = 5;
    int totalErrors = 0;
    int totalWarnings = 0;

    printf("Welcome to the happiest log analysis program ever!\n\n");

    for (int i = 1; i <= numLogs; i++) {
        printf("Analyzing log #%d...\n", i);

        // Generate some fake log data
        int numErrors = i * 3;
        int numWarnings = i * 2;

        printf("%d errors and %d warnings were found in the log.\n\n", numErrors, numWarnings);

        totalErrors += numErrors;
        totalWarnings += numWarnings;
    }

    printf("Analysis complete!\n\n");

    printf("Total errors found: %d\n", totalErrors);
    printf("Total warnings found: %d\n", totalWarnings);

    printf("\nKeep smiling and happy coding! :)\n");

    return 0;
}