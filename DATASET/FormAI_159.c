//FormAI DATASET v1.0 Category: Database simulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 10
#define MAX_NAME_LEN 20

struct Student {
    int id;
    char name[MAX_NAME_LEN];
    float gpa;
};

struct StudentDB {
    int num_records;
    struct Student records[MAX_RECORDS];
};

void addRecord(struct StudentDB* db, int id, char* name, float gpa) {
    if (db->num_records >= MAX_RECORDS) {
        printf("Error: database is full\n");
        return;
    }
    
    struct Student* new_record = &db->records[db->num_records];
    new_record->id = id;
    strncpy(new_record->name, name, MAX_NAME_LEN);
    new_record->gpa = gpa;
    
    db->num_records++;
}

void displayDB(struct StudentDB db) {
    printf("ID\tName\tGPA\n");
    for (int i = 0; i < db.num_records; i++) {
        printf("%d\t%s\t%.2f\n", db.records[i].id, db.records[i].name, db.records[i].gpa);
    }
}

int main() {
    struct StudentDB db = {0};
    
    addRecord(&db, 1, "Alice", 3.5);
    addRecord(&db, 2, "Bob", 3.2);
    addRecord(&db, 3, "Charlie", 3.9);
    addRecord(&db, 4, "David", 2.8);
    
    displayDB(db);
    
    return 0;
}