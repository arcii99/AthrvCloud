//FormAI DATASET v1.0 Category: Database querying ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for each record
struct Record {
    char name[50];
    int age;
    char occupation[50];
};

// Define the function to print out each record
void printRecord(struct Record* record) {
    printf("Name: %s\nAge: %d\nOccupation: %s\n", 
            record->name, record->age, record->occupation);
}

int main() {
    
    // Create a sample database with 3 records
    struct Record database[3];
    strcpy(database[0].name, "John");
    database[0].age = 30;
    strcpy(database[0].occupation, "Software Developer");
    
    strcpy(database[1].name, "Sarah");
    database[1].age = 25;
    strcpy(database[1].occupation, "Data Analyst");
    
    strcpy(database[2].name, "David");
    database[2].age = 40;
    strcpy(database[2].occupation, "Project Manager");
    
    // Print out all the records
    printf("All records in the database:\n");
    for (int i = 0; i < 3; i++) {
        printRecord(&database[i]);
        printf("\n");
    }
    
    // Query the database for all software developers
    printf("Querying database for all software developers:\n");
    for (int i = 0; i < 3; i++) {
        if (strcmp(database[i].occupation, "Software Developer") == 0) {
            printRecord(&database[i]);
            printf("\n");
        }
    }
    
    // Query the database for all employees over the age of 35
    printf("Querying database for all employees over 35:\n");
    for (int i = 0; i < 3; i++) {
        if (database[i].age > 35) {
            printRecord(&database[i]);
            printf("\n");
        }
    }
    
    return 0;
}