//FormAI DATASET v1.0 Category: Database Indexing System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_INDEXES 5

typedef struct {
    int id;
    char name[50];
    int age;
} Record;

typedef struct {
    int count;
    int indexes[MAX_INDEXES];
} Index;

Index indexes[MAX_INDEXES];
Record records[MAX_RECORDS];

// Function to add a new record to the database
void addRecord(int id, char name[], int age) {
    Record record = {id, "", age};
    strncpy(record.name, name, sizeof(record.name)-1);
    
    // Add record to the database
    records[id-1] = record;
    
    // Update indexes
    for (int i = 0; i < MAX_INDEXES; i++) {
        Index index = indexes[i];
        if (index.count > 0) {
            indexes[i].indexes[index.count] = id;
            indexes[i].count++;
        }
    }
}

// Function to search the database by ID
void searchById(int id) {
    if (id < 1 || id > MAX_RECORDS) {
        printf("Invalid ID!\n");
        return;
    }
    Record record = records[id-1];
    if (record.id != 0) {
        printf("ID: %d\nName: %s\nAge: %d\n", record.id, record.name, record.age);
    } else {
        printf("Record not found!\n");
    }
}

// Function to search the database by name
void searchByName(char name[]) {
    int found = 0;
    for (int i = 0; i < MAX_RECORDS; i++) {
        Record record = records[i];
        if (record.id != 0 && strcmp(record.name, name) == 0) {
            printf("ID: %d\nName: %s\nAge: %d\n", record.id, record.name, record.age);
            found = 1;
        }
    }
    if (!found) {
        printf("Record not found!\n");
    }
}

// Function to search the database by age
void searchByAge(int age) {
    int found = 0;
    for (int i = 0; i < MAX_RECORDS; i++) {
        Record record = records[i];
        if (record.id != 0 && record.age == age) {
            printf("ID: %d\nName: %s\nAge: %d\n", record.id, record.name, record.age);
            found = 1;
        }
    }
    if (!found) {
        printf("Record not found!\n");
    }
}

int main() {
    // Add some records to the database
    addRecord(1, "John Doe", 25);
    addRecord(2, "Jane Doe", 30);
    addRecord(3, "Bob Smith", 40);
    
    // Search the database
    printf("Search by ID:\n");
    searchById(2);
    printf("\nSearch by name:\n");
    searchByName("John Doe");
    printf("\nSearch by age:\n");
    searchByAge(30);
    
    return 0;
}