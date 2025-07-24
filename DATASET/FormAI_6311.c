//FormAI DATASET v1.0 Category: Log analysis ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void analyzeLogs(const char* fileName, int* totalLogs) {
    FILE *filePointer;
    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    filePointer = fopen(fileName, "r");
    if (filePointer == NULL) {
        printf("File cannot be opened\n");
        return;
    }

    while ((read = getline(&line, &len, filePointer)) != -1) {
        (*totalLogs)++;
        char* logLevel = strtok(line, " ");
        if (strcmp(logLevel, "ERROR") == 0) {
            printf("Error Found: %s\n", line);
        }
        analyzeLogs(NULL, totalLogs);   //recursive call
    }

    fclose(filePointer);
    if (line)
        free(line);
}

int main() {
    int totalLogs = 0;
    printf("Analyzing Logs....\n");
    analyzeLogs("example.log", &totalLogs);
    printf("Total Number of Logs: %d\n", totalLogs);
    return 0;
}