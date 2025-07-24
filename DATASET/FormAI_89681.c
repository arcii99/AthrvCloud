//FormAI DATASET v1.0 Category: Database Indexing System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 50
#define MAX_RECORDS 100

struct Record {
    char name[MAX_LENGTH];
    int id;
    float score;
};

struct Index {
    char name[MAX_LENGTH];
    int record_index;
};

struct Database {
    struct Record records[MAX_RECORDS];
    struct Index name_index[MAX_RECORDS];
    struct Index id_index[MAX_RECORDS];
    int count;
};

// Helper function to compare two records by name
int compare_by_name(const void *a, const void *b) {
    struct Record *record_a = (struct Record*)a;
    struct Record *record_b = (struct Record*)b;
    return strcmp(record_a->name, record_b->name);
}

// Helper function to compare two records by id
int compare_by_id(const void *a, const void *b) {
    struct Record *record_a = (struct Record*)a;
    struct Record *record_b = (struct Record*)b;
    return record_a->id - record_b->id;
}

// Function to add a record to the database
void add_record(struct Database *database, char *name, int id, float score) {
    if (database->count >= MAX_RECORDS) {
        printf("Database is full\n");
        return;
    }
    int index = database->count;
    struct Record *record = &database->records[index];
    strncpy(record->name, name, MAX_LENGTH);
    record->id = id;
    record->score = score;
    // Add index to name index
    struct Index *name_index = &database->name_index[index];
    strncpy(name_index->name, name, MAX_LENGTH);
    name_index->record_index = index;
    // Add index to id index
    struct Index *id_index = &database->id_index[index];
    strncpy(id_index->name, name, MAX_LENGTH);
    id_index->record_index = index;
    database->count++;
}

// Function to search for a record by name using binary search
struct Record* search_by_name(struct Database *database, char *name) {
    int min = 0, max = database->count-1, mid;
    while (min <= max) {
        mid = (min + max) / 2;
        struct Index *name_index = &database->name_index[mid];
        int cmp = strcmp(name, name_index->name);
        if (cmp == 0) {
            return &database->records[name_index->record_index];
        } else if (cmp < 0) {
            max = mid - 1;
        } else {
            min = mid + 1;
        }
    }
    return NULL;
}

// Function to search for a record by id using binary search
struct Record* search_by_id(struct Database *database, int id) {
    int min = 0, max = database->count-1, mid;
    while (min <= max) {
        mid = (min + max) / 2;
        struct Index *id_index = &database->id_index[mid];
        if (id == database->records[id_index->record_index].id) {
            return &database->records[id_index->record_index];
        } else if (id < database->records[id_index->record_index].id) {
            max = mid - 1;
        } else {
            min = mid + 1;
        }
    }
    return NULL;
}

// Function to print a record
void print_record(struct Record *record) {
    printf("%s %d %.2f\n", record->name, record->id, record->score);
}

// Function to print all records in the database
void print_database(struct Database *database) {
    printf("Name\tID\tScore\n");
    for (int i = 0; i < database->count; i++) {
        print_record(&database->records[i]);
    }
}

int main() {
    struct Database database = {0};
    // Add some records
    add_record(&database, "Alice", 123, 4.5);
    add_record(&database, "Bob", 456, 3.2);
    add_record(&database, "Charlie", 789, 2.7);
    // Print all records
    print_database(&database);
    // Search for a record by name
    struct Record *record = search_by_name(&database, "Bob");
    if (record != NULL) {
        printf("Record found: ");
        print_record(record);
    } else {
        printf("Record not found\n");
    }
    // Search for a record by id
    record = search_by_id(&database, 789);
    if (record != NULL) {
        printf("Record found: ");
        print_record(record);
    } else {
        printf("Record not found\n");
    }
    return 0;
}