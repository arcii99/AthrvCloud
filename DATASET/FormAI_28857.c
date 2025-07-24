//FormAI DATASET v1.0 Category: Database Indexing System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_KEY_LEN 50

struct Record {
    char key[MAX_KEY_LEN];
    int data;
};

struct Index {
    char key[MAX_KEY_LEN];
    int record_num;
};

int num_records = 0;
struct Record records[MAX_RECORDS];
int num_indexes = 0;
struct Index indexes[MAX_RECORDS];

int add_record(char *key, int data) {
    if (num_records >= MAX_RECORDS) {
        printf("Error: Maximum number of records reached!\n");
        return -1;
    }
    strncpy(records[num_records].key, key, MAX_KEY_LEN);
    records[num_records].data = data;
    num_records++;
    return num_records-1;
}

int add_index(char *key, int record_num) {
    if (num_indexes >= MAX_RECORDS) {
        printf("Error: Maximum number of indexes reached!\n");
        return -1;
    }
    strncpy(indexes[num_indexes].key, key, MAX_KEY_LEN);
    indexes[num_indexes].record_num = record_num;
    num_indexes++;
    return num_indexes-1;
}

int search_index(char *key) {
    for (int i = 0; i < num_indexes; i++) {
        if (strcmp(indexes[i].key, key) == 0) {
            return indexes[i].record_num;
        }
    }
    return -1;
}

void print_records() {
    printf("Records:\n");
    for (int i = 0; i < num_records; i++) {
        printf("%s %d\n", records[i].key, records[i].data);
    }
}

void print_indexes() {
    printf("Indexes:\n");
    for (int i = 0; i < num_indexes; i++) {
        printf("%s %d\n", indexes[i].key, indexes[i].record_num);
    }
}

int main(void) {
    // Add some records
    add_record("Alice", 20);
    add_record("Bob", 30);
    add_record("Charlie", 40);
    add_record("David", 50);

    // Add some indexes
    add_index("Alice", 0);
    add_index("Bob", 1);
    add_index("Charlie", 2);
    add_index("David", 3);

    // Search for a record
    int record_num = search_index("Charlie");
    if (record_num != -1) {
        printf("Record found: %s %d\n", records[record_num].key, records[record_num].data);
    } else {
        printf("Record not found!\n");
    }

    // Print all records and indexes
    print_records();
    print_indexes();

    return 0;
}