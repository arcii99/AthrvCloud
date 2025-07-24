//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLUMNS 50 
#define MAX_LINE_LENGTH 1000
#define DELIMITER ','

typedef struct {
    int numColumns;
    char** columnNames;
    char*** data;
} CsvData;

CsvData* readCsvFile(const char* filename) {
    CsvData* csvData = (CsvData*)malloc(sizeof(CsvData));
    if(csvData == NULL) {
        printf("Error allocating memory for CsvData.\n");
        exit(1);
    }

    FILE* file = fopen(filename, "r");
    if(file == NULL) {
        printf("Error opening file %s.\n", filename);
        exit(1);
    }

    // Read first line to determine number of columns
    char line[MAX_LINE_LENGTH];
    fgets(line, MAX_LINE_LENGTH, file);
    char* token = strtok(line, ",");
    csvData->numColumns = 0;
    csvData->columnNames = (char**)malloc(MAX_COLUMNS * sizeof(char*));
    if(csvData->columnNames == NULL) {
        printf("Error allocating memory for CsvData column names.\n");
        exit(1);
    }
    while(token != NULL && csvData->numColumns < MAX_COLUMNS) {
        csvData->columnNames[csvData->numColumns] = strdup(token);
        csvData->numColumns++;
        token = strtok(NULL, ",");
    }

    // Allocate memory for data
    csvData->data = (char***)malloc(MAX_LINE_LENGTH * sizeof(char**));
    if(csvData->data == NULL) {
        printf("Error allocating memory for CsvData data.\n");
        exit(1);
    }
    for(int i = 0; i < MAX_LINE_LENGTH; i++) {
        csvData->data[i] = (char**)malloc(MAX_COLUMNS * sizeof(char*));
        if(csvData->data[i] == NULL) {
            printf("Error allocating memory for CsvData data[%d].\n", i);
            exit(1);
        }
    }

    // Read data
    int lineIndex = 0;
    while(fgets(line, MAX_LINE_LENGTH, file) != NULL && lineIndex < MAX_LINE_LENGTH) {
        char* value = strtok(line, ",");
        int columnIndex = 0;
        while(value != NULL && columnIndex < csvData->numColumns) {
            csvData->data[lineIndex][columnIndex] = strdup(value);
            columnIndex++;
            value = strtok(NULL, ",");
        }
        lineIndex++;
    }

    fclose(file);

    return csvData;
}

int main() {
    CsvData* csvData = readCsvFile("example.csv");

    // Print column names
    for(int i = 0; i < csvData->numColumns; i++) {
        printf("%s ", csvData->columnNames[i]);
    }
    printf("\n");

    // Print data
    for(int i = 0; i < MAX_LINE_LENGTH && csvData->data[i][0] != NULL; i++) {
        for(int j = 0; j < csvData->numColumns; j++) {
            printf("%s ", csvData->data[i][j]);
        }
        printf("\n");
    }

    // Deallocate memory
    for(int i = 0; i < MAX_LINE_LENGTH; i++) {
        for(int j = 0; j < csvData->numColumns; j++) {
            free(csvData->data[i][j]);
        }
        free(csvData->data[i]);
    }
    free(csvData->data);
    for(int i = 0; i < csvData->numColumns; i++) {
        free(csvData->columnNames[i]);
    }
    free(csvData->columnNames);
    free(csvData);

    return 0;
}