//FormAI DATASET v1.0 Category: Database simulation ; Style: distributed
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_TABLE_SIZE 100

// Struct to hold information about each entry in the database
typedef struct {
    int id;
    char name[50];
    char email[50];
} Record;

// Struct to hold a table with multiple entries
typedef struct {
    int size;
    Record records[MAX_TABLE_SIZE];
} Table;

// Function to add a new record to the table
void addRecord(Table* table, int id, char* name, char* email) {
    if (table->size >= MAX_TABLE_SIZE) {
        printf("Table is full\n");
        return;
    }
    Record newRecord;
    newRecord.id = id;
    strcpy(newRecord.name, name);
    strcpy(newRecord.email, email);
    table->records[table->size++] = newRecord;
}

// Function to print all records in the table
void printTable(Table* table) {
    printf("Id\tName\tEmail\n");
    for (int i = 0; i < table->size; i++) {
        printf("%d\t%s\t%s\n", table->records[i].id, table->records[i].name, table->records[i].email);
    }
}

int main() {
    Table table;
    table.size = 0;

    addRecord(&table, 1, "Alice", "alice@example.com");
    addRecord(&table, 2, "Bob", "bob@example.com");
    addRecord(&table, 3, "Charlie", "charlie@example.com");

    printTable(&table);

    return 0;
}