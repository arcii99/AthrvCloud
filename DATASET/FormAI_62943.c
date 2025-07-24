//FormAI DATASET v1.0 Category: Database Indexing System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
// Maximum number of records that can be indexed

typedef struct {
    int id;
    char name[50];
    int age;
} Record;
// The structure for our database records. Includes an ID, name, and age.

typedef struct {
    int num_records;
    Record records[MAX_RECORDS];
} Database;
// The structure for our database. Includes the number of records, and an array of record structures.

typedef struct {
    int index_key;
    int record_id;
} Index;
// The structure for our index. Includes an index key, and the ID of the corresponding record.

typedef struct {
    int num_indices;
    Index indices[MAX_RECORDS];
} IndexTable;
// The structure for our index table. Includes the number of indices, and an array of index structures.

void add_record(Database *db, int id, char *name, int age);
void create_index(IndexTable *index_table, Database *db);
void print_index(IndexTable *index_table, int index_key);

int main()
{
    Database db = {0};
    IndexTable index_table = {0};

    add_record(&db, 1, "John Smith", 32);
    add_record(&db, 2, "Jane Doe", 40);
    add_record(&db, 3, "Bob Johnson", 25);

    create_index(&index_table, &db);

    print_index(&index_table, 25);

    return 0;
}

void add_record(Database *db, int id, char *name, int age)
{
    if (db->num_records >= MAX_RECORDS) {
        printf("Error: Maximum number of records reached.\n");
        exit(1);
    }

    Record record = {id, "", age};
    strncpy(record.name, name, sizeof(record.name) - 1);

    db->records[db->num_records] = record;
    db->num_records++;
}

void create_index(IndexTable *index_table, Database *db)
{
    for (int i = 0; i < db->num_records; i++) {
        Index index = {db->records[i].age, db->records[i].id};

        index_table->indices[index_table->num_indices] = index;
        index_table->num_indices++;
    }
}

void print_index(IndexTable *index_table, int index_key)
{
    for (int i = 0; i < index_table->num_indices; i++) {
        if (index_table->indices[i].index_key == index_key) {
            printf("Record %d has index key %d.\n", index_table->indices[i].record_id, index_table->indices[i].index_key);
        }
    }
}