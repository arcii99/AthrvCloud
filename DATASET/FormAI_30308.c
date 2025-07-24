//FormAI DATASET v1.0 Category: Database simulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct {
    int id;
    char name[50];
    int age;
} Record;

Record create_record(int id, char* name, int age) {
    Record record;
    record.id = id;
    strcpy(record.name, name);
    record.age = age;
    return record;
}

void insert_record(Record* records, int* num_records, Record new_record) {
    if (*num_records < MAX_RECORDS) {
        records[*num_records] = new_record;
        (*num_records)++;
        printf("Record inserted successfully.\n");
    } else {
        printf("Error: Maximum number of records reached.\n");
    }
}

void print_record(Record record) {
    printf("ID: %d\n", record.id);
    printf("Name: %s\n", record.name);
    printf("Age: %d\n", record.age);
}

void print_database(Record* records, int num_records) {
    printf("DATABASE:\n");
    for (int i = 0; i < num_records; i++) {
        printf("Record %d:\n", i+1);
        print_record(records[i]);
    }
}

int search_record_by_id(Record* records, int num_records, int target_id) {
    for (int i = 0; i < num_records; i++) {
        if (records[i].id == target_id) {
            return i;
        }
    }
    return -1;
}

void update_record_by_id(Record* records, int num_records, int target_id, Record new_record) {
    int record_index = search_record_by_id(records, num_records, target_id);
    if (record_index != -1) {
        records[record_index] = new_record;
        printf("Record updated successfully.\n");
    } else {
        printf("Error: Record with ID %d not found.\n", target_id);
    }
}

void delete_record_by_id(Record* records, int* num_records, int target_id) {
    int record_index = search_record_by_id(records, *num_records, target_id);
    if (record_index != -1) {
        for (int i = record_index; i < (*num_records)-1; i++) {
            records[i] = records[i+1];
        }
        (*num_records)--;
        printf("Record deleted successfully.\n");
    } else {
        printf("Error: Record with ID %d not found.\n", target_id);
    }
}

int main(void) {
    Record records[MAX_RECORDS];
    int num_records = 0;

    // Insert some sample records
    insert_record(records, &num_records, create_record(1, "Alice", 25));
    insert_record(records, &num_records, create_record(2, "Bob", 30));
    insert_record(records, &num_records, create_record(3, "Charlie", 40));

    // Print the initial database
    print_database(records, num_records);

    // Update a record
    update_record_by_id(records, num_records, 2, create_record(2, "Bobby", 31));
    print_database(records, num_records);

    // Delete a record
    delete_record_by_id(records, &num_records, 1);
    print_database(records, num_records);

    return 0;
}