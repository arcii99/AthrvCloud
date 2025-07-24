//FormAI DATASET v1.0 Category: Database Indexing System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    int key;
    char name[50];
} Record;

typedef struct {
    int index;
} Index;

void createIndex(Record *records, Index *index, int numRecords) {
    int i;
    for (i = 0; i < numRecords; i++) {
        index[i].index = (int)pow(records[i].key, 2);
    }
}

void searchIndex(Record *records, Index *index, int numRecords, int searchKey) {
    int i;
    printf("Searching for key %d...\n", searchKey);
    int searchIndex = (int)pow(searchKey, 2);
    for (i = 0; i < numRecords; i++) {
        if (index[i].index == searchIndex) {
            printf("Record found: %d, %s\n", records[i].key, records[i].name);
            return;
        }
    }
    printf("No record found.\n");
}

int main() {
    Record records[4] = {{1, "David"}, {2, "Sarah"}, {3, "John"}, {4, "Emily"}};
    Index index[4];

    // Create index
    createIndex(records, index, 4);

    // Search for records
    searchIndex(records, index, 4, 2);
    searchIndex(records, index, 4, 5);
    searchIndex(records, index, 4, 4);

    return 0;
}