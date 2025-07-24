//FormAI DATASET v1.0 Category: Database Indexing System ; Style: relaxed
#include <stdio.h>
#include <string.h>
#define MAX_RECORDS 1000
#define MAX_INDEX 500

typedef struct record_t {
    int id;
    char name[50];
    int age;
} record_t;

typedef struct index_t {
    char name[50];
    int offset;
} index_t;

int num_records = 0;
int num_indexes = 0;
record_t records[MAX_RECORDS];
index_t indexes[MAX_INDEX];

void add_record(int id, char *name, int age) {
    record_t record;
    record.id = id;
    strcpy(record.name, name);
    record.age = age;
    records[num_records++] = record;
}

void add_index(char *name, int offset) {
    index_t index;
    strcpy(index.name, name);
    index.offset = offset;
    indexes[num_indexes++] = index;
}

void print_record(record_t record) {
    printf("Record ID: %d\n", record.id);
    printf("Name: %s\n", record.name);
    printf("Age: %d\n", record.age);
}

void print_index(index_t index) {
    printf("Index Name: %s\n", index.name);
    printf("Offset: %d\n", index.offset);
}

void print_records() {
    int i;
    for (i = 0; i < num_records; i++) {
        print_record(records[i]);
    }
}

void print_indexes() {
    int i;
    for (i = 0; i < num_indexes; i++) {
        print_index(indexes[i]);
    }
}

int main() {
    add_record(1, "Alice", 21);
    add_record(2, "Bob", 34);
    add_record(3, "Charlie", 27);
    add_record(4, "Dave", 42);

    add_index("Name", 0);
    add_index("ID", 1);
    add_index("Age", 2);

    printf("Records:\n");
    print_records();

    printf("Indexes:\n");
    print_indexes();

    return 0;
}