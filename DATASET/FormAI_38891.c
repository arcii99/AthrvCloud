//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define DELIMITER ","

int main(int argc, char **argv) {
    char filename[BUFFER_SIZE], line[BUFFER_SIZE];
    FILE *file;
    char *token;
    int row_count = 0;
    int column_count = 0;

    // Get the filename from user input
    printf("Enter the name of the CSV file: ");
    fgets(filename, BUFFER_SIZE, stdin);
    strtok(filename, "\n");

    // Open the file
    file = fopen(filename, "r");
    if (!file) {
        printf("Error: Unable to open file %s", filename);
        return -1;
    }

    // Read the file line by line
    while (fgets(line, BUFFER_SIZE, file)) {
        row_count++; // Increase the row count for each line read
        column_count = 0;

        // Parse the line using the delimiter
        token = strtok(line, DELIMITER);

        while(token) {
            column_count++; // Increase the column count for each token found
            printf("%s ", token); // Print the token
            token = strtok(NULL, DELIMITER);
        }

        // Print a newline after each row
        printf("\n");
    }

    // Close the file
    fclose(file);

    // Print result
    printf("Number of rows: %d\n", row_count);
    printf("Number of columns: %d\n", column_count);

    return 0;
}