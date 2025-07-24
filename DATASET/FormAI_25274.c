//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLUMN_COUNT 10
#define MAX_COLUMN_LENGTH 50

int main() {
    char file[] = "data.csv";
    FILE *fp;

    fp = fopen(file, "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    char line[MAX_COLUMN_COUNT * MAX_COLUMN_LENGTH];
    char *token;
    int column_count = 0;
    while (fgets(line, sizeof(line), fp)) {
        token = strtok(line, ",");
        while (token != NULL) {
            printf("%s", token);
            column_count++;
            token = strtok(NULL, ",");
            if (column_count % MAX_COLUMN_COUNT == 0) {
                printf("\n");
            }
        }
    }

    fclose(fp);
    return 0;
}