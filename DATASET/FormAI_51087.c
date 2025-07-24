//FormAI DATASET v1.0 Category: Database Indexing System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 50
#define MAX_NAME_LENGTH 20

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    float score;
} Record;

typedef struct {
    Record records[MAX_RECORDS];
    int count;
} Database;

void insert_record(Database *db, int id, char *name, float score) {
    if(db->count >= MAX_RECORDS) {
        printf("Database full.\n");
        return;
    }

    Record r;
    r.id = id;
    strncpy(r.name, name, MAX_NAME_LENGTH);
    r.score = score;

    db->records[db->count] = r;
    db->count++;
}

void print_records(Database *db) {
    for(int i = 0; i < db->count; i++) {
        Record r = db->records[i];
        printf("%d\t%s\t%.2f\n", r.id, r.name, r.score);
    }
}

void index_database(Database *db) {
    Record *idx[MAX_RECORDS];  // Create an array of record pointers
    for(int i = 0; i < db->count; i++) {
        idx[i] = &db->records[i];  // Assign each record's address to a pointer in the index
    }

    // Sort the index based on name using a simple bubble sort algorithm
    for(int i = 0; i < db->count - 1; i++) {
        for(int j = 0; j < db->count - i - 1; j++) {
            Record *r1 = idx[j];
            Record *r2 = idx[j+1];
            if(strcmp(r1->name, r2->name) > 0) {
                // Swap pointers in the index
                Record *temp = idx[j];
                idx[j] = idx[j+1];
                idx[j+1] = temp;
            }
        }
    }

    // Print the indexed database
    printf("ID\tName\tScore\n");
    for(int i = 0; i < db->count; i++) {
        Record *r = idx[i];
        printf("%d\t%s\t%.2f\n", r->id, r->name, r->score);
    }
}

int main() {
    Database db = {{0}, 0};

    // Insert some sample records
    insert_record(&db, 1001, "Alice", 85.2);
    insert_record(&db, 1002, "Charlie", 72.9);
    insert_record(&db, 1003, "Bob", 91.5);
    insert_record(&db, 1004, "David", 79.1);

    printf("Unindexed database:\n");
    printf("ID\tName\tScore\n");
    print_records(&db);

    printf("\nIndexed database:\n");
    index_database(&db);

    return 0;
}