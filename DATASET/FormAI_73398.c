//FormAI DATASET v1.0 Category: Database Indexing System ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>

#define MAX_RECORDS 1000   // maximum size of the database
#define MAX_FIELDS 10      // maximum number of fields in the record

struct record {
    int id;
    char fields[MAX_FIELDS][256];
};

struct index {
    int id;
    int offset;   // byte offset of the record in the database file
};

struct database {
    struct record records[MAX_RECORDS];
    struct index index[MAX_RECORDS];
    int num_records;
};

void add_record(struct database *db, struct record r) {
    db->records[db->num_records] = r;
    db->index[db->num_records].id = r.id;
    db->index[db->num_records].offset = db->num_records * sizeof(struct record);
    db->num_records++;
}

void search(struct database *db, int id) {
    int i;
    for (i = 0; i < db->num_records; i++) {
        if (db->index[i].id == id) {
            printf("Record %d:\n", id);
            int j;
            for (j = 0; j < MAX_FIELDS; j++) {
                printf("%s: %s\n", db->records[i].fields[j], db->records[i].fields[j]);
            }
            return;
        }
    }
    printf("Record %d not found\n", id);
}

int main() {
    struct database db;
    db.num_records = 0;

    // add some records
    struct record r1 = {1, {"name", "John", "age", "25"}};
    add_record(&db, r1);

    struct record r2 = {2, {"name", "Jane", "age", "30"}};
    add_record(&db, r2);

    struct record r3 = {3, {"name", "Bob", "age", "35"}};
    add_record(&db, r3);

    // search for a record
    search(&db, 2);

    return 0;
}