//FormAI DATASET v1.0 Category: Log analysis ; Style: lively
#include <stdio.h>

int main() {
    printf("Welcome to the Log Analyzer!\n");
    printf("Please enter the name of the log file to be analyzed (e.g. access_log): ");
    char filename[50];
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error! Could not open file.\n");
        return 1;
    }

    int numRequests = 0;
    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        char *pos;
        if ((pos = strchr(line, '\n')) != NULL) {
            *pos = '\0';
        }
        printf("%s\n", line);
        numRequests++;
    }
    printf("Total number of requests: %d\n", numRequests);

    fclose(file);

    return 0;
}