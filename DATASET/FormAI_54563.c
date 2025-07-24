//FormAI DATASET v1.0 Category: Database simulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_RECORDS 1000

struct Record {
    int id;
    char name[20];
    int age;
};

struct Database {
    struct Record records[MAX_RECORDS];
    int size;
};

void initializeDatabase(struct Database* db) {
    db->size = 0;
}

void addRecord(struct Database* db, int id, char name[], int age) {
    if (db->size < MAX_RECORDS) {
        struct Record record = {id, name, age};
        db->records[db->size++] = record;
    }
}

void displayRecords(struct Database* db) {
    printf("ID\tName\tAge\n");
    for (int i = 0; i < db->size; i++) {
        printf("%d\t%s\t%d\n", db->records[i].id, db->records[i].name, db->records[i].age);
    }
}

void searchRecordByID(struct Database* db, int id) {
    for (int i = 0; i < db->size; i++) {
        if (db->records[i].id == id) {
            printf("Record found:\n");
            printf("ID\tName\tAge\n");
            printf("%d\t%s\t%d\n", db->records[i].id, db->records[i].name, db->records[i].age);
            return;
        }
    }
    printf("Record not found!\n");
}

void deleteRecordByID(struct Database* db, int id) {
    for (int i = 0; i < db->size; i++) {
        if (db->records[i].id == id) {
            for (int j = i; j < db->size - 1; j++) {
                db->records[j] = db->records[j + 1];
            }
            db->size--;
            printf("Record deleted!\n");
            return;
        }
    }
    printf("Record not found!\n");
}

int main() {
    struct Database db;
    initializeDatabase(&db);
    
    // add some records to the database
    addRecord(&db, 1, "Alice", 25);
    addRecord(&db, 2, "Bob", 30);
    addRecord(&db, 3, "Charlie", 35);
    addRecord(&db, 4, "David", 40);
    addRecord(&db, 5, "Eve", 45);
    
    // display all records
    displayRecords(&db);
    
    // search for a record by ID
    searchRecordByID(&db, 3);
    
    // delete a record by ID
    deleteRecordByID(&db, 4);
    
    // display all records again
    displayRecords(&db);
    
    // add some more records to the database
    addRecord(&db, 6, "Frank", 50);
    addRecord(&db, 7, "Grace", 55);
    addRecord(&db, 8, "Hank", 60);
    addRecord(&db, 9, "Ivy", 65);
    
    // display all records again
    displayRecords(&db);
    
    // search for a record by ID
    searchRecordByID(&db, 10);
    
    return 0;
}