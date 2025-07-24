//FormAI DATASET v1.0 Category: Log analysis ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    FILE *logFile;
    char logLine[50];

    printf("Initiating system scan...\n\n");

    srand(time(NULL));
    int numLogs = rand() % 50 + 1;

    logFile = fopen("system.log", "w+");
    if (logFile == NULL) {
        printf("Error: could not open log file\n");
        return 1;
    }

    for (int i = 0; i < numLogs; i++) {
        int randError = rand() % 3; // 33% chance for each error type
        if (randError == 0) {
            sprintf(logLine, "Error: system overload at line %d\n", i);
            fputs(logLine, logFile);
        } else if (randError == 1) {
            sprintf(logLine, "Warning: system temperature approaching critical levels at line %d\n", i);
            fputs(logLine, logFile);
        } else {
            sprintf(logLine, "INFO: system scan at line %d completed successfully\n", i);
            fputs(logLine, logFile);
        }
    }

    rewind(logFile);

    int lineNum = 1;
    char readLine[50];

    printf("System scan complete. Results:\n\n");

    while (fgets(readLine, 50, logFile) != NULL) {
        printf("%d. %s", lineNum, readLine);

        if (strstr(readLine, "Error")) {
            printf("ALERT: CRITICAL SYSTEM FAILURE DETECTED\n");
        } else if (strstr(readLine, "Warning")) {
            printf("WARNING: SYSTEM TEMPERATURE APPROACHING CRITICAL LEVELS\n");
        }

        lineNum++;
    }

    printf("\n");

    fclose(logFile);
    return 0;
}