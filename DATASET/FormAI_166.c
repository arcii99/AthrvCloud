//FormAI DATASET v1.0 Category: Database Indexing System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_NAME_LEN 50
#define MAX_AGE 120

typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    int age;
} record_t;

typedef struct {
    char name[MAX_NAME_LEN];
    int records_count;
    int* records_indexes;
} index_t;

record_t records[MAX_RECORDS];
int records_count = 0;
index_t indexes[MAX_NAME_LEN];
int indexes_count = 0;

/* Helper functions */
int is_name_match(const char* name1, const char* name2) {
    return strcmp(name1, name2) == 0;
}

/* Database functions */
int add_record(int id, const char* name, int age) {
    if (records_count >= MAX_RECORDS) {
        return 0;
    }
    record_t* record = &records[records_count];
    record->id = id;
    strncpy(record->name, name, MAX_NAME_LEN);
    record->age = age;
    records_count++;
    return 1;
}

void add_index(const char* name, int record_index) {
    index_t* index = NULL;
    for (int i = 0; i < indexes_count; i++) {
        if (is_name_match(indexes[i].name, name)) {
            index = &indexes[i];
            break;
        }
    }
    if (index == NULL) {
        index = &indexes[indexes_count];
        strncpy(index->name, name, MAX_NAME_LEN);
        index->records_count = 0;
        index->records_indexes = calloc(MAX_RECORDS, sizeof(int));
        indexes_count++;
    }
    index->records_indexes[index->records_count] = record_index;
    index->records_count++;
}

void print_records(const index_t* index) {
    printf("Records indexed by %s:\n", index->name);
    for (int i = 0; i < index->records_count; i++) {
        const record_t* record = &records[index->records_indexes[i]];
        printf("[%d] %s (age %d)\n", record->id, record->name, record->age);
    }
}

int main() {
    /* Add some records */
    add_record(1, "John", 25);
    add_index("name", 0);
    add_record(2, "Bob", 30);
    add_index("name", 1);
    add_record(3, "John", 45);
    add_index("name", 2);
    add_record(4, "Alice", 20);
    add_index("age", 0);
    add_record(5, "Jane", 35);
    add_index("age", 1);

    /* Test indexing */
    for (int i = 0; i < indexes_count; i++) {
        print_records(&indexes[i]);
    }

    /* Cleanup */
    for (int i = 0; i < indexes_count; i++) {
        free(indexes[i].records_indexes);
    }

    return 0;
}