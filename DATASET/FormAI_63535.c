//FormAI DATASET v1.0 Category: Database simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct {
    int rows;
    int cols;
    int data[MAX_ROWS][MAX_COLS];
} Table;

void print_table(Table t) {
    for(int i=0; i<t.rows; i++) {
        for(int j=0; j<t.cols; j++) {
            printf("%d ", t.data[i][j]);
        }
        printf("\n");
    }
}

void insert_row(Table *t, int row_idx, int new_row[]) {
    if(t->rows >= MAX_ROWS || t->cols >= MAX_COLS) {
        printf("Table is full!\n");
        return;
    }
    if(row_idx < 0 || row_idx > t->rows) {
        printf("Invalid row index!\n");
        return;
    }
    
    // Shift existing rows down by one
    for(int i=t->rows-1; i>=row_idx; i--) {
        for(int j=0; j<t->cols; j++) {
            t->data[i+1][j] = t->data[i][j];
        }
    }
    
    // Insert new row at row_idx
    for(int i=0; i<t->cols; i++) {
        t->data[row_idx][i] = new_row[i];
    }
    t->rows++;
}

void delete_row(Table *t, int row_idx) {
    if(row_idx < 0 || row_idx >= t->rows) {
        printf("Invalid row index!\n");
        return;
    }
    
    // Shift existing rows up by one
    for(int i=row_idx; i<t->rows-1; i++) {
        for(int j=0; j<t->cols; j++) {
            t->data[i][j] = t->data[i+1][j];
        }
    }
    
    // Clear last row's data
    for(int i=0; i<t->cols; i++) {
        t->data[t->rows-1][i] = 0;
    }
    t->rows--;
}

int main() {
    Table my_table;
    my_table.rows = 3;
    my_table.cols = 3;
    int initial_data[MAX_ROWS][MAX_COLS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    memcpy(my_table.data, initial_data, MAX_ROWS * MAX_COLS * sizeof(int));
    print_table(my_table);
    printf("\n");
    
    int new_row[MAX_COLS] = {10, 11, 12};
    insert_row(&my_table, 1, new_row);
    print_table(my_table);
    printf("\n");
    
    delete_row(&my_table, 0);
    print_table(my_table);
    printf("\n");
    
    return 0;
}