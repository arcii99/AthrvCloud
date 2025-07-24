//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CSV_SIZE 1024

int main() {
    FILE* fp;
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    int row = 0, col = 0;
    char* csv_file_path = "example.csv";

    fp = fopen(csv_file_path, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file: %s\n", csv_file_path);
        exit(EXIT_FAILURE);
    }

    char csv_data[MAX_CSV_SIZE][MAX_CSV_SIZE];

    // Read CSV file from disk and convert to 2D array
    while ((read = getline(&line, &len, fp)) != -1) {
        col = 0;
        char* token = strtok(line, ",");
        while (token != NULL) {
            strncpy(csv_data[row][col], token, MAX_CSV_SIZE);
            col++;
            token = strtok(NULL, ",");
        }
        row++;
    }

    // Print contents of 2D array to console
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%s ", csv_data[i][j]);
        }
        printf("\n");
    }

    fclose(fp);
    if (line)
        free(line);

    return 0;
}