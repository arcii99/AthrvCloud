//FormAI DATASET v1.0 Category: Data mining ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROW 100
#define MAX_COL 100
#define MAX_BUF 1000

void read_csv_file(char file_name[], int data[MAX_ROW][MAX_COL], int *num_rows, int *num_cols) {
    FILE *fp;
    char buf[MAX_BUF];
    char *p;
    int row = 0;
    int col = 0;

    fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Error: Cannot open file %s\n", file_name);
        exit(1);
    }

    while (fgets(buf, MAX_BUF, fp) != NULL) {
        col = 0;
        p = strtok(buf, ",");
        while (p != NULL) {
            data[row][col++] = atoi(p);
            p = strtok(NULL, ",");
        }
        row++;
    }

    *num_rows = row;
    *num_cols = col;

    fclose(fp);
}

void print_data(int data[MAX_ROW][MAX_COL], int num_rows, int num_cols) {
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            printf("%d ", data[i][j]);
        }
        printf("\n");
    }
}

void data_mining_example(int data[MAX_ROW][MAX_COL], int num_rows, int num_cols) {
    int max_row_sum = -1;
    int max_row_copy[MAX_COL];
    int temp_sum = 0;

    for (int i = 0; i < num_rows; i++) {
        temp_sum = 0;
        for (int j = 0; j < num_cols; j++) {
            temp_sum += data[i][j];
        }
        if (temp_sum > max_row_sum) {
            max_row_sum = temp_sum;
            for (int k = 0; k < num_cols; k++) {
                max_row_copy[k] = data[i][k];
            }
        }
    }

    printf("The row with the highest sum is:\n");
    for (int i = 0; i < num_cols; i++) {
        printf("%d ", max_row_copy[i]);
    }
    printf("\n");
}

int main() {
    int data[MAX_ROW][MAX_COL];
    int num_rows = 0;
    int num_cols = 0;
    char file_name[] = "data.csv";

    read_csv_file(file_name, data, &num_rows, &num_cols);
    print_data(data, num_rows, num_cols);
    printf("Performing data mining...\n");
    data_mining_example(data, num_rows, num_cols);

    return 0;
}