//FormAI DATASET v1.0 Category: Database simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

// Defining the structure for the database.
struct Record {
    int id;
    char name[50];
    int age;
};

// Defining the database to store the records.
struct Record database[MAX_RECORDS];

// Initializing the number of records in the database.
int nRecords = 0;

// Function to add a new record to the database.
void addRecord(int id, char name[], int age) {
    if (nRecords < MAX_RECORDS) {
        database[nRecords].id = id;
        strcpy(database[nRecords].name, name);
        database[nRecords].age = age;
        nRecords++;
        printf("New record added.\n");
    } else {
        printf("Database is full. Cannot add more records.\n");
    }
}

// Function to display all the records in the database.
void displayRecords() {
    if (nRecords == 0) {
        printf("No records to display.\n");
    } else {
        printf("ID\tName\tAge\n");
        for (int i = 0; i < nRecords; i++) {
            printf("%d\t%s\t%d\n", database[i].id, database[i].name, database[i].age);
        }
    }
}

// Function to search for a record in the database.
void searchRecord(int id) {
    int index = -1;
    for (int i = 0; i < nRecords; i++) {
        if (database[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Record not found.\n");
    } else {
        printf("ID\tName\tAge\n");
        printf("%d\t%s\t%d\n", database[index].id, database[index].name, database[index].age);
    }
}

// Function to delete a record from the database.
void deleteRecord(int id) {
    int index = -1;
    for (int i = 0; i < nRecords; i++) {
        if (database[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Record not found.\n");
    } else {
        for (int i = index; i < nRecords - 1; i++) {
            database[i] = database[i + 1];
        }
        nRecords--;
        printf("Record deleted.\n");
    }
}

// Main function to demonstrate the database simulation.
int main() {
    // Adding some records to the database.
    addRecord(1, "John Doe", 25);
    addRecord(2, "Jane Smith", 30);
    addRecord(3, "Bob Johnson", 40);

    // Displaying all the records in the database.
    displayRecords();

    // Searching for a record in the database.
    searchRecord(2);

    // Deleting a record from the database.
    deleteRecord(3);

    // Displaying all the records in the database after deletion.
    displayRecords();

    return 0;
}