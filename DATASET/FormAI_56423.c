//FormAI DATASET v1.0 Category: Database simulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 10000
#define MAX_NAME_LENGTH 50

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    int age;
} Record;

typedef struct {
    Record records[MAX_RECORDS];
    int num_records;
} Database;

void initialize_database(Database *db) {
    db->num_records = 0;
}

void add_record(Database *db, int id, char *name, int age) {
    if (db->num_records < MAX_RECORDS) {
        Record *record = &(db->records[db->num_records]);
        record->id = id;
        strncpy(record->name, name, MAX_NAME_LENGTH);
        record->age = age;
        db->num_records++;
    }
}

void delete_record(Database *db, int id) {
    int i;
    for (i = 0; i < db->num_records; i++) {
        if (db->records[i].id == id) {
            int j;
            for (j = i; j < db->num_records - 1; j++) {
                db->records[j] = db->records[j+1];
            }
            db->num_records--;
            break;
        }
    }
}

Record * find_record(Database *db, int id) {
    int i;
    for (i = 0; i < db->num_records; i++) {
        if (db->records[i].id == id) {
            return &(db->records[i]);
        }
    }
    return NULL;
}

void print_records(Database *db) {
    int i;
    for (i = 0; i < db->num_records; i++) {
        Record *record = &(db->records[i]);
        printf("%d: %s (%d)\n", record->id, record->name, record->age);
    }
}

int main(void) {
    Database db;
    initialize_database(&db);
    
    add_record(&db, 1, "John", 25);
    add_record(&db, 2, "Jane", 30);
    add_record(&db, 3, "Bob", 40);
    
    printf("All records:\n");
    print_records(&db);
    
    printf("Deleting record with ID 2...\n");
    delete_record(&db, 2);
    
    printf("All records after deletion:\n");
    print_records(&db);
    
    Record *record = find_record(&db, 1);
    if (record != NULL) {
        printf("Record found: %s (%d)\n", record->name, record->age);
    } else {
        printf("Record not found!\n");
    }
    
    return 0;
}