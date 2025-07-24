//FormAI DATASET v1.0 Category: Database simulation ; Style: synchronous
#include <stdio.h>
#include <string.h>

// Define struct for database records
struct Record {
    int id;
    char name[20];
    int age;
};

// Define array to hold database records
const int MAX_RECORDS = 10;
struct Record database[10];

// Define function to print all records in the database
void printDatabase() {
    printf("\nPrinting Database...\n");
    for (int i = 0; i < MAX_RECORDS; i++) {
        if (database[i].id != 0) {
            printf("Record %d: ID=%d, Name=%s, Age=%d\n", i+1, database[i].id, database[i].name, database[i].age);
        }
    }
    printf("End of Database\n");
}

int main() {
    // Initialize database with empty records
    for (int i = 0; i < MAX_RECORDS; i++) {
        database[i].id = 0;
    }
    
    // Add some example records
    database[0].id = 1;
    strcpy(database[0].name, "John");
    database[0].age = 30;
    database[1].id = 2;
    strcpy(database[1].name, "Jane");
    database[1].age = 25;
    
    // Print initial state of database
    printDatabase();
    
    // Add a new record
    printf("\nAdding new record...\n");
    int newID = 3;
    strcpy(database[2].name, "Bob");
    database[2].age = 40;
    database[2].id = newID;
    
    // Print database after adding new record
    printDatabase();
    
    // Update an existing record
    printf("\nUpdating record...\n");
    int updateID = 1;
    strcpy(database[0].name, "John Smith");
    
    // Print database after updating record
    printDatabase();
    
    // Delete a record
    printf("\nDeleting record...\n");
    int deleteID = 2;
    database[1].id = 0;
    
    // Print database after deleting record
    printDatabase();
    
    return 0;
}