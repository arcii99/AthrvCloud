//FormAI DATASET v1.0 Category: Database Indexing System ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 50
#define MAX_INDEX_SIZE 100

typedef struct index_t {
    int key;
    int value;
} index_t;

typedef struct database_t {
    char name[MAX_STRING_LENGTH];
    int size;
    index_t index[MAX_INDEX_SIZE];
} database_t;

void add_database(database_t* db, char* name, int size) {
    strncpy(db->name, name, MAX_STRING_LENGTH);
    db->size = size;
    for (int i = 0; i < size; i++) {
        db->index[i].key = i;
        db->index[i].value = rand() % 100;
    }
}

void print_database(database_t db) {
    printf("Database: %s\n", db.name);
    for (int i = 0; i < db.size; i++) {
        printf("Key: %d\tValue: %d\n", db.index[i].key, db.index[i].value);
    }
}

void sort_index(database_t* db) {
    for (int i = 0; i < db->size-1; i++) {
        for (int j = i+1; j < db->size; j++) {
            if (db->index[i].value > db->index[j].value) {
                int tmp_key = db->index[i].key;
                int tmp_val = db->index[i].value;
                db->index[i].key = db->index[j].key;
                db->index[i].value = db->index[j].value;
                db->index[j].key = tmp_key;
                db->index[j].value = tmp_val;
            }
        }
    }
}

int binary_search(database_t db, int value) {
    int start = 0;
    int end = db.size - 1;
    int mid = (start+end)/2;
    while (start <= end) {
        if (db.index[mid].value == value) {
            return db.index[mid].key;
        } else if (db.index[mid].value > value) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
        mid = (start + end) / 2;
    }
    return -1;
}

int main(void) {
    database_t db;
    add_database(&db, "Test Database", 10);
    printf("Unsorted Database:\n");
    print_database(db);
    sort_index(&db);
    printf("\nSorted Database:\n");
    print_database(db);
    int target_value = 42;
    int search_res = binary_search(db, target_value);
    if (search_res == -1) {
        printf("\nValue %d not found in database.\n", target_value);
    } else {
        printf("\nValue %d found at key: %d\n", target_value, search_res);
    }

    return 0;
}