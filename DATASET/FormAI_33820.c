//FormAI DATASET v1.0 Category: Log analysis ; Style: enthusiastic
#include <stdio.h> 

int main() 
{ 
    FILE *logFile;
    char buffer[1000];
    int line = 0, errCount = 0, warnCount = 0, infoCount = 0;
    logFile = fopen("log.txt", "r");

    if (logFile == NULL) {
        printf("Log file not found");
        return 0;
    }

    printf("===== Starting Log Analysis =====\n\n");

    while (fgets(buffer,1000,logFile)) {
        line++;
        if (strstr(buffer, "ERROR")) {
            errCount++;
            printf("Line %d: %s", line, buffer);
        } else if (strstr(buffer, "WARNING")) {
            warnCount++;
            printf("Line %d: %s", line, buffer);
        } else if (strstr(buffer, "INFO")) {
            infoCount++;
            printf("Line %d: %s", line, buffer);
        }
    }

    printf("\n===== Log Analysis Complete =====\n\n");
    printf("Number of Error Messages: %d\n", errCount);
    printf("Number of Warning Messages: %d\n", warnCount);
    printf("Number of Info Messages: %d\n", infoCount);

    fclose(logFile);

    return 0; 
}