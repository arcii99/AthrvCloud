//FormAI DATASET v1.0 Category: Database Indexing System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct {
    int id;
    char name[50];
    int age;
    double salary;
} Record;

typedef struct {
    Record data[MAX_RECORDS];
    int count;
} Database;

typedef struct {
    int key;
    int recordId;
} Index;

typedef struct {
    Index data[MAX_RECORDS];
    int count;
} IndexTable;

void addRecord(Database *db, int id, char *name, int age, double salary);
void displayRecords(Database *db);
void addIndex(IndexTable *indexTable, int key, int recordId);
int searchIndex(IndexTable *indexTable, int key);

int main() {
    Database db;
    db.count = 0;

    IndexTable indexTable;
    indexTable.count = 0;

    addRecord(&db, 1, "John Smith", 25, 2500);
    addRecord(&db, 2, "Mary Johnson", 32, 4300);
    addRecord(&db, 3, "David Lee", 41, 6700);
    addRecord(&db, 4, "Jessica Adams", 29, 3800);
    addRecord(&db, 5, "Robert Wilson", 36, 5200);

    for (int i = 0; i < db.count; i++) {
        addIndex(&indexTable, db.data[i].id, i);
    }

    printf("Enter ID to search: ");
    int searchId;
    scanf("%d", &searchId);

    int recordIndex = searchIndex(&indexTable, searchId);

    if (recordIndex == -1) {
        printf("Record not found\n");
    } else {
        printf("ID\tName\t\t\tAge\tSalary\n");
        printf("%d\t%-20s%d\t$%.2f", db.data[recordIndex].id, db.data[recordIndex].name,
            db.data[recordIndex].age, db.data[recordIndex].salary);
    }

    return 0;
}

void addRecord(Database *db, int id, char *name, int age, double salary) {
    if (db->count >= MAX_RECORDS) {
        printf("Database is full\n");
        return;
    }

    Record newRecord = {id, "", age, salary};
    strncpy(newRecord.name, name, 50);

    db->data[db->count] = newRecord;
    db->count++;
}

void displayRecords(Database *db) {
    printf("ID\tName\t\t\tAge\tSalary\n");
    for (int i = 0; i < db->count; i++) {
        printf("%d\t%-20s%d\t$%.2f\n", db->data[i].id, db->data[i].name,
            db->data[i].age, db->data[i].salary);
    }
}

void addIndex(IndexTable *indexTable, int key, int recordId) {
    if (indexTable->count >= MAX_RECORDS) {
        printf("Index table is full\n");
        return;
    }

    Index newIndex = {key, recordId};

    indexTable->data[indexTable->count] = newIndex;
    indexTable->count++;
}

int searchIndex(IndexTable *indexTable, int key) {
    for (int i = 0; i < indexTable->count; i++) {
        if (indexTable->data[i].key == key) {
            return indexTable->data[i].recordId;
        }
    }

    return -1;
}