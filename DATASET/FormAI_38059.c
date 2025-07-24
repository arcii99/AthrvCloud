//FormAI DATASET v1.0 Category: Data mining ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

void readData(char *filename, int **data, int *numRows, int *numCols) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error in opening file %s!\n", filename);
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    *numRows = 0;
    while (fgets(line, MAX_LINE_LENGTH, fp)) {
        (*numRows)++;
    }
    rewind(fp);

    *data = (int *) malloc((*numRows) * sizeof(int));
    *numCols = 0;
    while (fgets(line, MAX_LINE_LENGTH, fp)) {
        char *token = strtok(line, ",");
        while (token != NULL) {
            (*data)[(*numCols)++] = atoi(token);
            token = strtok(NULL, ",");
        }
    }

    fclose(fp);
}

void printData(int *data, int numRows, int numCols) {
    int i, j;
    for (i = 0; i < numRows; i++) {
        for (j = 0; j < numCols; j++) {
            printf("%d ", *(data + i*numCols + j));
        }
        printf("\n");
    }
}

int main() {
    int *data;
    int numRows, numCols;

    readData("data.csv", &data, &numRows, &numCols);

    printf("Data from file:\n");
    printData(data, numRows, numCols);

    free(data);

    return 0;
}