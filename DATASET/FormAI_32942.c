//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLUMNS 20
#define MAX_LINE_LENGTH 100

int main(void) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char *token;

    fp = fopen("data.csv", "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    int num_columns = 0;
    char *columns[MAX_COLUMNS];

    if (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        token = strtok(line, ",");
        while (token != NULL && num_columns < MAX_COLUMNS) {
            columns[num_columns++] = strdup(token);
            token = strtok(NULL, ",");
        }
    }

    printf("Number of columns: %d\n", num_columns);
    for (int i = 0; i < num_columns; i++) {
        printf("%s\n", columns[i]);
    }

    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        char *column_values[MAX_COLUMNS];
        int column_index = 0;
        token = strtok(line, ",");
        while (token != NULL && column_index < num_columns) {
            column_values[column_index++] = strdup(token);
            token = strtok(NULL, ",");
        }

        for (int i = 0; i < column_index; i++) {
            printf("%s: %s\n", columns[i], column_values[i]);
            free(column_values[i]);
        }
    }

    for (int i = 0; i < num_columns; i++) {
        free(columns[i]);
    }

    fclose(fp);

    return 0;
}