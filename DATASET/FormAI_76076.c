//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLUMN 1000
#define MAX_NAME 100

int main() {
    char file_name[MAX_NAME];
    FILE *csv_file;
    char line[MAX_COLUMN];
    char *token;
    int row_count = 0;

    printf("Please enter the name of CSV file to read: ");
    scanf("%s", file_name);

    csv_file = fopen(file_name, "r");
    if (csv_file == NULL) {
        printf("Failed to open the file: %s\n", file_name);
        return 1;
    }

    printf("CSV file contents:\n");

    // Read and print each line in the CSV file.
    while (fgets(line, MAX_COLUMN, csv_file)) {
        row_count++;
        printf("Row %d: ", row_count);

        // Parse each column in the line.
        token = strtok(line, ",");
        while (token != NULL) {
            printf("%s\t", token);
            token = strtok(NULL, ",");
        }

        printf("\n");
    }

    fclose(csv_file);
    return 0;
}