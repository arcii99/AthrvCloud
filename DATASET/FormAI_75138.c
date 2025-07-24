//FormAI DATASET v1.0 Category: Database Indexing System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key;
    int index;
} Record;

void insert(Record *records, int key, int *size) {
    int i = *size - 1;
    while (i >= 0 && records[i].key > key) {
        records[i + 1].key = records[i].key;
        records[i + 1].index = records[i].index;
        i--;
    }
    records[i + 1].key = key;
    records[i + 1].index = *size;
    *size += 1;
}

int search(Record *records, int key, int size) {
    int i = size - 1;
    while (i >= 0 && records[i].key >= key) {
        i--;
    }
    if (i == size - 1) {
        return -1;
    }
    return records[i + 1].index;
}

int main() {
    Record records[100];
    int size = 0;

    insert(records, 7, &size);
    insert(records, 4, &size);
    insert(records, 9, &size);
    insert(records, 2, &size);
    insert(records, 5, &size);

    int index = search(records, 5, size);
    if (index == -1) {
        printf("Key not found.\n");
    } else {
        printf("Key found at index %d.\n", index);
    }

    return 0;
}