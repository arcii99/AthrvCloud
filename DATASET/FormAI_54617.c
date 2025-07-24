//FormAI DATASET v1.0 Category: Log analysis ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function for analyzing a log file
void analyzeLog(char* fileName) {
    FILE* logFile;
    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    // open the log file in read mode
    logFile = fopen(fileName, "r");

    if (logFile == NULL) {
        printf("Error opening log file: %s\n", fileName);
        exit(EXIT_FAILURE);
    }

    printf("Analyzing log file: %s\n", fileName);

    // read each line of the log file
    while ((read = getline(&line, &len, logFile)) != -1) {
        // remove newline character from line
        line[strcspn(line, "\n")] = 0;

        // check if line contains a warning or error message
        if (strstr(line, "WARNING") != NULL) {
            printf("Warning message: %s\n", line);
        } else if (strstr(line, "ERROR") != NULL) {
            printf("Error message: %s\n", line);
        }
    }

    // close the log file and free memory allocated for line
    fclose(logFile);
    if (line) {
        free(line);
    }
}

int main() {
    // call analyzeLog function with specified log file
    analyzeLog("example.log");

    return 0;
}