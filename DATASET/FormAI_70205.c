//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define MAX_COLUMNS 10

int main() {
    FILE* csv_file = fopen("example.csv", "r");
    if (!csv_file) {
        printf("Failed to open CSV file.");
        return 1;
    }
    
    // Read the headers of our CSV file
    char line[BUFFER_SIZE];
    fgets(line, BUFFER_SIZE, csv_file);
    char* header[MAX_COLUMNS];
    int columns = 0;
    header[0] = strtok(line, ",");
    columns++;
    while (header[columns-1] != NULL && columns < MAX_COLUMNS) {
        header[columns] = strtok(NULL, ",");
        columns++;
    }
    printf("Headers:\n");
    for (int i = 0; i < columns-1; i++) {
        printf("%s | ", header[i]);
    }
    printf("\n");

    // Read the rows of the CSV file
    while (fgets(line, BUFFER_SIZE, csv_file)) {
        char* row[MAX_COLUMNS];
        int rows = 0;
        row[0] = strtok(line, ",");
        rows++;
        while (row[rows-1] != NULL && rows < MAX_COLUMNS) {
            row[rows] = strtok(NULL, ",");
            rows++;
        }
        printf("Row:\n");
        for (int i = 0; i < rows-1; i++) {
            printf("%s | ", row[i]);
        }
        printf("\n");
    }

    fclose(csv_file);
    return 0;
}