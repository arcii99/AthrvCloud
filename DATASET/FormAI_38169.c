//FormAI DATASET v1.0 Category: Log analysis ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main() {
    
    printf("Welcome to our happy log analysis program!\n\n");

    FILE *file;
    file = fopen("logfile.txt", "r");
    if(file == NULL){
        printf("Sorry, file does not exist.");
        exit(1);
    }

    printf("File found!\n\n");

    char line[100];
    int errorCount = 0;
    int lineCount = 0;
    int warningCount = 0;

    printf("Begin log analysis...\n\n");

    while (fgets(line, sizeof(line), file)) {
        lineCount++;

        // Check for errors
        if (strstr(line, "error")) {
            printf("ERROR: %s\n", line);
            errorCount++;
        }

        // Check for warnings
        else if (strstr(line, "warning")) {
            printf("WARNING: %s\n", line);
            warningCount++;
        }

        // Otherwise, ignore the line
    }

    printf("\nLog analysis complete!\n\n");
    printf("Summary:\n");
    printf("%d lines checked.\n", lineCount);
    printf("%d errors found.\n", errorCount);
    printf("%d warnings found.\n\n", warningCount);

    fclose(file);
    return 0;
}