//FormAI DATASET v1.0 Category: Database simulation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100 // Maximum number of records that can be stored in the database

typedef struct {
    int id;
    char name[50];
    int age;
    char address[100];
} Record;

typedef struct {
    Record records[MAX_RECORDS];
    int count;
} Database;

void init(Database *db) {
    db->count = 0;
}

void add_record(Database *db, Record r) {
    if (db->count < MAX_RECORDS) {
        db->records[db->count] = r;
        db->count++;
    }
}

void display_records(Database db) {
    printf("ID\tName\tAge\tAddress\n");
    printf("----------------------------------------------\n");
    for (int i = 0; i < db.count; i++) {
        printf("%d\t%s\t%d\t%s\n", db.records[i].id, db.records[i].name,
               db.records[i].age, db.records[i].address);
    }
}

int main() {
    Database db;
    Record r;

    init(&db);

    // Add some records to the database
    r.id = 1;
    strcpy(r.name, "John Doe");
    r.age = 30;
    strcpy(r.address, "123 Main St, Anytown USA");
    add_record(&db, r);

    r.id = 2;
    strcpy(r.name, "Jane Smith");
    r.age = 25;
    strcpy(r.address, "456 Oak Dr, Somewhere Else USA");
    add_record(&db, r);

    // Display the records in the database
    display_records(db);

    return 0;
}