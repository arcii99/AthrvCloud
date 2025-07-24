//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024
#define MAX_FIELD_SIZE 64
#define MAX_COLUMNS 10
#define MAX_ROWS 100

int main(void) {
    // Open CSV file for reading
    FILE *file = fopen("example.csv", "r");
    if (!file) {
        printf("Error: Failed to open file\n");
        return 1;
    }

    // Initialize variables for storing data
    char buffer[MAX_BUFFER_SIZE];
    char fields[MAX_ROWS][MAX_COLUMNS][MAX_FIELD_SIZE];
    int row_count = 0;
    int col_count = 0;

    // Read each line of the CSV file
    while (fgets(buffer, MAX_BUFFER_SIZE, file)) {
        // Split the line into fields
        char *field = strtok(buffer, ",");
        while (field) {
            // Copy field to array
            strncpy(fields[row_count][col_count], field, MAX_FIELD_SIZE);
            // Remove newline character
            if (fields[row_count][col_count][strlen(fields[row_count][col_count]) - 1] == '\n') {
                fields[row_count][col_count][strlen(fields[row_count][col_count]) - 1] = '\0';
            }
            // Increment column count and get next field
            col_count++;
            field = strtok(NULL, ",");
        }
        // Increment row count and reset column count
        row_count++;
        col_count = 0;
    }

    // Close the file
    fclose(file);

    // Print the data
    for (int i = 0; i < row_count; i++) {
        for (int j = 0; j < col_count; j++) {
            printf("%s ", fields[i][j]);
        }
        printf("\n");
    }

    return 0;
}