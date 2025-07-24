//FormAI DATASET v1.0 Category: Log analysis ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char log[1000], *timestamp, *message;
    int error_count = 0;
    FILE *file;

    printf("Welcome to the log analysis program.\n");
    printf("\nEnter the path of the log file: ");
    scanf("%s", log);

    file = fopen(log, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", log);
        return 1;
    }

    while (fgets(log, sizeof(log), file)) {
        timestamp = strtok(log, " ");
        message = strtok(NULL, "");

        if (strstr(message, "error")) {
            error_count++;

            printf("\nThe error occurred at %s", timestamp);
            printf("The error message is: %s", message);
        }
    }

    if (error_count == 0) {
        printf("\nCongratulations! No errors were found in the log file.\n");
    } else {
        printf("\nTotal Errors: %d\n", error_count);
    }

    fclose(file);
    return 0;
}