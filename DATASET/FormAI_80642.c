//FormAI DATASET v1.0 Category: Database simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a max limit for number of student records.
#define MAX_STUDENT_RECORDS 50

// Define the student record struct.
typedef struct StudentRecord {
    int id;
    char name[50];
    char address[100];
    float gpa;
} StudentRecord;

// Define a global array of student records and a variable to keep track of the number of records.
StudentRecord studentRecords[MAX_STUDENT_RECORDS];
int numRecords = 0;

// Function to add a new student record to the database.
void addRecord(int id, char* name, char* address, float gpa) {
    // Check if the maximum number of records has been reached.
    if (numRecords >= MAX_STUDENT_RECORDS) {
        printf("Error: Maximum number of student records reached.\n");
        return;
    }
    // Create a new record and add it to the array.
    StudentRecord newRecord = {id, {0}, {0}, gpa};
    strcpy(newRecord.name, name);
    strcpy(newRecord.address, address);
    studentRecords[numRecords++] = newRecord;
}

// Function to find a student record by ID.
StudentRecord* findRecord(int id) {
    for (int i = 0; i < numRecords; i++) {
        if (studentRecords[i].id == id) {
            return &studentRecords[i];
        }
    }
    return NULL;
}

// Function to print all student records in the database.
void printRecords() {
    printf("ID  Name                       Address                                    GPA\n");
    printf("--  ----                       -------                                    ---\n");
    for (int i = 0; i < numRecords; i++) {
        printf("%-3d %-25s %-40s %3.2f\n", studentRecords[i].id, studentRecords[i].name, studentRecords[i].address, studentRecords[i].gpa);
    }
}

int main() {
    // Add some initial student records to the database.
    addRecord(1, "John Smith", "123 Main St., Anytown, USA", 3.5);
    addRecord(2, "Jane Doe", "456 Oak St., Anytown, USA", 3.8);
    addRecord(3, "Bob Johnson", "789 Elm St., Anytown, USA", 4.0);
    
    // Print all student records.
    printf("Initial student records:\n");
    printRecords();
    
    // Find and update a student record.
    printf("Updating record with ID 2...\n");
    StudentRecord* recordToUpdate = findRecord(2);
    if (recordToUpdate != NULL) {
        strcpy(recordToUpdate->address, "321 Maple St., Anytown, USA");
        recordToUpdate->gpa = 3.9;
    }
    else {
        printf("Error: Student record not found.\n");
    }
    
    // Print all student records again.
    printf("Student records after update:\n");
    printRecords();
    
    return 0;
}