//FormAI DATASET v1.0 Category: Database Indexing System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000

// define the structure of a record
struct Record {
    int id;
    char name[50];
    int age;
    char address[100];
};

// define the structure of an index entry
struct IndexEntry {
    int key;
    int offset;
};

// define the structure of an index
struct Index {
    int size;
    struct IndexEntry entries[MAX_RECORDS];
};

// function for adding a record to the database
void add_record(FILE *database, struct Record record, struct Index *index) {
    int offset = ftell(database);
    fwrite(&record, sizeof(struct Record), 1, database);
    struct IndexEntry entry = {record.id, offset};
    index->entries[index->size++] = entry;
}

// function for finding a record by ID
struct Record find_record(FILE *database, struct Index *index, int id) {
    for (int i = 0; i < index->size; i++) {
        if (index->entries[i].key == id) {
            int offset = index->entries[i].offset;
            fseek(database, offset, SEEK_SET);
            struct Record record;
            fread(&record, sizeof(struct Record), 1, database);
            return record;
        }
    }
    struct Record empty_record = {0, "", 0, ""};
    return empty_record;
}

// function for removing a record by ID
void remove_record(FILE *database, struct Index *index, int id) {
    for (int i = 0; i < index->size; i++) {
        if (index->entries[i].key == id) {
            int offset = index->entries[i].offset;
            fseek(database, offset, SEEK_SET);
            struct Record empty_record = {0, "", 0, ""};
            fwrite(&empty_record, sizeof(struct Record), 1, database);
            for (int j = i; j < index->size - 1; j++) {
                index->entries[j] = index->entries[j+1];
            }
            index->size--;
            break;
        }
    }
}

int main() {
    // open the database file
    FILE *database = fopen("database.bin", "w+b");
    if (database == NULL) {
        printf("Error: could not open database file\n");
        exit(1);
    }
    
    // create an empty index
    struct Index index = {0};
    
    // add some records to the database
    struct Record record1 = {1, "John Smith", 35, "123 Main St."};
    add_record(database, record1, &index);
    
    struct Record record2 = {2, "Jane Doe", 25, "456 Oak Ave."};
    add_record(database, record2, &index);
    
    struct Record record3 = {3, "Bob Johnson", 42, "789 Maple Rd."};
    add_record(database, record3, &index);
    
    // find a record by ID
    struct Record result1 = find_record(database, &index, 2);
    printf("Found record by ID: %d %s %d %s\n", result1.id, result1.name, result1.age, result1.address);
    
    // remove a record by ID
    remove_record(database, &index, 2);
    struct Record result2 = find_record(database, &index, 2);
    printf("Found record after removal: %d %s %d %s\n", result2.id, result2.name, result2.age, result2.address);
    
    // close the database file
    fclose(database);
    
    return 0;
}