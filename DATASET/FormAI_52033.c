//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR_PER_LINE 50
#define MAX_LINE 10

int main() {
    // Initialize variables
    FILE* file; 
    char data[MAX_CHAR_PER_LINE];
    char* token;
    char* fileName = "example.csv";
    int row = 0;
    int col = 0;
    char csvData[MAX_LINE][MAX_CHAR_PER_LINE];

    // Open file
    file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Failed to open %s.", fileName);
        return 0;
    }

    // Read data from file
    while (fgets(data, MAX_CHAR_PER_LINE, file) != NULL) {
        col = 0;
        token = strtok(data, ",");
        while (token != NULL) {
            strcpy(csvData[row][col], token);
            token = strtok(NULL, ",");
            col++;
        }
        row++;
    }

    // Close file
    fclose(file);

    // Print data
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%s ", csvData[i][j]);
        }
        printf("\n");
    }
    return 0;
}