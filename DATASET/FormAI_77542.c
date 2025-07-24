//FormAI DATASET v1.0 Category: Log analysis ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

#define MAX_LOG_LINES 1000

char log[MAX_LOG_LINES][256];
int logCounter = 0;

int main() {
    printf("Welcome to CyberLog: The Ultimate Log Analyzer!\n\n");
    printf("Please enter the path of the log file you wish to analyze:\n");

    char filePath[256];
    fgets(filePath, 256, stdin);
    filePath[strcspn(filePath, "\n")] = 0;

    printf("\nAnalyzing log file at path: %s\n\n", filePath);

    FILE *file = fopen(filePath, "r");
    
    if (file == NULL) {
        printf("Error opening file at path: %s\n", filePath);
        return 1;
    }

    char line[256];

    printf("Log Analysis in Progress...\n\n");

    while (fgets(line, sizeof(line), file) != NULL) {
        line[strcspn(line, "\r\n")] = 0;

        printf("Examining log line: %s\n", line);

        if (strstr(line, "WARNING") != NULL) {
            strcpy(log[logCounter], line);
            logCounter++;
        } else if (strstr(line, "ERROR") != NULL) {
            strcpy(log[logCounter], line);
            logCounter++;
        } else if (strstr(line, "SUCCESS") != NULL) {
            // do nothing
        } else {
            printf("Unrecognized log line, ignoring...\n");
        }
    }

    fclose(file);

    printf("\nLog Analysis Complete!\n\n");

    if (logCounter == 0) {
        printf("No warnings or errors found in log file.\n");
    } else {
        printf("%d warnings or errors found in log file:\n", logCounter);
        for (int i = 0; i < logCounter; i++) {
            printf("%s\n", log[i]);
        }
    }

    return 0;
}