//FormAI DATASET v1.0 Category: Database simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_NAME_LEN 50
#define MAX_PHONE_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
} Record;

typedef struct {
    Record records[MAX_RECORDS];
    int num_records;
} Database;

void add_record(Database* db, const char* name, const char* phone) {
    if (db->num_records >= MAX_RECORDS) {
        printf("Database is full!\n");
        return;
    }

    Record* record = &db->records[db->num_records];
    strncpy(record->name, name, MAX_NAME_LEN);
    strncpy(record->phone, phone, MAX_PHONE_LEN);
    db->num_records++;
}

int find_record(Database* db, const char* name) {
    for (int i = 0; i < db->num_records; i++) {
        if (strncmp(db->records[i].name, name, MAX_NAME_LEN) == 0) {
            return i;
        }
    }

    return -1;
}

void remove_record(Database* db, const char* name) {
    int index = find_record(db, name);

    if (index == -1) {
        printf("Record not found!\n");
        return;
    }

    for (int i = index; i < db->num_records - 1; i++) {
        db->records[i] = db->records[i + 1];
    }

    db->num_records--;
}

void print_record(const Record* record) {
    printf("Name: %s\n", record->name);
    printf("Phone: %s\n", record->phone);
}

void print_database(const Database* db) {
    printf("Database: (%d records)\n", db->num_records);

    for (int i = 0; i < db->num_records; i++) {
        printf("- Record #%d:\n", i + 1);
        print_record(&db->records[i]);
    }
}

int main() {
    Database db = {};
    add_record(&db, "John Doe", "555-1234");
    add_record(&db, "Jane Smith", "555-5678");

    printf("Database initially:\n");
    print_database(&db);

    remove_record(&db, "John Doe");

    printf("Database after removing John Doe:\n");
    print_database(&db);

    return 0;
}