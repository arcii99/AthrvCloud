//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: imaginative
#include <stdio.h>
#include <string.h>

#define MAX_COLUMNS 10
#define MAX_BUFFER 1024

int main() {
    FILE *csvFile;
    char filePath[256], line[MAX_BUFFER], *column;
    char columns[MAX_COLUMNS][MAX_BUFFER];
    int i, columnCount = 0;

    printf("Enter the CSV file path: ");
    fgets(filePath, 256, stdin);

    if ((csvFile = fopen(filePath, "r")) == NULL) {
        printf("Failed to open file.\n");
        return -1;
    }

    // Reading the header row
    if (fgets(line, MAX_BUFFER, csvFile) != NULL) {
        // Splitting the header row into columns
        column = strtok(line, ",");
        while(column != NULL && columnCount < MAX_COLUMNS) {
            strcpy(columns[columnCount++], column);
            column = strtok(NULL, ",");
        }
    }

    // Printing the column headers
    printf("\nColumns in the CSV file:\n");
    for (i = 0; i < columnCount; i++) {
        printf("%s\n", columns[i]);
    }

    // Reading the data rows
    printf("\nData in the CSV file:\n");
    while(fgets(line, MAX_BUFFER, csvFile) != NULL) {
        // Splitting the data row into columns
        columnCount = 0;
        column = strtok(line, ",");
        while(column != NULL && columnCount < MAX_COLUMNS) {
            printf("%s: %s\n", columns[columnCount], column);
            columnCount++;
            column = strtok(NULL, ",");
        }
        printf("\n");
    }

    fclose(csvFile);

    return 0;
}