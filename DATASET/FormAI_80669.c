//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLS 50
#define MAX_ROWS 100

void read_csv(const char *filename, int *data, int *rows, int *cols)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char line[BUFSIZ], *ptr;
    int row_count = 0, col_count = 0;
    while (fgets(line, BUFSIZ, fp) && row_count < MAX_ROWS)
    {
        ptr = strtok(line, ",");
        while (ptr != NULL && col_count < MAX_COLS)
        {
            data[row_count * MAX_COLS + col_count] = atoi(ptr);
            ptr = strtok(NULL, ",");
            col_count++;
        }
        row_count++;
        col_count = 0;
    }
    fclose(fp);

    *rows = row_count;
    *cols = col_count;
}

void print_csv(int *data, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", data[i * MAX_COLS + j]);
        }
        printf("\n");
    }
}

int main()
{
    int data[MAX_ROWS * MAX_COLS];
    int rows, cols;

    printf("Reading in data from example.csv...\n");
    read_csv("example.csv", data, &rows, &cols);

    printf("Printing out data from example.csv...\n");
    print_csv(data, rows, cols);

    return 0;
}