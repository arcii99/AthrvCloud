//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_LINES 10000

int main() {
    char input[MAX_INPUT_LENGTH];
    char* linePtrs[MAX_LINES];
    int numLines = 0;
    int i;

    // Get input from user
    printf("Enter input: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    // Split input into lines
    char* tok = strtok(input, "\n");
    while (tok != NULL) {
        linePtrs[numLines++] = tok;
        tok = strtok(NULL, "\n");
    }

    // Check for suspicious activity
    int alert = 0;
    for (i = 0; i < numLines; i++) {
        // Check for port scanning
        if (strstr(linePtrs[i], "nmap") != NULL) {
            printf("Alert: Port scanning detected on line %d\n", i+1);
            alert = 1;
        }

        // Check for buffer overflow attempt
        if (strstr(linePtrs[i], "strcpy(") != NULL && strstr(linePtrs[i+1], "int main(") == NULL) {
            printf("Alert: Buffer overflow attempt detected on line %d\n", i+1);
            alert = 1;
        }

        // Check for SQL injection attempt
        if (strstr(linePtrs[i], "SELECT ") != NULL && strstr(linePtrs[i], "FROM ") != NULL && strstr(linePtrs[i+1], "WHERE ") != NULL) {
            printf("Alert: SQL injection attempt detected on line %d\n", i+1);
            alert = 1;
        }
    }

    // Print final result
    if (alert) {
        printf("Suspicious activity detected!\n");
    } else {
        printf("No suspicious activity detected.\n");
    }

    return 0;
}