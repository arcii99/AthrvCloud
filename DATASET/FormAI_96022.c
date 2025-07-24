//FormAI DATASET v1.0 Category: Database simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LEN 20
#define MAX_RECORDS 100

typedef struct record {
    int id;
    char name[MAX_NAME_LEN];
    int age;
    char gender;
} Record;

typedef struct database {
    Record records[MAX_RECORDS];
    int count;
} Database;

void add_record(Database *db, Record record) {
    if (db->count >= MAX_RECORDS) {
        printf("Database full!\n");
        return;
    }
    db->records[db->count] = record;
    db->count++;
}

Record create_record(int id, char *name, int age, char gender) {
    Record record;
    record.id = id;
    strncpy(record.name, name, MAX_NAME_LEN);
    record.age = age;
    record.gender = gender;
    return record;
}

void print_record(Record record) {
    printf("ID: %d\n", record.id);
    printf("Name: %s\n", record.name);
    printf("Age: %d\n", record.age);
    printf("Gender: %c\n", record.gender);
}

void print_database(Database db) {
    printf("Database:\n");
    for (int i = 0; i < db.count; i++) {
        printf("------------------------\n");
        print_record(db.records[i]);
    }
    printf("------------------------\n");
}

int main() {
    srand(time(NULL));
    Database db;
    db.count = 0;

    // Create some example records
    Record r1 = create_record(rand() % 1000, "John Smith", 30, 'M');
    Record r2 = create_record(rand() % 1000, "Jane Doe", 25, 'F');
    Record r3 = create_record(rand() % 1000, "Max Power", 45, 'M');

    // Add records to database
    add_record(&db, r1);
    add_record(&db, r2);
    add_record(&db, r3);

    // Print database
    print_database(db);

    return 0;
}