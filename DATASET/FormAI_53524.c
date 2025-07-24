//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read CSV file
void readCSV(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Unable to open the file!\n");
        exit(1);
    }
    
    char buffer[1024], *token;
    int row = 0, column = 0;
    int data[row][column];
    
    while (fgets(buffer, 1024, file)) {
        column = 0;
        row++;
        
        token = strtok(buffer, ",");
        
        while (token != NULL) {
            data[row - 1][column++] = atoi(token);
            token = strtok(NULL, ",");
        }
    }
    
    fclose(file);
    printf("CSV file read successfully!\n");
    
    // Display the data from the CSV file
    printf("Data from the CSV file:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            printf("%d ", data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    readCSV("data.csv");
    return 0;
}