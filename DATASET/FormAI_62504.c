//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CSV_DELIMETER "," // Define the CSV delimeter

int main() {
    FILE* csv_file = fopen("data.csv", "r"); // Open the CSV file for reading

    if (csv_file == NULL) { // Check if the file exists
        printf("Error opening file\n");
        return 1;
    }

    char buffer[1024]; // Define a buffer to store each line of the CSV file
    int row_count = 0; // Counter for the number of rows in the CSV file
    int column_count = 0; // Counter for the number of columns in the CSV file

    while (fgets(buffer, 1024, csv_file)) { // Loop through each line of the CSV file
        row_count++; // Increment the row count for each line
        if (row_count == 1) { // If this is the first row, count the columns
            char* token = strtok(buffer, CSV_DELIMETER); // Use strtok to find the columns
            while (token != NULL) {
                column_count++; // Increment the column count for each column
                token = strtok(NULL, CSV_DELIMETER);
            }
        }
    }

    rewind(csv_file); // Rewind the file position to the beginning

    char*** data = (char***)malloc(sizeof(char**) * row_count); // Allocate memory for the data array
    for (int i = 0; i < row_count; i++) {
        data[i] = (char**)malloc(sizeof(char*) * column_count); // Allocate memory for each row
        for (int j = 0; j < column_count; j++) {
            data[i][j] = (char*)malloc(sizeof(char) * 1024); // Allocate memory for each column
        }
    }

    row_count = 0;
    while (fgets(buffer, 1024, csv_file)) {
        int column_num = 0;
        char* token = strtok(buffer, CSV_DELIMETER);
        while (token != NULL) {
            strcpy(data[row_count][column_num], token); // Copy each token into the data array
            column_num++;
            token = strtok(NULL, CSV_DELIMETER);
        }
        row_count++;
    }

    fclose(csv_file); // Close the CSV file

    // Print out the CSV data
    for (int i = 0; i < row_count; i++) {
        for (int j = 0; j < column_count; j++) {
            printf("%s, ", data[i][j]);
        }
        printf("\n");
    }

    // Free the memory allocated for the data array
    for (int i = 0; i < row_count; i++) {
        for (int j = 0; j < column_count; j++) {
            free(data[i][j]);
        }
        free(data[i]);
    }
    free(data);

    return 0;
}