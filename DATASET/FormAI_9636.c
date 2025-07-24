//FormAI DATASET v1.0 Category: Database Indexing System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 100
#define MAX_REC 1000

struct Record {
    int id;
    char name[MAX_STR];
    char address[MAX_STR];
};

struct Index {
    int id;
    int offset;
};

struct Database {
    int num_records;
    struct Record records[MAX_REC];
    struct Index indices[MAX_REC];
};

void insert_record(struct Database *db, struct Record *rec) {
    if (db->num_records >= MAX_REC) {
        printf("Error: Database full\n");
        return;
    }
    db->records[db->num_records] = *rec;
    db->indices[db->num_records].id = rec->id;
    db->indices[db->num_records].offset = db->num_records;
    db->num_records++;
}

void index_sort(struct Database *db) {
    for (int i = 0; i < db->num_records; i++) {
        for (int j = i+1; j < db->num_records; j++) {
            if (db->indices[i].id > db->indices[j].id) {
                struct Index temp = db->indices[i];
                db->indices[i] = db->indices[j];
                db->indices[j] = temp;
            }
        }
    }
}

void search_record(struct Database *db, int id) {
    int lo = 0, hi = db->num_records-1, mid;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (id == db->indices[mid].id) {
            printf("Record found at offset %d\n", db->indices[mid].offset);
            printf("\tID: %d\n", db->records[db->indices[mid].offset].id);
            printf("\tName: %s\n", db->records[db->indices[mid].offset].name);
            printf("\tAddress: %s\n", db->records[db->indices[mid].offset].address);
            return;
        }
        else if (id < db->indices[mid].id) {
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }
    printf("Record not found\n");
}

int main() {
    struct Database db = {0};
    
    struct Record rec1 = {10, "John Smith", "123 Main St."};
    struct Record rec2 = {2, "Jane Doe", "456 Elm St."};
    struct Record rec3 = {33, "Bob Johnson", "789 Oak St."};
    struct Record rec4 = {45, "Mary Williams", "321 Maple St."};
    
    insert_record(&db, &rec1);
    insert_record(&db, &rec2);
    insert_record(&db, &rec3);
    insert_record(&db, &rec4);
    
    index_sort(&db);
    
    search_record(&db, 10);
    search_record(&db, 33);
    search_record(&db, 99);
    
    return 0;
}