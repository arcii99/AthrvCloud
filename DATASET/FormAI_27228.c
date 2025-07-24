//FormAI DATASET v1.0 Category: Database simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TABLE_SIZE 100 // maximum number of records in the table

// structure representing a record in the table
typedef struct Record {
    int id;
    char name[50];
    int age;
} Record;

// structure representing the database table
typedef struct Table {
    Record records[MAX_TABLE_SIZE];
    int size;
} Table;

// function for adding a new record to the table
void addRecord(Table* table, Record record) {
    if (table->size >= MAX_TABLE_SIZE) {
        printf("Error: Cannot add record, table is full.\n");
        return;
    }
    table->records[table->size++] = record;
}

// function for finding a record based on its id
Record* findById(Table* table, int id) {
    for (int i = 0; i < table->size; i++) {
        if (table->records[i].id == id) {
            return &table->records[i];
        }
    }
    return NULL;
}

// function for deleting a record based on its id
void deleteById(Table* table, int id) {
    int index = -1;
    for (int i = 0; i < table->size; i++) {
        if (table->records[i].id == id) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Error: Record with id %d does not exist.\n", id);
        return;
    }
    for (int i = index; i < table->size - 1; i++) {
        table->records[i] = table->records[i+1];
    }
    table->size--;
}

// example usage of the table functions
int main() {
    Table table;
    table.size = 0;
    Record record;
    record.id = 1;
    strcpy(record.name, "John");
    record.age = 30;
    addRecord(&table, record);
    record.id = 2;
    strcpy(record.name, "Jane");
    record.age = 25;
    addRecord(&table, record);
    Record* foundRecord = findById(&table, 1);
    if (foundRecord != NULL) {
        printf("Found record: id=%d name=%s age=%d\n", foundRecord->id, foundRecord->name, foundRecord->age);
    } else {
        printf("Record not found.\n");
    }
    deleteById(&table, 2);
    return 0;
}