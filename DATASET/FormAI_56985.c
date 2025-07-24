//FormAI DATASET v1.0 Category: Database Indexing System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_RECORDS 1000

typedef struct {
    int id;
    char name[50];
    int age;
} Record;

typedef struct {
    int key;
    int offset;
} Index;

typedef struct {
    Index indices[MAX_RECORDS];
    int size;
} IndexTable;

int compare(const void *a, const void *b) {
    Index *indexA = (Index*) a;
    Index *indexB = (Index*) b;
    return indexA->key - indexB->key;
}

int search(IndexTable *table, int key) {
    int left = 0;
    int right = table->size - 1;

    while (left <= right) {
        int middle = (left + right) / 2;
        if (table->indices[middle].key == key) {
            return table->indices[middle].offset;
        }
        else if (table->indices[middle].key < key) {
            left = middle + 1;
        }
        else {
            right = middle - 1;
        }
    }

    return -1;
}

void insert(Record *record, IndexTable *table, FILE *dataFile, FILE *indexFile) {
    fseek(dataFile, 0, SEEK_END);
    int offset = ftell(dataFile);

    fwrite(record, sizeof(Record), 1, dataFile);

    table->indices[table->size].key = record->id;
    table->indices[table->size].offset = offset;
    table->size++;

    qsort(table->indices, table->size, sizeof(Index), compare);

    fseek(indexFile, 0, SEEK_SET);
    fwrite(table, sizeof(IndexTable), 1, indexFile);
}

int main() {
    FILE *dataFile = fopen("data.db", "wb+");
    FILE *indexFile = fopen("index.db", "wb+");

    IndexTable table = {{0}, 0};

    fwrite(&table, sizeof(IndexTable), 1, indexFile);

    Record records[] = {
        {1, "Alice", 25},
        {2, "Bob", 30},
        {3, "Charlie", 35},
        {4, "David", 40},
        {5, "Emily", 45},
        {6, "Frank", 50},
        {7, "Grace", 55},
        {8, "Henry", 60},
        {9, "Isabelle", 65},
        {10, "Jack", 70}
    };

    for (int i = 0; i < 10; i++) {
        insert(&records[i], &table, dataFile, indexFile);
    }

    int idToSearch = 8;
    int offset = search(&table, idToSearch);

    if (offset == -1) {
        printf("Record with id %d not found.\n", idToSearch);
    }
    else {
        Record record;
        fseek(dataFile, offset, SEEK_SET);
        fread(&record, sizeof(Record), 1, dataFile);
        printf("Record with id %d found: name=%s, age=%d.\n", record.id, record.name, record.age);
    }

    fclose(dataFile);
    fclose(indexFile);

    return 0;
}