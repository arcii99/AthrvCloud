//FormAI DATASET v1.0 Category: Database querying ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of records in the database
#define MAX_RECORDS 100

// Define the structure for each record
struct Record {
    int id;
    char name[20];
    char hobby[20];
    char date[10];
};

// Create an array to store all the records
struct Record database[MAX_RECORDS];

// Define the current number of records in the database
int num_records = 0;

// Function to add a new record to the database
void add_record(int id, char name[], char hobby[], char date[]) {
    // Check if the database is full
    if (num_records >= MAX_RECORDS) {
        printf("Sorry, the database is full\n");
    } else {
        // Create a new record and add it to the database
        struct Record new_record;
        new_record.id = id;
        strcpy(new_record.name, name);
        strcpy(new_record.hobby, hobby);
        strcpy(new_record.date, date);
        database[num_records] = new_record;
        num_records++;
        printf("Record added successfully\n");
    }
}

// Function to search for a record by ID
void search_by_id(int id) {
    int i;
    for (i = 0; i < num_records; i++) {
        if (database[i].id == id) {
            printf("ID: %d\n", database[i].id);
            printf("Name: %s\n", database[i].name);
            printf("Hobby: %s\n", database[i].hobby);
            printf("Date: %s\n", database[i].date);
            return;
        }
    }
    printf("Record not found\n");
}

// Function to search for a record by name
void search_by_name(char name[]) {
    int i;
    for (i = 0; i < num_records; i++) {
        if (strcmp(database[i].name, name) == 0) {
            printf("ID: %d\n", database[i].id);
            printf("Name: %s\n", database[i].name);
            printf("Hobby: %s\n", database[i].hobby);
            printf("Date: %s\n", database[i].date);
            return;
        }
    }
    printf("Record not found\n");
}

int main() {
    // Welcome the user
    printf("Welcome to our romantic database!\n");

    // Add some records to the database
    add_record(1, "John", "Singing", "09/25/2010");
    add_record(2, "Mary", "Dancing", "03/17/2015");
    add_record(3, "Peter", "Painting", "11/08/2012");

    // Search for a record by ID
    printf("Searching for record with ID = 2\n");
    search_by_id(2);

    // Search for a record by name
    printf("Searching for record with name = Mary\n");
    search_by_name("Mary");

    // Goodbye message
    printf("Thank you for using our database! Have a romantic day!\n");

    return 0;
}