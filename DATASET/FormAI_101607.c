//FormAI DATASET v1.0 Category: Database Indexing System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_KEY_LEN 50

typedef struct {
    char key[MAX_KEY_LEN];
    int data;
} Record;

typedef struct {
    Record **records;
    int num_records;
} RecordSet;

typedef struct {
    RecordSet **record_sets;
    int num_sets;
} Index;

// Functions for working with Records
Record* create_record(char *key, int data) {
    Record *new_record = malloc(sizeof(Record));
    strcpy(new_record->key, key);
    new_record->data = data;
    return new_record;
}

void print_record(Record *record) {
    printf("{%s, %d}\n", record->key, record->data);
}

void free_record(Record *record) {
    free(record);
}

// Functions for working with RecordSets
RecordSet* create_record_set() {
    RecordSet *new_record_set = malloc(sizeof(RecordSet));
    new_record_set->records = malloc(MAX_RECORDS * sizeof(Record*));
    new_record_set->num_records = 0;
    return new_record_set;
}

void add_record_to_set(RecordSet *record_set, Record *record) {
    if (record_set->num_records < MAX_RECORDS) {
        record_set->records[record_set->num_records++] = record;
    } else {
        printf("Error: Record set already at maximum capacity.\n");
    }
}

void print_record_set(RecordSet *record_set) {
    printf("Record Set:\n");
    for (int i = 0; i < record_set->num_records; i++) {
        print_record(record_set->records[i]);
    }
}

void free_record_set(RecordSet *record_set) {
    for (int i = 0; i < record_set->num_records; i++) {
        free_record(record_set->records[i]);
    }
    free(record_set->records);
    free(record_set);
}

// Functions for working with Indexes
Index* create_index() {
    Index *new_index = malloc(sizeof(Index));
    new_index->record_sets = malloc(MAX_KEY_LEN * sizeof(RecordSet*));
    new_index->num_sets = 0;
    return new_index;
}

RecordSet* find_record_set_by_key(Index *index, char *key) {
    for (int i = 0; i < index->num_sets; i++) {
        if (strcmp(index->record_sets[i]->records[0]->key, key) == 0) {
            return index->record_sets[i];
        }
    }
    return NULL;
}

void add_record_to_index(Index *index, Record *record) {
    RecordSet *record_set = find_record_set_by_key(index, record->key);
    if (record_set == NULL) {
        record_set = create_record_set();
        index->record_sets[index->num_sets++] = record_set;
    }
    add_record_to_set(record_set, record);
}

void print_index(Index *index) {
    printf("Index:\n");
    for (int i = 0; i < index->num_sets; i++) {
        print_record_set(index->record_sets[i]);
    }
}

void free_index(Index *index) {
    for (int i = 0; i < index->num_sets; i++) {
        free_record_set(index->record_sets[i]);
    }
    free(index->record_sets);
    free(index);
}

// Example program
int main() {
    Index *my_index = create_index();
    add_record_to_index(my_index, create_record("abc", 123));
    add_record_to_index(my_index, create_record("def", 456));
    add_record_to_index(my_index, create_record("abc", 789));
    print_index(my_index);
    free_index(my_index);
    return 0;
}