//FormAI DATASET v1.0 Category: Log analysis ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char filename[100];
    printf("Enter the name of the log file: ");
    scanf("%s", filename);

    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    int linecount = 0, errorcount = 0;
    char line[100];
    while (fgets(line, 100, fp) != NULL) {
        linecount++;
        if (strstr(line, "ERROR")) {
            errorcount++;
            printf("Error found in line %d: %s", linecount, line);
        }
    }

    if (errorcount == 0) {
        printf("No errors found in log file!\n");
    }
    else {
        printf("%d error(s) found in log file!\n", errorcount);
    }

    fclose(fp);
    return 0;
}