//FormAI DATASET v1.0 Category: Database simulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 5
#define MAX_NAME_LENGTH 20

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
} Record;

typedef struct {
    Record records[MAX_SIZE];
    int count;
} Database;

void print_record(const Record* record) {
    printf("ID: %d, Name: %s\n", record->id, record->name);
}

void print_database(const Database* db) {
    printf("Records in Database:\n");
    for(int i=0; i<db->count; i++) {
        print_record(&db->records[i]);
    }
}

bool add_record(Database* db, const char* name) {
    if(db->count == MAX_SIZE) return false;
    int id = db->count + 1;
    Record new_record = {id};
    strncpy(new_record.name, name, MAX_NAME_LENGTH);
    db->records[db->count++] = new_record;
    return true;
}

int find_record(const Database* db, int id) {
    for(int i=0; i<db->count; i++) {
        if(db->records[i].id == id) {
            return i;
        }
    }
    return -1;
}

bool remove_record(Database* db, int id) {
    int index = find_record(db, id);
    if(index == -1) return false;
    db->count--;
    for(int i=index; i<db->count; i++) {
        db->records[i] = db->records[i+1];
    }
    return true;
}

int main() {
    Database my_db = {{}, 0};
    
    printf("Adding Records:\n");
    add_record(&my_db, "Alice");
    add_record(&my_db, "Bob");
    add_record(&my_db, "Charlie");
    add_record(&my_db, "David");
    add_record(&my_db, "Emily");
    print_database(&my_db);
    
    printf("\nRemoving Record with ID 3:\n");
    remove_record(&my_db, 3);
    print_database(&my_db);
    
    printf("\nAdding Record:\n");
    add_record(&my_db, "Frank");
    print_database(&my_db);
    
    return 0;
}