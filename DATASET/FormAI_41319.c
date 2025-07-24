//FormAI DATASET v1.0 Category: Database Indexing System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_INDEX 10000

typedef struct {
    int id;
    char name[50];
    char gender;
    int age;
    int index;
} record_t;

record_t records[MAX_RECORDS];
int num_records = 0;

int indexes[MAX_INDEX];

void add_record(int id, char *name, char gender, int age, int index) {
    record_t record;
    record.id = id;
    strncpy(record.name, name, sizeof(record.name));
    record.gender = gender;
    record.age = age;
    record.index = index;

    records[num_records++] = record;
}

void create_index() {
    // Initialize the indexes array to -1 to indicate empty slots
    memset(indexes, -1, sizeof(indexes));

    // Go through each record and update the indexes array
    for (int i = 0; i < num_records; i++) {
        int index = records[i].index;
        if (indexes[index] == -1) {
            indexes[index] = i;
        } else {
            printf("Duplicate index %d!\n", index);
        }
    }
}

int get_record_by_index(int index) {
    if (index >= 0 && index < MAX_INDEX && indexes[index] != -1) {
        return indexes[index];
    } else {
        return -1;
    }
}

int main() {
    add_record(101, "John", 'M', 23, 321);
    add_record(102, "Jane", 'F', 32, 123);
    add_record(103, "Bob", 'M', 45, 1234);
    add_record(104, "Alice", 'F', 27, 4321);
    add_record(105, "Tom", 'M', 19, 555);

    create_index();

    int index = 123;
    int record_index = get_record_by_index(index);
    if (record_index != -1) {
        record_t record = records[record_index];
        printf("Record found: ID=%d, Name=%s, Gender=%c, Age=%d, Index=%d\n", record.id, record.name, record.gender, record.age, record.index);
    } else {
        printf("Record not found for index %d\n", index);
    }

    return 0;
}