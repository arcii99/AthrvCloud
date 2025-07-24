//FormAI DATASET v1.0 Category: Database Indexing System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 10
#define MAX_NAME 20

typedef struct {
    char name[MAX_NAME];
} Column;

typedef struct {
    int id;
    char name[MAX_NAME];
    float score;
} Row;

typedef struct {
    Row rows[MAX_ROWS];
    int size;
} Index;

void add_row(Index *ind, int id, char *name, float score) {
    if (ind->size >= MAX_ROWS) {
        printf("Error: Index is full\n");
        return;
    }
    
    Row *row = &ind->rows[ind->size];
    row->id = id;
    strcpy(row->name, name);
    row->score = score;
    
    ind->size++;
}

int get_row_index(Index *ind, int id) {
    for (int i = 0; i < ind->size; i++) {
        if (ind->rows[i].id == id) {
            return i;
        }
    }
    
    return -1;
}

void print_row(Row *row) {
    printf("%d\t%s\t%.2f\n", row->id, row->name, row->score);
}

void print_index(Index *ind) {
    printf("ID\tName\tScore\n");
    for (int i = 0; i < ind->size; i++) {
        print_row(&ind->rows[i]);
    }
}

void update_score(Index *ind, int id, float score) {
    int idx = get_row_index(ind, id);
    if (idx == -1) {
        printf("Error: Row with ID %d is not found\n", id);
        return;
    }
    
    ind->rows[idx].score = score;
}

int main() {
    Index ind = {.size = 0};
    
    // Add some rows
    add_row(&ind, 1, "Alice", 85.0);
    add_row(&ind, 2, "Bob", 70.0);
    add_row(&ind, 3, "Charlie", 92.5);
    
    printf("Initial index:\n");
    print_index(&ind);
    
    // Update a score
    update_score(&ind, 2, 80.0);
    
    printf("Updated index:\n");
    print_index(&ind);
    
    // Add more rows
    add_row(&ind, 4, "David", 77.5);
    add_row(&ind, 5, "Emily", 95.0);
    
    printf("Extended index:\n");
    print_index(&ind);
    
    return 0;
}