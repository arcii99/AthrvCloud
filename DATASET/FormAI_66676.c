//FormAI DATASET v1.0 Category: Text processing ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LINE_LENGTH 100

int main()
{
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char processed_lines[MAX_LINES][MAX_LINE_LENGTH];
    int count = 0;

    fp = fopen("input.txt", "r");

    if (fp == NULL) {
        printf("Error opening file");
        return 1;
    }

    while(fgets(line, MAX_LINE_LENGTH, fp)) {
        // Process line here
        char temp[MAX_LINE_LENGTH];
        strcpy(temp, line);
        int i, j;
        for (i = 0, j = strlen(temp)-1; i < j; i++, j--) {
            char c = temp[i];
            temp[i] = temp[j];
            temp[j] = c;
        }
        strcpy(processed_lines[count], temp);
        count++;
    }

    fclose(fp);

    fp = fopen("output.txt", "w");

    if (fp == NULL) {
        printf("Error creating file");
        return 1;
    }

    for (int i = 0; i < count; i++) {
        fputs(processed_lines[i], fp);
    }

    fclose(fp);

    printf("File processed successfully");

    return 0;
}