//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: scientific
#include <stdio.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 100
#define MAX_LINE_LENGTH 1024

typedef struct csv_data {
    int rows;
    int cols;
    char data[MAX_ROWS][MAX_COLS][MAX_LINE_LENGTH];
} CSVData;

// Function to read CSV file
CSVData readCSVFile(char filename[]) {
    CSVData csvData;
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        csvData.rows = 0;
        csvData.cols = 0;
        return csvData;
    }
    
    char line[MAX_LINE_LENGTH];
    int rowCount = 0, colCount = 0;
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        char* token = strtok(line, ",");
        while (token != NULL && colCount < MAX_COLS) {
            strcpy(csvData.data[rowCount][colCount], token);
            token = strtok(NULL, ",");
            colCount++;
        }
        rowCount++;
        colCount = 0;
    }
    csvData.rows = rowCount;
    csvData.cols = colCount;
    
    fclose(fp);
    return csvData;
}

// Function to print CSV data
void printCSVData(CSVData csvData) {
    printf("Number of Rows: %d\n", csvData.rows);
    printf("Number of Columns: %d\n", csvData.cols);
    for (int i = 0; i < csvData.rows; i++) {
        for (int j = 0; j < csvData.cols; j++) {
            printf("%s ", csvData.data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    CSVData csvData = readCSVFile("data.csv");
    printCSVData(csvData);
    return 0;
}