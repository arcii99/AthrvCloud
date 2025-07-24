//FormAI DATASET v1.0 Category: Database simulation ; Style: unmistakable
// C Program to simulate a Database using an Array of Structures

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 1000 // Maximum number of records in the database
 
// Structure to represent a single Record in the Database
struct Record {
    int id;
    char name[50];
    int age;
    char gender[10];
};
 
// Database Array to store all the records
struct Record db[MAX_SIZE];
int numRecords = 0; // current number of records in the database
 
// Function to add a new Record to the Database
void addRecord(int id, char *name, int age, char *gender) {
    strcpy(db[numRecords].name, name);
    strcpy(db[numRecords].gender, gender);
    db[numRecords].id = id;
    db[numRecords].age = age;
    numRecords++;
}
 
// Function to display all the records in the Database
void displayAllRecords() {
    printf("\nID\tName\tAge\tGender\n");
    for (int i = 0; i < numRecords; i++) {
        printf("%d\t", db[i].id);
        printf("%s\t", db[i].name);
        printf("%d\t", db[i].age);
        printf("%s\n", db[i].gender);
    }
    printf("\n");
}
 
// Function to search a Record in the Database by ID
int searchRecord(int id) {
    for (int i = 0; i < numRecords; i++) {
        if (db[i].id == id) {
            printf("\nID\tName\tAge\tGender\n");
            printf("%d\t", db[i].id);
            printf("%s\t", db[i].name);
            printf("%d\t", db[i].age);
            printf("%s\n\n", db[i].gender);
            return i;
        }
    }
    printf("Record not found\n\n");
    return -1;
}
 
// Function to update a Record in the Database
void updateRecord(int id) {
    int index = searchRecord(id);
    if (index == -1)
        return;
 
    struct Record r = db[index];
    printf("Enter New Name for ID %d: ", id);
    scanf("%s", r.name);
    printf("Enter New Age for ID %d: ", id);
    scanf("%d", &r.age);
    printf("Enter New Gender for ID %d: ", id);
    scanf("%s", r.gender);
 
    db[index] = r;
    printf("Record with ID %d Updated Successfully!\n\n", id);
}
 
// Function to delete a Record from the Database
void deleteRecord(int id) {
    int index = searchRecord(id);
    if (index == -1)
        return;
 
    // Shift all the records after the deleted record to fill the gap
    for (int i = index; i < numRecords - 1; i++) {
        db[i] = db[i + 1];
    }
    numRecords--;
    printf("Record with ID %d Deleted Successfully!\n\n", id);
}
 
int main() {
    // Adding some initial records to the Database
    addRecord(101, "John", 25, "Male");
    addRecord(102, "Jane", 23, "Female");
    addRecord(103, "Bob", 30, "Male");
 
    int choice, id;
    char name[50], gender[10];
    int age;
 
    // Main Menu
    printf("\nWelcome to the Database Simulation Program\n");
    do {
        printf("\n1. Add new Record");
        printf("\n2. Display all Records");
        printf("\n3. Search for a Record by ID");
        printf("\n4. Update a Record by ID");
        printf("\n5. Delete a Record by ID");
        printf("\n0. Exit");
        printf("\nEnter your choice(0-5): ");
        scanf("%d", &choice);
 
        switch (choice) {
        case 0:
            printf("\nExiting Program...");
            break;
        case 1:
            printf("\nEnter ID, Name, Age and Gender separated by spaces: ");
            scanf("%d %s %d %s", &id, name, &age, gender);
            addRecord(id, name, age, gender);
            printf("Record Added Successfully!\n\n");
            break;
        case 2:
            displayAllRecords();
            break;
        case 3:
            printf("\nEnter ID to search for: ");
            scanf("%d", &id);
            searchRecord(id);
            break;
        case 4:
            printf("\nEnter ID to update: ");
            scanf("%d", &id);
            updateRecord(id);
            break;
        case 5:
            printf("\nEnter ID to delete: ");
            scanf("%d", &id);
            deleteRecord(id);
            break;
        default:
            printf("\nInvalid choice!");
        }
    } while (choice != 0);
 
    return 0;
}