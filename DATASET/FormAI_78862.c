//FormAI DATASET v1.0 Category: Database Indexing System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

// struct to represent the data stored in the database
typedef struct {
    int id;
    char name[20];
    char email[50];
    double salary;
} Employee;

// struct to represent the index in the database
typedef struct {
    int id;
    long offset; // byte offset of the data in the file
} Index;

// function to add an index to the database index file
void addIndex(FILE *indexFile, int id, long offset) {
    Index index = {id, offset};
    fwrite(&index, sizeof(Index), 1, indexFile);
}

// function to retrieve an employee from the database given their ID
Employee getEmployeeById(FILE *dataFile, FILE *indexFile, int id) {
    Index index;
    rewind(indexFile);
    while (fread(&index, sizeof(Index), 1, indexFile) == 1) {
        if (index.id == id) {
            fseek(dataFile, index.offset, SEEK_SET);
            Employee employee;
            fread(&employee, sizeof(Employee), 1, dataFile);
            return employee;
        }
    }
    // if no employee with the given ID is found
    Employee nullEmployee = {-1, "", "", 0.0};
    return nullEmployee;
}

int main() {
    // open the data and index files
    FILE *dataFile = fopen("data.bin", "rb");
    FILE *indexFile = fopen("index.bin", "ab+");

    // add some dummy data to the database
    Employee employees[5];
    employees[0] = (Employee) {1, "John Smith", "john.smith@email.com", 50000};
    employees[1] = (Employee) {2, "Jane Doe", "jane.doe@email.com", 60000};
    employees[2] = (Employee) {3, "Bob Johnson", "bob.johnson@email.com", 70000};
    employees[3] = (Employee) {4, "Alice Jones", "alice.jones@email.com", 80000};
    employees[4] = (Employee) {5, "Tom Davis", "tom.davis@email.com", 90000};
    long currentOffset = 0;
    for (int i = 0; i < 5; i++) {
        fwrite(&employees[i], sizeof(Employee), 1, dataFile);
        addIndex(indexFile, employees[i].id, currentOffset);
        currentOffset += sizeof(Employee);
    }

    // retrieve an employee by ID
    Employee employee = getEmployeeById(dataFile, indexFile, 3); // should return Bob Johnson
    printf("Employee ID: %d\n", employee.id);
    printf("Employee Name: %s\n", employee.name);
    printf("Employee Email: %s\n", employee.email);
    printf("Employee Salary: %.2f\n", employee.salary);

    // close the files and exit
    fclose(dataFile);
    fclose(indexFile);
    return 0;
}