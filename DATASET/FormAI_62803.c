//FormAI DATASET v1.0 Category: Log analysis ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

// function to parse a single line of a log file
int parseLine(char *line) {
    int errorCode = -1;
    char *separator = ",";
    char *ptr;
    char *tokens[5];
    int i = 0;

    // tokenize the line based on separator ","
    ptr = strtok(line, separator);
    while (ptr != NULL && i < 5) {
        tokens[i] = ptr;
        ptr = strtok(NULL, separator);
        i++;
    }

    // check if the line was correctly parsed (must have 4 comma separated values)
    if (i == 4) {
        // get the error code (last token)
        if (strlen(tokens[3]) == 3) {
            errorCode = atoi(tokens[3]);
        }
    }

    return errorCode;
}

// function to analyze the log file and count the occurrence of each error code
int *analyzeLogFile(char *filename, int *numErrorCodes) {
    int *errorCodes = NULL;
    int errorCode;
    int numCodes = 0;

    // open the log file for reading
    FILE *logFile = fopen(filename, "r");
    if (logFile != NULL) {
        char line[MAX_LINE_LENGTH];

        // read each line of the log file and parse the error code
        while (fgets(line, sizeof(line), logFile)) {
            errorCode = parseLine(line);
            if (errorCode != -1) {
                // check if the error code already exists in the array
                int i;
                for (i = 0; i < numCodes; i++) {
                    if (errorCode == errorCodes[i]) {
                        break;
                    }
                }

                // if the error code does not exist in the array, add it
                if (i == numCodes) {
                    numCodes++;
                    errorCodes = realloc(errorCodes, sizeof(int) * numCodes);
                    errorCodes[numCodes - 1] = errorCode;
                }
            }
        }

        // close the log file
        fclose(logFile);
    }

    // set the number of error codes
    *numErrorCodes = numCodes;

    return errorCodes;
}

int main() {
    char *filename = "log.txt";
    int *errorCodes;
    int numErrorCodes;
    int i;

    // analyze the log file
    errorCodes = analyzeLogFile(filename, &numErrorCodes);

    // print the results
    printf("Log analysis results:\n");
    printf("---------------------\n");
    printf("File name : %s\n", filename);

    if (numErrorCodes > 0) {
        printf("Error codes:\n");
        for (i = 0; i < numErrorCodes; i++) {
            printf("%d\n", errorCodes[i]);    
        }
    } else {
        printf("No error codes found in log file.\n");
    }

    // free the memory allocated for the error codes array
    free(errorCodes);

    return 0;
}