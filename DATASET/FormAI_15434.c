//FormAI DATASET v1.0 Category: Database simulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 10
#define MAX_NAME_LENGTH 20

struct Record {
    int id;
    char name[MAX_NAME_LENGTH];
    float balance;
};

struct Database {
    struct Record records[MAX_RECORDS];
    int count;
    float total_balance;
};

void initialize_database(struct Database *db) {
    db->count = 0;
    db->total_balance = 0;
}

void add_record(struct Database *db, struct Record record) {
    if(db->count < MAX_RECORDS) {
        db->records[db->count] = record;
        db->total_balance += record.balance;
        db->count++;
    }
}

void print_record(struct Record record) {
    printf("ID: %d\nName: %s\nBalance: %.2f\n", record.id, record.name, record.balance);
}

void print_database(struct Database db) {
    printf("Database contains %d records and has a total balance of %.2f\n", db.count, db.total_balance);
    for(int i=0; i<db.count; i++) {
        print_record(db.records[i]);
    }
}

int main() {
    struct Database db;
    struct Record record;

    initialize_database(&db);

    record.id = 1;
    strncpy(record.name, "John", MAX_NAME_LENGTH);
    record.balance = 1000.00;
    add_record(&db, record);

    record.id = 2;
    strncpy(record.name, "Jane", MAX_NAME_LENGTH);
    record.balance = 1500.00;
    add_record(&db, record);

    print_database(db);

    return 0;
}