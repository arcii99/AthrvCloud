//FormAI DATASET v1.0 Category: Log analysis ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 100
#define MAX_LINES 100

int main() {

    FILE *fp;
    char fileName[MAX_CHARS];
    char line[MAX_CHARS];
    char searchStr[MAX_CHARS];
    int count = 0;

    printf("Enter file name: ");
    scanf("%s", fileName);

    printf("Enter search string: ");
    scanf("%s", searchStr);

    fp = fopen(fileName, "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, MAX_CHARS, fp)) {
        if (strstr(line, searchStr))
            count++;
    }

    printf("Number of lines containing search string: %d\n", count);

    fclose(fp);

    return 0;
}