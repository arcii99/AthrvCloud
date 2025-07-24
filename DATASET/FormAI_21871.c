//FormAI DATASET v1.0 Category: Database Indexing System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_RECORDS 100

struct Record {
    int id;
    char name[50];
    int age;
};

struct IndexNode {
    int key;
    int pos;
};

struct Index {
    int size;
    struct IndexNode nodes[MAX_RECORDS];
};

struct Database {
    int count;
    struct Record records[MAX_RECORDS];
    struct Index index;
};

void addToIndex(struct Index* index, int key, int pos) {
    index->nodes[index->size].key = key;
    index->nodes[index->size].pos = pos;
    index->size++;
}

void indexRecords(struct Database* db) {
    db->index.size = 0;
    for (int i = 0; i < db->count; i++) {
        addToIndex(&db->index, db->records[i].id, i);
    }
}

void displayRecord(struct Record* record) {
    printf("ID: %d\n", record->id);
    printf("Name: %s\n", record->name);
    printf("Age: %d\n", record->age);
}

void displayIndex(struct Index* index) {
    for (int i = 0; i < index->size; i++) {
        printf("%d: %d\n", index->nodes[i].key, index->nodes[i].pos);
    }
}

int binarySearch(struct IndexNode* nodes, int size, int key) {
    int start = 0;
    int end = size - 1;
    while (start <= end) {
        int middle = (start + end) / 2;
        if (nodes[middle].key == key) {
            return nodes[middle].pos;
        } else if (nodes[middle].key > key) {
            end = middle - 1;
        } else {
            start = middle + 1;
        }
    }
    return -1;
}

int searchRecord(struct Database* db, int id) {
    int pos = binarySearch(db->index.nodes, db->index.size, id);
    if (pos < 0) {
        printf("Record with ID %d not found.\n", id);
    } else {
        displayRecord(&db->records[pos]);
    }
    return pos;
}

int addRecord(struct Database* db, struct Record* record) {
    if (db->count >= MAX_RECORDS) {
        printf("Database is full.\n");
        return -1;
    }
    db->records[db->count] = *record;
    int pos = db->count;
    db->count++;
    addToIndex(&db->index, record->id, pos);
    printf("Record added.\n");
    return pos;
}

bool deleteRecord(struct Database* db, int id) {
    int pos = binarySearch(db->index.nodes, db->index.size, id);
    if (pos < 0) {
        printf("Record with ID %d not found.\n", id);
        return false;
    }
    for (int i = pos; i < db->count - 1; i++) {
        db->records[i] = db->records[i + 1];
    }
    db->count--;
    for (int i = 0; i < db->index.size; i++) {
        if (db->index.nodes[i].pos == pos) {
            for (int j = i; j < db->index.size - 1; j++) {
                db->index.nodes[j] = db->index.nodes[j + 1];
            }
            db->index.size--;
            break;
        }
    }
    printf("Record deleted.\n");
    return true;
}

int main() {
    struct Database db;
    db.count = 0;
    db.index.size = 0;

    struct Record record1 = {1, "John Doe", 25};
    struct Record record2 = {2, "Jane Smith", 30};
    struct Record record3 = {3, "Bob Johnson", 20};

    addRecord(&db, &record1);
    addRecord(&db, &record2);
    addRecord(&db, &record3);
    indexRecords(&db);

    searchRecord(&db, 2);
    deleteRecord(&db, 2);
    searchRecord(&db, 2);
    displayIndex(&db.index);
    
    return 0;
}