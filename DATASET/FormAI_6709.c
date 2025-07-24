//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to get number of columns in CSV file
int get_num_cols(char *line, char *delimiter) {
    int num_cols = 0;
    char *token = strtok(line, delimiter);
    while(token != NULL) {
        num_cols++;
        token = strtok(NULL, delimiter);
    }
    return num_cols;
}

// Function to parse CSV file and store data in 2D array
void read_csv(char *filename, char *delimiter, char ***data, int *num_rows, int *num_cols) {
    FILE *fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    // Read header line to get number of columns
    if((read = getline(&line, &len, fp)) != -1) {
        *num_cols = get_num_cols(line, delimiter);
    }

    // Allocate memory for data array
    *data = (char **) malloc(sizeof(char *) * (*num_cols));
    for(int i=0; i<*num_cols; i++) {
        (*data)[i] = (char *) malloc(sizeof(char) * 100);
    }

    // Read rest of the lines to get data
    int row = 0;
    while((read = getline(&line, &len, fp)) != -1) {
        char *token = strtok(line, delimiter);
        int col = 0;
        while(token != NULL) {
            strcpy((*data)[(row * *num_cols) + col], token);
            col++;
            token = strtok(NULL, delimiter);
        }
        row++;
        (*num_rows)++;
    }

    fclose(fp);
    if(line) free(line);
}

int main() {
    char *filename = "data.csv";
    char *delimiter = ",";
    char **data;
    int num_rows = 0, num_cols = 0;

    read_csv(filename, delimiter, &data, &num_rows, &num_cols);

    // Print data
    printf("Number of rows: %d\n", num_rows);
    printf("Number of cols: %d\n", num_cols);
    printf("\nData:\n");
    for(int i=0; i<num_rows; i++) {
        for(int j=0; j<num_cols; j++) {
            printf("%s\t", data[(i * num_cols) + j]);
        }
        printf("\n");
    }

    // Free memory
    for(int i=0; i<num_cols; i++) {
        free(data[i]);
    }
    free(data);

    return EXIT_SUCCESS;
}