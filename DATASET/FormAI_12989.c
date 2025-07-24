//FormAI DATASET v1.0 Category: Log analysis ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    if(argc < 2) {
        printf("No input file provided.\n");
        return 1;
    }

    FILE* file = fopen(argv[1], "r");

    if(!file) {
        printf("File could not be opened.\n");
        return 1;
    }

    char line[512];
    int totalLines = 0;
    int errorCount = 0;
    int warningCount = 0;

    while(fgets(line, sizeof(line), file)) {
        totalLines++;

        if(strstr(line, "ERROR")) {
            errorCount++;
        } else if(strstr(line, "WARNING")) {
            warningCount++;
        }
    }

    fclose(file);

    printf("Total lines in log: %d\n", totalLines);
    printf("Errors found: %d\n", errorCount);
    printf("Warnings found: %d\n", warningCount);

    return 0;
}