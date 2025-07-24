//FormAI DATASET v1.0 Category: Database Indexing System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 1000

typedef struct {
    int id;
    char name[50];
} Record;

typedef struct {
    Record* records[TABLE_SIZE];
} HashTable;

int hash(char* key) {
    int hash_value = 0;
    for (int i = 0; i < strlen(key); i++) {
        hash_value += key[i];
    }
    return hash_value % TABLE_SIZE;
}

void insert_record(HashTable* table, Record* record) {
    int index = hash(record->name);
    while (table->records[index] != NULL) {
        index = (index + 1) % TABLE_SIZE;
    }
    table->records[index] = record;
}

Record* find_record(HashTable* table, char* name) {
    int index = hash(name);
    while (table->records[index] != NULL) {
        if (strcmp(table->records[index]->name, name) == 0) {
            return table->records[index];
        }
        index = (index + 1) % TABLE_SIZE;
    }
    return NULL;
}

int main() {
    HashTable table;
    memset(&table, 0, sizeof(HashTable));

    Record r1 = { 1, "John" };
    Record r2 = { 2, "Jane" };
    Record r3 = { 3, "Joe" };

    insert_record(&table, &r1);
    insert_record(&table, &r2);
    insert_record(&table, &r3);

    Record* result = find_record(&table, "Jane");
    if (result != NULL) {
        printf("Record found: id=%d name=%s\n", result->id, result->name);
    } else {
        printf("Record not found\n");
    }

    return 0;
}