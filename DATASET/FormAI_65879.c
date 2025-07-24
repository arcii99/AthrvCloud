//FormAI DATASET v1.0 Category: Database Indexing System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for storing data in the database
typedef struct {
    int id;
    char name[50];
    int age;
    double salary;
} Employee;

// Structure for storing the index of the data in the database
typedef struct {
    int id;
    long offset;
    int size;
} Index;

// Function to add a new employee to the database
void addEmployee(FILE *db, FILE *idx, Employee emp) {

    // Write data to file
    fseek(db, 0, SEEK_END);
    fwrite(&emp, sizeof(Employee), 1, db);

    // Update index
    fseek(idx, 0, SEEK_END);
    Index index;
    index.id = emp.id;
    index.offset = ftell(db) - sizeof(Employee);
    index.size = sizeof(Employee);
    fwrite(&index, sizeof(Index), 1, idx);
}

// Function to search for an employee in the database by ID
void searchEmployeeById(FILE *db, FILE *idx, int id) {

    // Search for employee in index
    Index index;
    fseek(idx, 0, SEEK_SET);
    while(fread(&index, sizeof(Index), 1, idx)) {
        if(index.id == id) {
            // Found employee, read from file and print data
            Employee emp;
            fseek(db, index.offset, SEEK_SET);
            fread(&emp, sizeof(Employee), 1, db);
            printf("ID: %d\nName: %s\nAge:%d\nSalary: $%.2f\n", emp.id, emp.name, emp.age, emp.salary);
            return;
        }
    }

    // Employee was not found
    printf("Employee with ID %d not found.\n", id);
}

int main() {

    // Open files for writing and reading
    FILE *db = fopen("employee_database.bin", "wb+");
    FILE *idx = fopen("employee_index.bin", "wb+");

    // Create some example employees
    Employee emp1 = {1, "John Doe", 30, 50000.0};
    Employee emp2 = {2, "Jane Smith", 35, 60000.0};
    Employee emp3 = {3, "Bob Johnson", 25, 40000.0};

    // Add employees to database
    addEmployee(db, idx, emp1);
    addEmployee(db, idx, emp2);
    addEmployee(db, idx, emp3);

    // Search for an employee by ID
    searchEmployeeById(db, idx, 2);

    // Close files
    fclose(db);
    fclose(idx);

    return 0;
}