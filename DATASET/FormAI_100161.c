//FormAI DATASET v1.0 Category: Database Indexing System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_NAME_LEN 25
#define MAX_EMAIL_LEN 50

typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} Record;

typedef struct {
    Record records[MAX_RECORDS];
    int size;
} Database;

void initialize(Database *db) {
    db->size = 0;
}

void insert_record(Database *db, int id, const char *name, const char *email) {
    if (db->size < MAX_RECORDS) {
        Record *record = &(db->records[db->size]);
        record->id = id;
        strncpy(record->name, name, MAX_NAME_LEN);
        strncpy(record->email, email, MAX_EMAIL_LEN);
        db->size++;
    }
}

Record *find_record_by_id(Database *db, int id) {
    for (int i = 0; i < db->size; i++) {
        if (db->records[i].id == id) {
            return &(db->records[i]);
        }
    }
    return NULL;
}

void print_database(Database *db) {
    printf("ID\tName\t\tEmail\n");
    for (int i = 0; i < db->size; i++) {
        printf("%d\t%s\t\t%s\n", db->records[i].id, db->records[i].name, db->records[i].email);
    }
}

int main() {
    Database db;
    initialize(&db);

    insert_record(&db, 101, "John Smith", "j.smith@example.com");
    insert_record(&db, 102, "Jane Doe", "jane.doe@example.com");
    insert_record(&db, 103, "Bob Johnson", "b.johnson@example.com");

    Record *record = find_record_by_id(&db, 102);
    printf("Record found:\n%d\t%s\t\t%s\n", record->id, record->name, record->email);

    print_database(&db);

    return 0;
}