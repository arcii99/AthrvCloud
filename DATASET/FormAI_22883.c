//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARACTERS_PER_LINE 256
#define MAX_COLUMNS_PER_LINE 10
#define MAX_ROWS 100

char lines[MAX_ROWS][MAX_COLUMNS_PER_LINE][MAX_CHARACTERS_PER_LINE];

void process_csv_file(const char* filename) {
    // Try to open the file
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        return;
    }

    // Read line by line until the end of the file or the maximum number of rows is reached
    int current_row = 0;
    char line[MAX_CHARACTERS_PER_LINE];
    while (fgets(line, MAX_CHARACTERS_PER_LINE, file) != NULL && current_row < MAX_ROWS) {
        // Split the line into columns by searching for commas and removing the newline character
        char* column_ptr = strtok(line, ",");
        int current_column = 0;
        while (column_ptr != NULL && current_column < MAX_COLUMNS_PER_LINE) {
            strtok(column_ptr, "\n"); // Remove newline character from the end of the column
            strcpy(lines[current_row][current_column], column_ptr); // Copy the column to the lines array
            column_ptr = strtok(NULL, ","); // Move to the next column
            current_column++;
        }
        current_row++;
    }

    // Close the file
    fclose(file);
}

int main() {
    process_csv_file("example.csv");
    printf("CSV file processed successfully!\n");

    // Print the lines array for testing purposes
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLUMNS_PER_LINE; j++) {
            printf("%s\t", lines[i][j]);
        }
        printf("\n");
    }

    return 0;
}