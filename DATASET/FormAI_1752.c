//FormAI DATASET v1.0 Category: Database Indexing System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Record {
    int key;
    char name[50];
};

struct Index {
    int key;
    int pos;
};

void createIndex(struct Record db[], int n, struct Index idx[]) {
    int i, j;
    for (i = 0; i < n; i++) {
        idx[i].key = db[i].key;
        idx[i].pos = i;
    }
    // Sort the index based on key
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (idx[i].key > idx[j].key) {
                // Swap the elements in the index
                struct Index temp = idx[i];
                idx[i] = idx[j];
                idx[j] = temp;
            }
        }
    }
}

void search(struct Record db[], int n, struct Index idx[], int searchKey) {
    int i, low, high, mid;
    low = 0;
    high = n - 1;
    
    while (low <= high) {
        mid = (low + high) / 2;
        if (idx[mid].key > searchKey) {
            high = mid - 1;
        } else if (idx[mid].key < searchKey) {
            low = mid + 1;
        } else {
            printf("Record found at position %d\n", idx[mid].pos);
            printf("Name: %s\n", db[idx[mid].pos].name);
            return;
        }
    }
    printf("Record not found\n");
}

int main() {
    struct Record db[MAX] = {
        {10, "John"},
        {20, "Jane"},
        {30, "Bob"},
        {40, "Alice"},
        {50, "Mike"}
    };
    struct Index idx[MAX];
    int n = 5;
    int i;

    createIndex(db, n, idx);
    
    // Print the index
    printf("INDEX\n");
    for (i = 0; i < n; i++) {
        printf("key: %d\tpos: %d\n", idx[i].key, idx[i].pos);
    }
    
    // Search for a record
    int searchKey = 30;
    printf("\nSearching for record with key %d\n", searchKey);
    search(db, n, idx, searchKey);
    
    return 0;
}