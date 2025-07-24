//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLS 20
#define MAX_ROWS 100

/* Initialize the CSV Reader */
void init_csv_reader(char *filename, char *delim, char **fields, int *num_cols)
{
    FILE *fptr = fopen(filename, "r");

    if (fptr == NULL) {
        printf("Error: Unable to open file\n");
        exit(1);
    }

    /* Read the first row to determine the number of columns */
    char row[MAX_ROWS];
    fgets(row, MAX_ROWS, fptr);

    *num_cols = 0;
    char *token = strtok(row, delim);
    while (token != NULL && *num_cols < MAX_COLS) {
        fields[*num_cols] = token;
        (*num_cols)++;
        token = strtok(NULL, delim);
    }

    fclose(fptr);
}

/* Read a Row from the CSV file */
int read_csv_row(char *filename, char *delim, char *row, int row_len)
{
    FILE *fptr = fopen(filename, "r");

    if (fptr == NULL) {
        printf("Error: Unable to open file\n");
        exit(1);
    }

    /* Skip the first row */
    char first_row[MAX_ROWS];
    fgets(first_row, MAX_ROWS, fptr);

    /* Read the next row */
    fgets(row, row_len, fptr);
    char *pos = strchr(row, '\n');
    if (pos != NULL) {
        *pos = '\0';
    }

    fclose(fptr);

    return strlen(row);
}

/* Main function */
int main()
{
    char *filename = "data.csv";
    char *delim = ",";
    char *fields[MAX_COLS];
    int num_cols = 0;

    init_csv_reader(filename, delim, fields, &num_cols);

    for (int i = 0; i < num_cols; i++) {
        printf("%s ", fields[i]);
    }
    printf("\n");

    char row[MAX_ROWS];
    while (read_csv_row(filename, delim, row, MAX_ROWS) > 0) {
        printf("%s\n", row);
    }

    return 0;
}