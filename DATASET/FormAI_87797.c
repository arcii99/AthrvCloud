//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE_LENGTH 1000
#define MAX_FIELD_LENGTH 100

int main() {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char *field;
    char *delimiter = ",";
    int field_count = 0;

    fp = fopen("file.csv", "r");
    if (fp == NULL) {
        printf("Error opening CSV file.\n");
        return 1;
    } 

    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        field_count = 0;
        field = strtok(line, delimiter);
        while (field != NULL) {
            printf("%d: %s\n", ++field_count, field);
            field = strtok(NULL, delimiter);
        }
    }
    fclose(fp);
    return 0;
}