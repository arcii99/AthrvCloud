//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum line length for the file
#define MAX_LINE_LENGTH 1000

/* Define struct for reading CSV file */
typedef struct {
    char* filename;
    char delimiter;
} CSVReader;

/* Define struct for storing CSV data */
typedef struct {
    int rows;
    int cols;
    char** data;
} CSVData;

/* Function to read CSV file */
CSVData read_csv(CSVReader reader) {
    CSVData data;
    data.rows = 0;
    data.cols = 0;
    data.data = NULL;
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    int i = 0;
    FILE* file = fopen(reader.filename, "r");
    if (file == NULL) {
        printf("Error: Unable to open file '%s'.\n", reader.filename);
        exit(EXIT_FAILURE);
    }
    while ((read = getline(&line, &len, file)) != -1) {
        char* token = strtok(line, &reader.delimiter);
        int j = 0;
        while (token != NULL) {
            // Reallocate memory for each column
            data.data = realloc(data.data, (i + 1) * sizeof(char*));
            data.data[i] = realloc(data.data[i], (j + 1) * sizeof(char));
            strcpy(data.data[i][j], token);
            token = strtok(NULL, &reader.delimiter);
            j++;
        }
        if (i == 0) {
            data.cols = j;
        }
        i++;
    }
    data.rows = i;
    fclose(file);
    if (line) {
        free(line);
    }
    return data;
}

/* Function to print CSV data */
void print_csv(CSVData data) {
    int i, j;
    for (i = 0; i < data.rows; i++) {
        for (j = 0; j < data.cols; j++) {
            printf("%s\t", data.data[i][j]);
        }
        printf("\n");
    }  
}

/* Main function */
int main(int argc, char** argv) {
    CSVReader reader = {"data.csv", ','};
    CSVData data = read_csv(reader);
    printf("CSV data:\n");
    print_csv(data);
    return 0;
}