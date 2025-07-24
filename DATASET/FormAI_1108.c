//FormAI DATASET v1.0 Category: Database Indexing System ; Style: Ada Lovelace
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_RECORDS 1000
#define MAX_NAME_LEN 30
#define MAX_ID_LEN 12

struct student {
    char id[MAX_ID_LEN];
    char name[MAX_NAME_LEN];
    char address[50];
    int age;
};

struct index {
    char id[MAX_ID_LEN];
    int record_pos;
};

struct database {
    struct student records[MAX_RECORDS];
    struct index index_list[MAX_RECORDS];
    int num_records;
};

void add_record(struct database *db, struct student s) {
    if(db->num_records >= MAX_RECORDS) {
        printf("ERROR: Database is full. Cannot add more records.\n");
        return;
    }

    strcpy(db->records[db->num_records].id, s.id);
    strcpy(db->records[db->num_records].name, s.name);
    strcpy(db->records[db->num_records].address, s.address);
    db->records[db->num_records].age = s.age;

    strcpy(db->index_list[db->num_records].id, s.id);
    db->index_list[db->num_records].record_pos = db->num_records;

    db->num_records++;
}

int search_by_id(struct database db, char* id) {
    int i;
    for(i=0; i<db.num_records; i++) {
        if(strcmp(db.records[i].id, id) == 0) {
            return i;
        }
    }
    return -1;
}

void delete_record(struct database *db, char* id) {
    int pos = search_by_id(*db, id);
    if(pos == -1) {
        printf("ERROR: Record with id '%s' not found.\n", id);
        return;
    }

    int i;
    for(i=pos; i<db->num_records-1; i++) {
        strcpy(db->records[i].id, db->records[i+1].id);
        strcpy(db->records[i].name, db->records[i+1].name);
        strcpy(db->records[i].address, db->records[i+1].address);
        db->records[i].age = db->records[i+1].age;

        strcpy(db->index_list[i].id, db->index_list[i+1].id);
        db->index_list[i].record_pos = db->index_list[i+1].record_pos;
    }
    db->num_records--;
}

void print_record(struct student s) {
    printf("%-12s %-30s %-50s %2d\n", s.id, s.name, s.address, s.age);
}

void print_database(struct database db) {
    int i;
    printf("%-12s %-30s %-50s %2s\n", "ID", "Name", "Address", "Age");
    printf("--------------------------------------------------------------\n");
    for(i=0; i<db.num_records; i++) {
        print_record(db.records[i]);
    }
}

void print_index(struct index idx) {
    printf("%-12s %d\n", idx.id, idx.record_pos);
}

void print_index_list(struct database db) {
    int i;
    printf("%-12s %s\n", "ID", "Record Position");
    printf("--------------------------\n");
    for(i=0; i<db.num_records; i++) {
        print_index(db.index_list[i]);
    }
}

int main() {
    struct database db;
    db.num_records = 0;

    struct student s1 = {"ST093146", "John Smith", "123 Main St, Anytown USA", 25};
    struct student s2 = {"ST028461", "Jane Doe", "456 Elm St, Another Town USA", 22};

    add_record(&db, s1);
    add_record(&db, s2);

    printf("Initial database:\n");
    print_database(db);
    printf("\nIndex list:\n");
    print_index_list(db);

    delete_record(&db, "ST093146");

    printf("\nAfter deleting record with id 'ST093146':\n");
    print_database(db);
    printf("\nIndex list:\n");
    print_index_list(db);

    return 0;
}