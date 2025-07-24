//FormAI DATASET v1.0 Category: Log analysis ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int main() {
    char line[MAXLINE];
    int lineNumber = 0;
    int errCounter = 0;

    // Open the log file
    FILE *filePtr = fopen("logFile.txt", "r");

    // Loop through each line in the file
    while (fgets(line, MAXLINE, filePtr)) {
        lineNumber++;

        // Check for error messages
        if (strstr(line, "ERROR")) {
            errCounter++;
            printf("Error! Line %d: %s\n", lineNumber, line);
        }
    }

    // Display summary
    printf("\n\n===== Log Analysis Summary =====\n");
    printf("Total Lines Analyzed: %d\n", lineNumber);
    printf("Total Errors Found: %d\n", errCounter);

    return 0;
}