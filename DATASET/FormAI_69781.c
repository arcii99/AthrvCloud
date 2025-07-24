//FormAI DATASET v1.0 Category: Log analysis ; Style: minimalist
#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

int main() {
    // open log file
    FILE *logFile = fopen("logfile.txt", "r");
    
    // check if file was opened successfully
    if (logFile == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // initialize variables
    int numRequests = 0;
    int numErrors = 0;
    char line[MAX_LINE_LENGTH];

    // read each line of the log file
    while (fgets(line, MAX_LINE_LENGTH, logFile)) {
        // get the first word of the line
        char *keyword = strtok(line, " ");

        // check if it is a request or an error
        if (strcmp(keyword, "REQUEST") == 0) {
            numRequests++;
        } else if (strcmp(keyword, "ERROR") == 0) {
            numErrors++;
        }
    }

    // print out the results
    printf("Number of requests: %d\nNumber of errors: %d\n", numRequests, numErrors);

    // close log file
    fclose(logFile);

    return 0;
}