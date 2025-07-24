//FormAI DATASET v1.0 Category: Database simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 1000

struct Record {
    int id;
    char name[20];
    int age;
};

struct Database {
    struct Record records[MAX_SIZE];
    int size;
};

void printRecord(struct Record record) {
    printf("ID: %d \nName: %s \nAge: %d\n\n", record.id, record.name, record.age);
}

void printDatabase(struct Database database) {
    printf("Printing All Records in Database:\n");
    for(int i=0; i<database.size; i++) {
        printRecord(database.records[i]);
    }
}

void findRecord(struct Database database, int id) {
    for(int i=0; i<database.size; i++) {
        if(database.records[i].id == id) {
            printf("Search Result:\n");
            printRecord(database.records[i]);
            return;
        }
    }
    printf("Record with ID %d not found.\n", id);
}

void deleteRecord(struct Database* database, int id) {
    int index = -1;
    for(int i=0; i<database->size; i++) {
        if(database->records[i].id == id) {
            index = i;
            break;
        }
    }
    if(index == -1) {
        printf("Record with ID %d not found.\n", id);
    } else {
        for(int i=index; i<database->size-1; i++) {
            database->records[i] = database->records[i+1];
        }
        database->size--;
        printf("Record with ID %d has been deleted.\n", id);
    }
}

void addRecord(struct Database* database, struct Record record) {
    if(database->size >= MAX_SIZE) {
        printf("Database is Full! Record not added.\n");
    } else {
        database->records[database->size++] = record;
        printf("Record with ID %d has been added.\n", record.id);
    }
}

int main() {
    struct Database db;
    db.size = 0;

    //Adding Records
    struct Record record1 = {1, "Tom", 25};
    addRecord(&db, record1);
    struct Record record2 = {2, "Emma", 18};
    addRecord(&db, record2);
    struct Record record3 = {3, "Stuart", 45};
    addRecord(&db, record3);

    //Printing All Records
    printDatabase(db);

    //Finding and Printing a Record
    printf("Finding a Record with ID 2\n");
    findRecord(db, 2);

    //Deleting a Record
    printf("Deleting a Record with ID 1\n");
    deleteRecord(&db, 1);

    //Printing All Records after Deletion
    printDatabase(db);

    return 0;
}