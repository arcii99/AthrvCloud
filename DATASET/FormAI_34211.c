//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: Donald Knuth
// This CSV Reader example program is inspired by Donald Knuth's classic writing style and is designed to showcase C programming creativity.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for CSV file parsing
#define MAX_COLS 100
#define MAX_ROWS 1000
#define MAX_LINE_LEN 1024

// Define global variables for CSV file parsing
char csv[MAX_ROWS][MAX_COLS][MAX_LINE_LEN];
int rows, cols;

// Declare helper functions for CSV file parsing
int get_csv_num_rows(FILE *fp);
int get_csv_num_cols(FILE *fp);
void parse_csv_file(FILE *fp);

// Define main function
int main(int argc, char **argv) {
    // Check if file path is provided as a command line argument
    if(argc != 2) {
        printf("Error: Please provide the CSV file path as a command line argument.\n");
        return 1;
    }

    // Open the CSV file in read mode
    FILE *fp = fopen(argv[1], "r");

    // Check if file was opened successfully
    if(fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    // Parse the CSV file and store the data in the csv array
    parse_csv_file(fp);

    // Print the CSV data
    printf("CSV Data:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%s", csv[i][j]);
            if(j < cols-1) {
                printf(",");
            }
        }
        printf("\n");
    }

    // Close the file
    fclose(fp);

    return 0;
}

// Define helper function to get the number of rows in the CSV file
int get_csv_num_rows(FILE *fp) {
    int num_rows = 0;
    char line[MAX_LINE_LEN];

    while(fgets(line, MAX_LINE_LEN, fp) != NULL) {
        num_rows++;
    }

    // Reset file pointer to beginning of file
    rewind(fp);

    return num_rows;
}

// Define helper function to get the number of columns in the CSV file
int get_csv_num_cols(FILE *fp) {
    int num_cols = 0;
    char line[MAX_LINE_LEN];
    fgets(line, MAX_LINE_LEN, fp);

    char *token = strtok(line, ",");
    while(token != NULL) {
        num_cols++;
        token = strtok(NULL, ",");
    }

    // Reset file pointer to beginning of file
    rewind(fp);

    return num_cols;
}

// Define helper function to parse the CSV file and store data in csv array
void parse_csv_file(FILE *fp) {
    rows = get_csv_num_rows(fp);
    cols = get_csv_num_cols(fp);

    char line[MAX_LINE_LEN];
    int row = 0;
    while(fgets(line, MAX_LINE_LEN, fp) != NULL) {
        int col = 0;
        char *token = strtok(line, ",");
        while(token != NULL) {
            strcpy(csv[row][col], token);
            col++;
            token = strtok(NULL, ",");
        }
        row++;
    }
}