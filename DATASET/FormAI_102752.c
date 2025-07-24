//FormAI DATASET v1.0 Category: Database Indexing System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_NAME_LENGTH 25
#define MAX_ADDRESS_LENGTH 50
#define MAX_PHONE_LENGTH 12

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Record;

typedef struct {
    Record records[MAX_RECORDS];
    int num_records;
} Database;

void insert_record(Database *db, Record record) {
    if (db->num_records == MAX_RECORDS) {
        printf("Error: database is full\n");
        return;
    }
    db->records[db->num_records] = record;
    db->num_records++;
}

void print_database(Database *db) {
    printf("ID\tName\t\tAddress\t\t\tPhone\n");
    printf("---------------------------------------------------------------\n");
    for (int i = 0; i < db->num_records; i++) {
        printf("%d\t%s\t\t%s\t\t%s\n", db->records[i].id, db->records[i].name, db->records[i].address, db->records[i].phone);
    }
}

Record find_record(Database *db, int id) {
    for (int i = 0; i < db->num_records; i++) {
        if (db->records[i].id == id) {
            return db->records[i];
        }
    }
    Record empty_record = {0, "", "", ""};
    return empty_record;
}

void delete_record(Database *db, int id) {
    for (int i = 0; i < db->num_records; i++) {
        if (db->records[i].id == id) {
            for (int j = i; j < db->num_records-1; j++) {
                db->records[j] = db->records[j+1];
            }
            db->num_records--;
            return;
        }
    }
}

int main() {
    Database db;
    db.num_records = 0;

    Record record1 = {1, "John Doe", "123 Main St", "555-1234"};
    Record record2 = {2, "Jane Smith", "456 Oak Ave", "555-5678"};

    insert_record(&db, record1);
    insert_record(&db, record2);
    print_database(&db);

    Record found_record = find_record(&db, 1);
    printf("Found record: %d %s %s %s\n", found_record.id, found_record.name, found_record.address, found_record.phone);

    delete_record(&db, 1);
    print_database(&db);

    return 0;
}