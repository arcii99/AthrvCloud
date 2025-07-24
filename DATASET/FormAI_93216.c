//FormAI DATASET v1.0 Category: Database simulation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DB_SIZE 10 // Maximum size of the database
#define MAX_STRING_LENGTH 20 // Maximum length of a string in the database

typedef struct {
    int id;
    char name[MAX_STRING_LENGTH];
    int age;
} Record; // Structure to hold a record in the database

typedef struct {
    Record records[MAX_DB_SIZE];
    int size;
} Database; // Structure to hold the database

void initialize_db(Database* db) {
    db->size = 0;
}

void insert_record(Database* db, Record record) {
    if(db->size >= MAX_DB_SIZE) {
        printf("Database is full!\n");
        return;
    }
    
    db->records[db->size] = record;
    db->size++;
}

void print_record(Record record) {
    printf("%d %s %d\n", record.id, record.name, record.age);
}

void print_db(Database db) {
    int i;
    for(i=0; i<db.size; i++) {
        print_record(db.records[i]);
    }
}

int main() {
    Database db;
    initialize_db(&db);
    
    // Insert some records
    Record record1 = {1, "John", 25};
    Record record2 = {2, "Jane", 30};
    Record record3 = {3, "Bob", 40};
    insert_record(&db, record1);
    insert_record(&db, record2);
    insert_record(&db, record3);
    
    // Print the database
    print_db(db);
    
    return 0;
}