//FormAI DATASET v1.0 Category: Database Indexing System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_NAME_LEN 50
#define MAX_PHONE_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
} Record;

typedef struct {
    Record records[MAX_RECORDS];
    int num_records;
} Table;

typedef struct {
    char name[MAX_NAME_LEN];
    int index;
} Index;

typedef struct {
    Index indexes[MAX_RECORDS];
    int num_indexes;
} IndexTable;

void add_record(Table *table, const char *name, const char *phone) {
    if (table->num_records >= MAX_RECORDS) {
        printf("Error: Table is full\n");
        return;
    }
    Record record;
    strncpy(record.name, name, MAX_NAME_LEN);
    strncpy(record.phone, phone, MAX_PHONE_LEN);
    table->records[table->num_records] = record;
    table->num_records++;
}

IndexTable create_index(Table *table) {
    IndexTable index_table;
    for (int i = 0; i < table->num_records; i++) {
        Index index;
        strncpy(index.name, table->records[i].name, MAX_NAME_LEN);
        index.index = i;
        index_table.indexes[index_table.num_indexes] = index;
        index_table.num_indexes++;
    }
    return index_table;
}

void print_record(const Record *record) {
    printf("%s: %s\n", record->name, record->phone);
}

void print_records(Table *table) {
    for (int i = 0; i < table->num_records; i++) {
        print_record(&table->records[i]);
    }
}

void print_index(const Index *index) {
    printf("%s: %d\n", index->name, index->index);
}

void print_indexes(IndexTable *index_table) {
    for (int i = 0; i < index_table->num_indexes; i++) {
        print_index(&index_table->indexes[i]);
    }
}

int search_records(Table *table, const char *name, IndexTable *index_table) {
    for (int i = 0; i < index_table->num_indexes; i++) {
        if (strcmp(name, index_table->indexes[i].name) == 0) {
            return index_table->indexes[i].index;
        }
    }
    printf("Error: Record not found\n");
    return -1;
}

int main() {
    Table table = { .num_records = 0 };
    IndexTable index_table = { .num_indexes = 0 };

    add_record(&table, "Alice", "123-4567");
    add_record(&table, "Bob", "234-5678");
    add_record(&table, "Charlie", "345-6789");
    add_record(&table, "David", "456-7890");

    printf("Records:\n");
    print_records(&table);

    printf("Creating index...\n");
    index_table = create_index(&table);

    printf("Indexes:\n");
    print_indexes(&index_table);

    printf("Searching for Alice...\n");
    int alice_index = search_records(&table, "Alice", &index_table);
    if (alice_index != -1) {
        printf("Record found:\n");
        print_record(&table.records[alice_index]);
    }

    return 0;
}