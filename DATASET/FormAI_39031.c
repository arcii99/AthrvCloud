//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

// Function to read CSV file and print its contents
int read_csv_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    
    if (file == NULL) {
        perror("Error: unable to open file");
        return 1;
    }
    
    char buffer[BUFFER_SIZE];
    char* value;
    int row = 0;
    int column = 0;

    // read each line of the file
    while (fgets(buffer, BUFFER_SIZE, file)) {
        column = 0;
        row++;

        // parse the line, separated by commas
        value = strtok(buffer, ",");

        // loop through each value in the row
        while (value) {
            column++;
            printf("Row %d, Column %d: %s\n", row, column, value);
            value = strtok(NULL, ",");
        }
    }

    fclose(file);
    return 0;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Error: usage: %s <filename>\n", argv[0]);
        return 1;
    }

    const char* filename = argv[1];

    if (read_csv_file(filename)) {
        printf("An error occurred while trying to read the CSV file.\n");
        return 1;
    }

    return 0;
}