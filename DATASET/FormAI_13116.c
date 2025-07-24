//FormAI DATASET v1.0 Category: Database simulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000

struct Record {
    int id;
    char name[30];
    int age;
    char gender;
};

struct Database {
    struct Record records[MAX_RECORDS];
    int num_records;
};

void print_record(struct Record record) {
    printf("ID: %d\n", record.id);
    printf("Name: %s\n", record.name);
    printf("Age: %d\n", record.age);
    printf("Gender: %c\n", record.gender);
    printf("\n");
}

void print_database(struct Database db) {
    printf("Number of Records: %d\n", db.num_records);
    for (int i = 0; i < db.num_records; i++) {
        printf("Record %d:\n", i+1);
        print_record(db.records[i]);
    }
}

void add_record(struct Database *db, int id, char *name, int age, char gender) {
    struct Record record;
    record.id = id;
    strcpy(record.name, name);
    record.age = age;
    record.gender = gender;

    db->records[db->num_records++] = record;
}

int main() {
    struct Database db;
    db.num_records = 0;

    add_record(&db, 1, "John Smith", 30, 'M');
    add_record(&db, 2, "Jane Doe", 25, 'F');
    add_record(&db, 3, "Bob Johnson", 55, 'M');
    
    print_database(db);
    
    return 0;
}