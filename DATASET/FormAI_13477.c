//FormAI DATASET v1.0 Category: Database Indexing System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 20
#define MAX_RECORD_COUNT 100

struct record {
    char key[MAX_KEY_LENGTH];
    int data;
};

struct index {
    char key[MAX_KEY_LENGTH];
    int position;
};

struct database {
    struct record records[MAX_RECORD_COUNT];
    struct index index_entries[MAX_RECORD_COUNT];
    int record_count;
    int index_count;
};

void add_record(struct database *db, char *key, int data) {
    if(db->record_count >= MAX_RECORD_COUNT) {
        printf("Database is full\n");
        return;
    }
    strcpy(db->records[db->record_count].key, key);
    db->records[db->record_count].data = data;
    db->record_count++;
}

void sort_index(struct database *db) {
    for(int i=0; i<db->index_count-1; i++) {
        for(int j=i+1; j<db->index_count; j++) {
            if(strcmp(db->index_entries[i].key, db->index_entries[j].key) > 0) {
                struct index temp = db->index_entries[i];
                db->index_entries[i] = db->index_entries[j];
                db->index_entries[j] = temp;
            }
        }
    }
}

void create_index(struct database *db) {
    for(int i=0; i<db->record_count; i++) {
        strcpy(db->index_entries[db->index_count].key, db->records[i].key);
        db->index_entries[db->index_count].position = i;
        db->index_count++;
    }
    sort_index(db);
}

int search_record(struct database *db, char *key) {
    int low = 0;
    int high = db->index_count-1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(strcmp(db->index_entries[mid].key, key) < 0) {
            low = mid+1;
        } else if(strcmp(db->index_entries[mid].key, key) > 0) {
            high = mid-1;
        } else {
            return db->index_entries[mid].position;
        }
    }
    return -1;
}

int main() {
    struct database db;
    db.record_count = 0;
    db.index_count = 0;
    add_record(&db, "key1", 10);
    add_record(&db, "key2", 20);
    add_record(&db, "key3", 30);
    create_index(&db);
    int pos = search_record(&db, "key2");
    if(pos != -1) {
        printf("Record found : %d\n", db.records[pos].data);
    } else {
        printf("Record not found\n");
    }
    return 0;
}