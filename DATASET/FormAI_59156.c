//FormAI DATASET v1.0 Category: Database simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 50

struct record {
    int id;
    char name[50];
    int age;
};

struct database {
    struct record records[MAX_RECORDS];
    int num_records;
};

void add_record(struct database *db, struct record r) {
    if (db->num_records < MAX_RECORDS) {
        db->records[db->num_records++] = r;
        printf("Record added successfully!\n");
    } else {
        printf("Error: database full!\n");
    }
}

void print_record(struct record r) {
    printf("ID: %d\n", r.id);
    printf("Name: %s\n", r.name);
    printf("Age: %d\n", r.age);
}

void print_database(struct database *db) {
    printf("Number of records: %d\n", db->num_records);
    for (int i = 0; i < db->num_records; i++) {
        printf("Record %d:\n", i+1);
        print_record(db->records[i]);
        printf("\n");
    }
}

int main() {
    struct database db;
    db.num_records = 0;

    // Add some sample records
    struct record r1 = {1, "John Smith", 25};
    struct record r2 = {2, "Jane Doe", 30};
    struct record r3 = {3, "Bob Johnson", 40};
    add_record(&db, r1);
    add_record(&db, r2);
    add_record(&db, r3);

    // Print the database
    print_database(&db);

    return 0;
}