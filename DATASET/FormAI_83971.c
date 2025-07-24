//FormAI DATASET v1.0 Category: Database simulation ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

// A structure to represent the database
typedef struct {
    int id;
    char name[20];
    char address[50];
    float salary;
} Record;

// A structure to hold the database records
typedef struct {
    Record records[MAX];
    int count;
} Database;

// Function to add a new record to the database
void addRecord(Database* db, Record record) {
    if(db->count < MAX) {
        db->records[db->count++] = record;
        printf("Record added successfully!\n");
    } else {
        printf("Error: Database is full!\n");
    }
}

// Function to display all records in the database
void displayRecords(Database* db) {
    printf("%-5s %-20s %-50s %-10s\n", "ID", "Name", "Address", "Salary");
    for(int i=0; i<db->count; i++) {
        Record record = db->records[i];
        printf("%-5d %-20s %-50s $%-9.2f\n", record.id, record.name, record.address, record.salary);
    }
}

int main() {

    // Initialize the database
    Database db;
    db.count = 0;

    // Add some records to the database
    Record record1 = {1, "John Doe", "123 Main St, Anytown USA", 50000.00};
    addRecord(&db, record1);

    Record record2 = {2, "Jane Smith", "456 Elm St, Somewhere USA", 60000.00};
    addRecord(&db, record2);

    Record record3 = {3, "Bob Johnson", "789 Oak St, Nowhere USA", 70000.00};
    addRecord(&db, record3);

    // Display all records in the database
    displayRecords(&db);

    return 0;
}