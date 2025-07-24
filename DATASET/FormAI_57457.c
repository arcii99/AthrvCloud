//FormAI DATASET v1.0 Category: Database Indexing System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_NAME_LENGTH 20

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
} Record;

typedef struct {
    Record data[MAX_RECORDS];
    int last_index;
} Database;

typedef struct {
    int id;
    int index;
} Index;

typedef struct {
    Index index[MAX_RECORDS];
    int last_index;
} IndexTable;

IndexTable index_table;

void insert_record(Database *db, Record record) {
    db->data[db->last_index] = record;
    db->last_index++;

    Index new_index = {
        .id = record.id,
        .index = db->last_index - 1
    };
    index_table.index[index_table.last_index] = new_index;
    index_table.last_index++;
}

int find_record_index_by_id(int id) {
    for (int i = 0; i < index_table.last_index; i++) {
        if (index_table.index[i].id == id) {
            return index_table.index[i].index;
        }
    }

    return -1;
}

Record *find_record_by_id(Database *db, int id) {
    int index = find_record_index_by_id(id);

    if (index == -1) {
        return NULL;
    } else {
        return &db->data[index];
    }
}

void print_database(Database *db) {
    printf("ID\tName\n");
    for (int i = 0; i < db->last_index; i++) {
        Record record = db->data[i];
        printf("%d\t%s\n", record.id, record.name);
    }
}

int main() {
    Database db = { 0 };
    index_table.last_index = 0;

    Record record1 = {
        .id = 1,
        .name = "Alice"
    };

    Record record2 = {
        .id = 2,
        .name = "Bob"
    };

    Record record3 = {
        .id = 3,
        .name = "Charlie"
    };

    insert_record(&db, record1);
    insert_record(&db, record2);
    insert_record(&db, record3);

    printf("Database before deletion:\n");
    print_database(&db);

    int record_index_to_delete = find_record_index_by_id(2);
    memmove(&db.data[record_index_to_delete], &db.data[record_index_to_delete + 1], (db.last_index - record_index_to_delete - 1) * sizeof(Record));
    db.last_index--;

    index_table.last_index = 0;
    for (int i = 0; i < db.last_index; i++) {
        Record record = db.data[i];

        Index new_index = {
            .id = record.id,
            .index = i
        };
        index_table.index[index_table.last_index] = new_index;
        index_table.last_index++;
    }

    printf("Database after deletion:\n");
    print_database(&db);

    Record *found_record = find_record_by_id(&db, 1);
    if (found_record) {
        printf("Record with ID 1 found: %s\n", found_record->name);
    } else {
        printf("Record with ID 1 not found.\n");
    }

    return 0;
}