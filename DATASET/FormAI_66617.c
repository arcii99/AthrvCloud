//FormAI DATASET v1.0 Category: Log analysis ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *logFile;
    char line[256];
    char cmd[10];
    int statusCode;
    int count = 0;
    int totalStatusCode = 0;

    logFile = fopen("example.log", "r");

    if (logFile == NULL) {
        printf("Error: Unable to open file\n");
        return 1;
    }

    printf("Processing logfile...\n");
    while (fgets(line, sizeof(line), logFile)) {
        sscanf(line, "%s %d", cmd, &statusCode);

        if (strcmp(cmd, "GET") == 0) {
            count++;

            if (statusCode == 200) {
                totalStatusCode++;
            }
        }
    }

    printf("Total GET requests: %d\n", count);
    printf("Percentage of successful GET requests: %.2f%%\n", ((float)totalStatusCode/count)*100);

    fclose(logFile);
    return 0;
}