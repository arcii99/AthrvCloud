//FormAI DATASET v1.0 Category: Database Indexing System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000000
#define MAX_NAME_LENGTH 256

struct Record {
    int id;
    char name[MAX_NAME_LENGTH];
};

struct Index {
    char name[MAX_NAME_LENGTH];
    int offset;
};

struct Database {
    struct Record records[MAX_RECORDS];
    struct Index index[MAX_RECORDS];
    int num_records;
};

void init_db(struct Database *db) {
    db->num_records = 0;
}

int add_record(struct Database *db, struct Record record) {
    if (db->num_records >= MAX_RECORDS) {
        return -1;
    }
    int index = db->num_records;
    db->records[index] = record;
    struct Index idx;
    strcpy(idx.name, record.name);
    idx.offset = index;
    db->index[index] = idx;
    db->num_records++;
    return index;
}

int search_name(struct Database *db, char *name) {
    int i;
    for (i = 0; i < db->num_records; i++) {
        if (strcmp(db->index[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    struct Database db;
    init_db(&db);

    struct Record record;
    record.id = 1;
    strcpy(record.name, "John Doe");
    add_record(&db, record);

    record.id = 2;
    strcpy(record.name, "Jane Doe");
    add_record(&db, record);

    int index = search_name(&db, "John Doe");
    if (index != -1) {
        printf("Found record with id %d and name %s\n", db.records[index].id, db.records[index].name);
    }
    else {
        printf("Record not found\n");
    }

    return 0;
}