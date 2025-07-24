//FormAI DATASET v1.0 Category: Database Indexing System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000 // maximum number of elements allowed in the database
#define FIELD_SIZE 20 // maximum size of each field in the database

typedef struct {
    char field1[FIELD_SIZE];
    char field2[FIELD_SIZE];
    char field3[FIELD_SIZE];
} Record;

typedef struct {
    Record record;
    int position; // position of the record in the database file
} IndexedRecord;

typedef struct {
    IndexedRecord records[MAX_SIZE];
    int size; // current size of the index
} Index;

// function to add a record to the database and update the index
void add_record(char* filename, Index* index, char* field1, char* field2, char* field3) {
    FILE* fp = fopen(filename, "a");
    if (fp == NULL) {
        printf("Error opening database file.\n");
        return;
    }
    Record record;
    strcpy(record.field1, field1);
    strcpy(record.field2, field2);
    strcpy(record.field3, field3);
    fwrite(&record, sizeof(record), 1, fp);
    fclose(fp);

    IndexedRecord indexed_record;
    strcpy(indexed_record.record.field1, field1);
    strcpy(indexed_record.record.field2, field2);
    strcpy(indexed_record.record.field3, field3);
    indexed_record.position = index->size;
    index->records[index->size++] = indexed_record;
}

// function to find all records that match a given field
void find_records(Index index, char* field, int field_num) {
    int i;
    for (i = 0; i < index.size; i++) {
        char* field_value;
        if (field_num == 1) {
            field_value = index.records[i].record.field1;
        } else if (field_num == 2) {
            field_value = index.records[i].record.field2;
        } else {
            field_value = index.records[i].record.field3;
        }
        if (strcmp(field_value, field) == 0) {
            printf("%s %s %s\n", index.records[i].record.field1,
                   index.records[i].record.field2,
                   index.records[i].record.field3);
        }
    }
}

// function to create an index for a given database file
void create_index(char* filename, Index* index) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening database file.\n");
        return;
    }
    Record record;
    int position = 0;
    while (fread(&record, sizeof(record), 1, fp) == 1) {
        IndexedRecord indexed_record;
        strcpy(indexed_record.record.field1, record.field1);
        strcpy(indexed_record.record.field2, record.field2);
        strcpy(indexed_record.record.field3, record.field3);
        indexed_record.position = position++;
        index->records[index->size++] = indexed_record;
    }
    fclose(fp);
}

int main() {
    Index index;
    index.size = 0;
    char* filename = "database.txt";

    add_record(filename, &index, "John", "Doe", "555-1234");
    add_record(filename, &index, "Jane", "Smith", "555-5678");
    add_record(filename, &index, "Bob", "Johnson", "555-9012");

    find_records(index, "John", 1);

    create_index(filename, &index);
    find_records(index, "Smith", 2);

    return 0;
}