//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a line in a CSV file
#define MAX_LINE_LEN 1024

// Define the maximum number of columns in a CSV file
#define MAX_COLUMNS 100

// Define the structure to hold the CSV data
typedef struct _csv_data_t {
    int num_cols;
    int num_rows;
    char** data;
} csv_data_t;

// Define the function to read the CSV data from a file
csv_data_t* read_csv_file(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Unable to open file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    // Count the number of rows in the CSV file
    int num_rows = 0;
    char buffer[MAX_LINE_LEN];
    while (fgets(buffer, MAX_LINE_LEN, fp) != NULL) {
        num_rows++;
    }
    rewind(fp);

    // Allocate memory for the CSV data structure
    csv_data_t* csv_data = (csv_data_t*) malloc(sizeof(csv_data_t));
    if (csv_data == NULL) {
        fprintf(stderr, "Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }
    csv_data->num_rows = num_rows;
    csv_data->num_cols = 0;
    csv_data->data = (char**) malloc(num_rows * sizeof(char*));
    if (csv_data->data == NULL) {
        fprintf(stderr, "Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }

    // Read in the CSV data
    int i, j;
    for (i = 0; i < num_rows; i++) {
        if (fgets(buffer, MAX_LINE_LEN, fp) == NULL) {
            fprintf(stderr, "Error: not enough rows in file.\n");
            exit(EXIT_FAILURE);
        }
        int len = strlen(buffer);
        if (len > 0 && buffer[len-1] == '\n') {
            buffer[len-1] = '\0';
        }

        // Tokenize the CSV line and store the data
        char* token = strtok(buffer, ",");
        j = 0;
        while (token != NULL) {
            if (j >= MAX_COLUMNS) {
                fprintf(stderr, "Error: too many columns in file.\n");
                exit(EXIT_FAILURE);
            }
            if (i == 0) {
                csv_data->num_cols++;
            }
            if (csv_data->data[i] == NULL) {
                csv_data->data[i] = (char*) malloc(MAX_LINE_LEN * sizeof(char));
                if (csv_data->data[i] == NULL) {
                    fprintf(stderr, "Memory allocation error.\n");
                    exit(EXIT_FAILURE);
                }
            }
            strcpy(csv_data->data[i] + strlen(csv_data->data[i]), token);
            strcat(csv_data->data[i], ",");
            token = strtok(NULL, ",");
            j++;
        }
    }

    fclose(fp);

    return csv_data;
}

// Define the main function
int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        return 1;
    }

    // Read in the CSV data
    csv_data_t* csv_data = read_csv_file(argv[1]);

    // Print out the CSV data
    int i, j;
    for (i = 0; i < csv_data->num_rows; i++) {
        for (j = 0; j < csv_data->num_cols; j++) {
            printf("%s ", csv_data->data[i] + j * (MAX_LINE_LEN + 1));
        }
        printf("\n");
    }

    // Free the memory used by the CSV data
    for (i = 0; i < csv_data->num_rows; i++) {
        free(csv_data->data[i]);
    }
    free(csv_data->data);
    free(csv_data);

    return 0;
}