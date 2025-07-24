//FormAI DATASET v1.0 Category: Database Indexing System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define constants
#define MAX_RECORDS 100
#define MAX_KEY_LEN 50

// define data structures
typedef struct {
    char key[MAX_KEY_LEN];
    int value;
} Record;

typedef struct {
    Record records[MAX_RECORDS];
    int num_records;
} Database;

// define functions
int insert_record(Database *db, char *key, int value) {
    // check if record already exists
    for (int i = 0; i < db->num_records; i++) {
        if (strcmp(db->records[i].key, key) == 0) {
            printf("Record with key '%s' already exists in database.\n", key);
            return 0;
        }
    }
    // insert new record
    if (db->num_records < MAX_RECORDS) {
        strcpy(db->records[db->num_records].key, key);
        db->records[db->num_records].value = value;
        db->num_records++;
        printf("Record with key '%s' successfully inserted into database.\n", key);
        return 1;
    } else {
        printf("Database is full. Unable to insert new record.\n");
        return 0;
    }
}

int delete_record(Database *db, char *key) {
    // search for record and delete it
    for (int i = 0; i < db->num_records; i++) {
        if (strcmp(db->records[i].key, key) == 0) {
            // shift records down to fill gap
            for (int j = i; j < db->num_records - 1; j++) {
                db->records[j] = db->records[j + 1];
            }
            db->num_records--;
            printf("Record with key '%s' successfully deleted from database.\n", key);
            return 1;
        }
    }
    // record not found
    printf("Record with key '%s' not found in database.\n", key);
    return 0;
}

Record *search_record(Database *db, char *key) {
    // search for record and return pointer to it
    for (int i = 0; i < db->num_records; i++) {
        if (strcmp(db->records[i].key, key) == 0) {
            return &(db->records[i]);
        }
    }
    // record not found
    return NULL;
}

int main() {
    // create database and some initial records
    Database db;
    db.num_records = 0;
    insert_record(&db, "john", 10);
    insert_record(&db, "mary", 20);
    insert_record(&db, "bob", 30);
    insert_record(&db, "alice", 40);
    insert_record(&db, "lisa", 50);
    // search for a record and print its value
    char search_key[MAX_KEY_LEN] = "mary";
    Record *record = search_record(&db, search_key);
    if (record != NULL) {
        printf("Value of record with key '%s' is %d.\n", search_key, record->value);
    } else {
        printf("Record with key '%s' not found in database.\n", search_key);
    }
    // delete a record and print updated database
    char delete_key[MAX_KEY_LEN] = "bob";
    delete_record(&db, delete_key);
    printf("Database after deleting record with key '%s':\n", delete_key);
    for (int i = 0; i < db.num_records; i++) {
        printf("%s: %d\n", db.records[i].key, db.records[i].value);
    }
    // insert a new record and print updated database
    char insert_key[MAX_KEY_LEN] = "dave";
    int insert_value = 60;
    insert_record(&db, insert_key, insert_value);
    printf("Database after inserting record with key '%s':\n", insert_key);
    for (int i = 0; i < db.num_records; i++) {
        printf("%s: %d\n", db.records[i].key, db.records[i].value);
    }
    return 0;
}