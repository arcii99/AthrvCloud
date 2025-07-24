//FormAI DATASET v1.0 Category: Log analysis ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOG_FILE "sample.log"

int main() {
    FILE *logFile;
    char *line = NULL;
    size_t length = 0;
    ssize_t read;

    logFile = fopen(LOG_FILE, "r");
    if (logFile == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    int errorCount = 0;
    int successCount = 0;
    int warningCount = 0;
    int infoCount = 0;
    int debugCount = 0;

    while ((read = getline(&line, &length, logFile)) != -1) {
        if (strstr(line, "[ERROR]") != NULL) {
            errorCount++;
        } else if (strstr(line, "[SUCCESS]") != NULL) {
            successCount++;
        } else if (strstr(line, "[WARNING]") != NULL) {
            warningCount++;
        } else if (strstr(line, "[INFO]") != NULL) {
            infoCount++;
        } else if (strstr(line, "[DEBUG]") != NULL) {
            debugCount++;
        }
    }

    printf("Error count: %d\n", errorCount);
    printf("Success count: %d\n", successCount);
    printf("Warning count: %d\n", warningCount);
    printf("Info count: %d\n", infoCount);
    printf("Debug count: %d\n", debugCount);

    fclose(logFile);
    if (line) free(line);

    return 0;
}