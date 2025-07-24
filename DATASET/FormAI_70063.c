//FormAI DATASET v1.0 Category: Log analysis ; Style: active
#include <stdio.h>

int main() {
    FILE *logFile;
    char logLine[100];
    int numInfo = 0, numWarnings = 0, numErrors = 0;

    logFile = fopen("example.log", "r");

    if (logFile != NULL) {
        while (fgets(logLine, 100, logFile) != NULL) {
            if (strstr(logLine, "INFO") != NULL) {
                numInfo++;
            }
            else if (strstr(logLine, "WARNING") != NULL) {
                numWarnings++;
            }
            else if (strstr(logLine, "ERROR") != NULL) {
                numErrors++;
            }
        }
        printf("Number of INFO logs: %d\n", numInfo);
        printf("Number of WARNING logs: %d\n", numWarnings);
        printf("Number of ERROR logs: %d\n", numErrors);
        fclose(logFile);
    }
    else {
        printf("Error: Unable to open log file.\n");
    }

    return 0;
}