//FormAI DATASET v1.0 Category: Database Indexing System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000

struct Record {
    int id;
    char name[50]; 
    char address[100]; 
    char phone[20];
};

struct Index {
    char key[50];
    int record_id;
};

struct Database {
    struct Record records[MAX_RECORDS];
    struct Index indexes[MAX_RECORDS];
    int num_records;
    int num_indexes;
};

void insert_record(struct Database *db, struct Record record, int record_id) {
    db->records[record_id] = record;
    // Add index for name
    struct Index name_index;
    strcpy(name_index.key, record.name);
    name_index.record_id = record_id;
    db->indexes[db->num_indexes++] = name_index;
    // Add index for address
    struct Index addr_index;
    strcpy(addr_index.key, record.address);
    addr_index.record_id = record_id;
    db->indexes[db->num_indexes++] = addr_index;
    // Add index for phone
    struct Index phone_index;
    strcpy(phone_index.key, record.phone);
    phone_index.record_id = record_id;
    db->indexes[db->num_indexes++] = phone_index;
}

void search_by_name(struct Database *db, char *name) {
    printf("Search results for name '%s':\n", name);
    for(int i=0; i<db->num_indexes; i++) {
        if(strcmp(db->indexes[i].key, name) == 0) {
            int record_id = db->indexes[i].record_id;
            struct Record record = db->records[record_id];
            printf("Record id: %d, Name: %s, Address: %s, Phone: %s\n", record.id, record.name, record.address, record.phone);
        }
    }
}

void search_by_address(struct Database *db, char *address) {
    printf("Search results for address '%s':\n", address);
    for(int i=0; i<db->num_indexes; i++) {
        if(strcmp(db->indexes[i].key, address) == 0) {
            int record_id = db->indexes[i].record_id;
            struct Record record = db->records[record_id];
            printf("Record id: %d, Name: %s, Address: %s, Phone: %s\n", record.id, record.name, record.address, record.phone);
        }
    }
}

void search_by_phone(struct Database *db, char *phone) {
    printf("Search results for phone '%s':\n", phone);
    for(int i=0; i<db->num_indexes; i++) {
        if(strcmp(db->indexes[i].key, phone) == 0) {
            int record_id = db->indexes[i].record_id;
            struct Record record = db->records[record_id];
            printf("Record id: %d, Name: %s, Address: %s, Phone: %s\n", record.id, record.name, record.address, record.phone);
        }
    }
}

int main() {
    struct Database db;
    db.num_records = 0;
    db.num_indexes = 0;

    // Insert records
    struct Record record1 = {1, "John Smith", "100 Main St, Springfield, IL", "(123) 456-7890"};
    insert_record(&db, record1, db.num_records++);
    struct Record record2 = {2, "Jane Doe", "200 Elm St, Chicago, IL", "(234) 567-8901"};
    insert_record(&db, record2, db.num_records++);
    struct Record record3 = {3, "Bob Johnson", "300 Oak Ave, Springfield, IL", "(345) 678-9012"};
    insert_record(&db, record3, db.num_records++);
    struct Record record4 = {4, "Mary Brown", "400 Main St, Springfield, IL", "(456) 789-0123"};
    insert_record(&db, record4, db.num_records++);

    // Search by name
    search_by_name(&db, "Jane Doe");

    // Search by address
    search_by_address(&db, "100 Main St, Springfield, IL");

    // Search by phone
    search_by_phone(&db, "(345) 678-9012");

    return 0;
}