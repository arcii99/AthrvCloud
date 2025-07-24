//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CSV_LINE_LENGTH 1024

int main() {
    // Open the CSV file for reading
    FILE *csv_file = fopen("sample.csv", "r");
    if (csv_file == NULL) {
        printf("Error: Could not open CSV file for reading.\n");
        return 1;
    }

    // Allocate memory for the CSV line buffer
    char *csv_line = (char*) malloc(sizeof(char) * MAX_CSV_LINE_LENGTH);

    // Parse the CSV file line by line
    while (fgets(csv_line, MAX_CSV_LINE_LENGTH, csv_file) != NULL) {
        // Strip the newline character from the end of the line
        csv_line[strcspn(csv_line, "\n")] = '\0';

        // Tokenize the CSV line using commas as the delimiter
        char *token;
        token = strtok(csv_line, ",");
        while (token != NULL) {
            // Print out each token in the CSV line
            printf("%s\n", token);

            // Move on to the next token
            token = strtok(NULL, ",");
        }
    }

    // Free the CSV line buffer and close the CSV file
    free(csv_line);
    fclose(csv_file);

    // Exit succesfully
    return 0;
}