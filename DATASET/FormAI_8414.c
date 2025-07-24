//FormAI DATASET v1.0 Category: Database Indexing System ; Style: Donald Knuth
#include <stdio.h>

#define MAX_ROWS 10
#define MAX_COLS 5

typedef struct {
    int values[MAX_COLS];
} row_t;

row_t table[MAX_ROWS];
int index[MAX_ROWS];

int compare_rows(const void* a, const void* b) {
    row_t* row_a = (row_t*) a;
    row_t* row_b = (row_t*) b;
    return row_a->values[0] - row_b->values[0];
}

void create_index() {
    for (int i = 0; i < MAX_ROWS; i++) {
        index[i] = i;
    }
    qsort(index, MAX_ROWS, sizeof(int), compare_rows);
}

int find_row(int key) {
    int left = 0;
    int right = MAX_ROWS - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        int row_index = index[mid];
        row_t* row = &table[row_index];
        if (row->values[0] == key) {
            return row_index;
        } else if (row->values[0] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    // populate table
    for (int i = 0; i < MAX_ROWS; i++) {
        table[i].values[0] = i;
        table[i].values[1] = rand() % 100;
        table[i].values[2] = rand() % 100;
        table[i].values[3] = rand() % 100;
        table[i].values[4] = rand() % 100;
    }
    
    // create index
    create_index();
    
    // search for rows
    int key = 5;
    int row_index = find_row(key);
    if (row_index == -1) {
        printf("Row with key %d not found\n", key);
    } else {
        printf("Row with key %d found at index %d\n", key, row_index);
    }
    
    key = 15;
    row_index = find_row(key);
    if (row_index == -1) {
        printf("Row with key %d not found\n", key);
    } else {
        printf("Row with key %d found at index %d\n", key, row_index);
    }
    
    return 0;
}