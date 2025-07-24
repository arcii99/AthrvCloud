//FormAI DATASET v1.0 Category: Log analysis ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char log[100];
    int count = 0;
    FILE *fptr;

    // Opening the log file
    fptr = fopen("cyberpunk_log.txt", "r");

    // Checking if the file exists or not
    if (fptr == NULL) {
        printf("Error: Unable to open the file!\n");
        exit(1);
    }

    // Reading and analyzing the log file
    while (fgets(log, 100, fptr) != NULL) {
        char *pattern = "Error";
        char *error = strstr(log, pattern);

        // If an error is found, increment the count and display the error message
        if (error != NULL) {
            count++;
            printf("------------------------------------------------\n");
            printf("Error message %d: %s", count, error);
            printf("------------------------------------------------\n");
        }
    }

    // Closing the file
    fclose(fptr);

    // Displaying the total number of errors found
    if (count == 0) {
        printf("No errors found in the Cyberpunk log file.");
    } else {
        printf("Total errors found in the Cyberpunk log file: %d\n", count);
    }

    return 0;
}