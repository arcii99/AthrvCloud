//FormAI DATASET v1.0 Category: Database Indexing System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 10 // maximum number of threads

// Node structure for database
typedef struct {
    int id;
    char name[50];
    char address[100];
} Record;

// Index structure to store the value and pointer to record
typedef struct {
    int value;
    Record* record;
} Index;

// Database structure to store records and indexes
typedef struct {
    Record records[1000];
    Index indexes[1000];
    int num_records;
    int num_indexes;
} Database;

// Function to compare two indexes
int compare_index(const void* a, const void* b) {
    const Index* index_a = a;
    const Index* index_b = b;
    return (index_a->value - index_b->value);
}

// Function to create indexes for the given database
void create_indexes(Database* db) {
    for (int i = 0; i < db->num_records; i++) {
        Index index = {db->records[i].id, &(db->records[i])};
        db->indexes[i] = index;
    }
    db->num_indexes = db->num_records;
    qsort(db->indexes, db->num_indexes, sizeof(Index), compare_index);
}

// Function to search for a record based on index value
Record* search_record(Database* db, int value) {
    int start = 0;
    int end = db->num_indexes - 1;
    int mid;
    while (start <= end) {
        mid = (start + end) / 2;
        if (db->indexes[mid].value == value) {
            return db->indexes[mid].record;
        } else if (db->indexes[mid].value < value) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return NULL;
}

// Function to add a record to the database
void add_record(Database* db, Record* record) {
    db->records[db->num_records] = *record;
    db->num_records++;
}

// Function to print all records in the database
void print_records(Database* db) {
    for (int i = 0; i < db->num_records; i++) {
        printf("Record %d\n", i+1);
        printf("ID: %d\n", db->records[i].id);
        printf("Name: %s\n", db->records[i].name);
        printf("Address: %s\n\n", db->records[i].address);
    }
}

// Function to print all indexes in the database
void print_indexes(Database* db) {
    for (int i = 0; i < db->num_indexes; i++) {
        printf("Index %d\n", i+1);
        printf("Value: %d\n", db->indexes[i].value);
    }
}

// Function for each thread to execute
void* thread_function(void* param) {
    Database* db = (Database*)param;
    Record record1 = {1, "John Doe", "123 Main Street"};
    Record record2 = {2, "Jane Smith", "456 Oak Avenue"};
    add_record(db, &record1);
    add_record(db, &record2);
    create_indexes(db);
    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    int num_threads = 2;
    Database db;
    db.num_records = 0;
    db.num_indexes = 0;
    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, thread_function, &db);
    }
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
    Record* record = search_record(&db, 1);
    printf("Record found: ID=%d Name=%s Address=%s\n", record->id, record->name, record->address);
    printf("All Records:\n");
    print_records(&db);
    printf("All Indexes:\n");
    print_indexes(&db);
    return 0;
}