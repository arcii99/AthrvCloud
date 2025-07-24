//FormAI DATASET v1.0 Category: Database Indexing System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_NAME_LENGTH 50

struct record {
    int id;
    char name[MAX_NAME_LENGTH];
    float score;
};

// Define a hash function to map record names to indices in the records array
int hash(char* name) {
    int sum = 0;
    for (int i = 0; i < strlen(name); i++) {
        sum += name[i];
    }
    return sum % MAX_RECORDS;
}

// Define a function to insert a record into the database
void insert_record(struct record records[], struct record new_record) {
    int index = hash(new_record.name);
    while (records[index].id != 0) {
        index++;
        if (index >= MAX_RECORDS) {
            index = 0;
        }
    }
    records[index] = new_record;
}

// Define a function to search for a record by name
int search_record(struct record records[], char* name) {
    int index = hash(name);
    while (strcmp(records[index].name, name) != 0) {
        index++;
        if (index >= MAX_RECORDS) {
            index = 0;
        }
        if (records[index].id == 0) {
            return -1;
        }
    }
    return index;
}

// Define a function to print out a single record
void print_record(struct record rec) {
    printf("ID: %d, Name: %s, Score: %f\n", rec.id, rec.name, rec.score);
}

// Define a function to print out the entire database
void print_database(struct record records[]) {
    for (int i = 0; i < MAX_RECORDS; i++) {
        if (records[i].id != 0) {
            print_record(records[i]);
        }
    }
}

int main() {
    struct record records[MAX_RECORDS] = {0};
    struct record new_record = {1, "Alice", 90.0};
    insert_record(records, new_record);
    new_record = (struct record) {2, "Bob", 85.0};
    insert_record(records, new_record);
    new_record = (struct record) {3, "Charlie", 95.0};
    insert_record(records, new_record);
    new_record = (struct record) {4, "David", 80.0};
    insert_record(records, new_record);
    print_database(records);
    int index = search_record(records, "Charlie");
    if (index != -1) {
        print_record(records[index]);
    } else {
        printf("No record found.\n");
    }
    return 0;
}